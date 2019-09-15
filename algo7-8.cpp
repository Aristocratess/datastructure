#include"c1.h"
#include"func7-6.cpp"
#include"func7-7.cpp"
#include"c7-2'.h"
#include"bo7-2.cpp"
#include"func7-5.cpp"
typedef int SElemType;
#include"c3-1.h"
#include"bo3-1.cpp"
Status TopologicalOrder(ALGraph &G,SqStack &T)
{//������G�����ڽӱ�洢�ṹ����������¼������緢��ʱ��ve(�洢��G��)
//TΪ�������ж���ջ��SΪ����ȶ���ջ����G�޻�·������ջT����G���и��������У��Һ���ֵΪOK
   int i,k,count=0;
   int indegree[MAX_VERTEX_NUM];
   SqStack S;
   ArcNode *p;
   FindInDegree(G,indegree);
   InitStack(S);
   printf("��������:");
   for(i=0;i<G.vexnum;++i)
     if(!indegree[i])
	   Push(S,i);
   InitStack(T);
   for(i=0;i<G.vexnum;++i)
     G.vertices[i].data.ve=0;
   while(!StackEmpty(S))
   {
   	Pop(S,i);
   	Visit(G.vertices[i].data);
   	Push(T,i);
   	++count;
   	for(p=G.vertices[i].firstarc;p;p=p->nextarc)
   	{//��i�Ŷ����ÿ���ڽӶ���
	   k=p->data.adjvex;
	   if(--indegree[k]==0)
	     Push(S,k);
	   if(G.vertices[i].data.ve+p->data.info->weight>G.vertices[k].data.ve) 
	   //����i�¼������緢��ʱ��+<i,k>��Ȩֵ>����k�¼������緢��ʱ��
	     G.vertices[k].data.ve=G.vertices[i].data.ve+p->data.info->weight; 
	   //����k�¼������緢��ʱ��=����i�¼������緢��ʱ��+<i,k>��Ȩֵ 
	   }//����i���������򣬹�G.vertices[i].data.ve���ٸı� 
	} 
	if(count<G.vexnum)
	{
		printf("���������л�·\n");
		return ERROR;
	 } 
	else
	  return OK;
 } 
 
Status CriticalPath(ALGraph &G)
{//GΪ�����������G�ĸ���ؼ��
  SqStack T;
  int i,j,k;
  ArcNode *p;
  if(!TopologicalOrder(G,T))
    return ERROR;
  j=G.vertices[0].data.ve;//j�ĳ�ֵ
  for(i=1;i<G.vexnum;i++)
    if(G.vertices[i].data.ve>j)
	  j=G.vertices[i].data.ve;
  for(i=0;i<G.vexnum;i++)
    G.vertices[i].data.vl=j;
  while(!StackEmpty(T))
    for(Pop(T,j),p=G.vertices[j].firstarc;p;p=p->nextarc)
	{//����ջT��Ԫ�أ�����j��pָ�򶥵�j�ĺ���¼�(����)����k
	//�¼�k����ٷ���ʱ����ȷ��
	 k=p->data.adjvex;
	 if(G.vertices[k].data.vl-p->data.info->weight<G.vertices[j].data.vl)
	 //�¼�j����ٷ���ʱ��>��ֱ�Ӻ���¼�k����ٷ���ʱ��-<j,k>��Ȩֵ
	   G.vertices[j].data.vl=G.vertices[k].data.vl-p->data.info->weight;
	   //�¼�j����ٷ���ʱ��=�¼�k����ٷ���ʱ��-<j,k>��Ȩֵ 
	 } //����k�����������򣬹�G.vertices[k].data.vl���ٸı�
   printf("\ni ve vl\n");
   for(i=0;i<G.vexnum;i++)
   {
   	printf("%d",i);
   	Visitel(G.vertices[i].data);
   	 if(G.vertices[i].data.ve==G.vertices[i].data.vl)
   	 //�¼�(���㣩�����緢��ʱ��=��ٷ���ʱ��
	   printf("�ؼ�·�������Ķ���");
	 printf("\n"); 
	} 
	printf("j  k Ȩֵ ee  el\n");
	for(j=0;j<G.vexnum;++j)
	  for(p=G.vertices[j].firstarc;p;p=p->nextarc)
	  {//p����ָ�����ڽӶ���
	   k=p->data.adjvex;
	   p->data.info->ee=G.vertices[j].data.ve;
	   //ee(�<j,k>�����翪ʼʱ��)=(����j)�¼����緢��ʱ��
	   p->data.info->el=G.vertices[k].data.vl-p->data.info->weight;
	   //el(�<i,k>����ٿ�ʼʱ��)=(����k)�¼���ٷ���ʱ��-<j,k>��Ȩֵ
	   printf("%s->%s",G.vertices[j].data.name,G.vertices[k].data.name);
	   OutputArcwel(p->data.info);
	   if(p->data.info->ee==p->data.info->el)
	   //�(��)�����翪ʼʱ��=�����ٿ�ʼʱ��
	     printf("�ؼ��");
	   printf("\n"); 
	  }
	return OK;
}

int main()
{
	ALGraph h;
	printf("��ѡ��������\n");
	CreateGraph(h);
	Display(h);
	CriticalPath(h);//��h�Ĺؼ�·�� 
}
