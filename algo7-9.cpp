#include"c1.h"
#include"func7-1.cpp"
#include"func7-2.cpp"
#include"c7-1.h"
#include"bo7-1.cpp"
typedef Status PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef VRType ShortPathTable[MAX_VERTEX_NUM];
void ShortestPath_DIJ(MGraph G,int v0,PathMatrix P,ShortPathTable D)
{//��Dijkstras�㷨��������G��v0���㵽���ඥ��v�����·��P[v]����Ȩ����D[v]
//��P[v][w]ΪTRUE����w�Ǵ�v0��v��ǰ������·���ϵĶ���
//final[v]ΪTRUE���ҽ���v��S�����Ѿ���ô�v0��v�����·��
  int v,w,i,j;
  VRType min;
  Status final[MAX_VERTEX_NUM];
  //��������Ϊ���ʾ�ö��㵽v0����̾������������ֵΪ�� 
  for(v=0;v<G.vexnum;++v)
  {
  	final[v]=FALSE;
  	D[v]=G.arcs[v0][v].adj;
  	for(w=0;w<G.vexnum;++w)
  	  P[v][w]=FALSE;
  	if(D[v]<INFINITY)
  	  P[v][v0]=P[v][v]=TRUE;
  }
  D[v0]=0;
  final[v0]=TRUE;
  for(i=1;i<G.vexnum;++i)
  {//��ʼ��ѭ����ÿ�����v0��ĳ������v�����·��������v����S��
    min=INFINITY;
	for(w=0;w<G.vexnum;++w)
	  if(!final[w]&&D[w]<min)
	  {//����v0����Ķ���w�������丳��v�����븳��min
	    v=w;//��S��֮�����v0����Ķ������ 
		min=D[w]; 
	   } 
	final[v]=TRUE;
	for(w=0;w<G.vexnum;++w)//�����²���Ķ��㣬���²���S���Ķ��㵽v0�ľ����·������
	  if(!final[w]&&min<INFINITY&&G.arcs[v][w].adj<INFINITY&&(min+G.arcs[v][w].adj<D[w]))
	  {//w������S����v0->v->w�ľ���<Ŀǰv0->w�ľ���
	   D[w]=min+G.arcs[v][w].adj;
	   for(j=0;j<G.vexnum;++j)
	   //�޸�P[w],v0��w�����Ķ������v0��v�����Ķ����ټ��϶���w
	     P[w][j]=P[v][j];
	   P[w][w]=TRUE; 
	   } 
  }
}

int main()
{
	int i,j;
	MGraph g;
	PathMatrix p;
	ShortPathTable d;
	CreateDN(g);
	Display(g);
	ShortestPath_DIJ(g,0,p,d);
	//��g�����Ϊ0�Ķ���ΪԴ�㣬���䵽������������̾��롣����d��
	printf("���·������p[i][j]����:\n");
	for(i=0;i<g.vexnum;++i)
	{for(j=0;j<g.vexnum;++j)
	   printf("%2d",p[i][j]);
	 printf("\n");
	 } 
	printf("%s������������·������Ϊ\n",g.vexs[0].name);
	for(i=0;i<g.vexnum;++i)
	  if(i!=0)
	    printf("%s->%s:%d\n",g.vexs[0].name,g.vexs[i].name,d[i]);
}
