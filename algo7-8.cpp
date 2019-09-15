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
{//有向网G采用邻接表存储结构，求各顶点事件的最早发生时间ve(存储在G中)
//T为拓扑序列顶点栈，S为零入度顶点栈。若G无回路，则用栈T返回G的有个拓扑序列，且函数值为OK
   int i,k,count=0;
   int indegree[MAX_VERTEX_NUM];
   SqStack S;
   ArcNode *p;
   FindInDegree(G,indegree);
   InitStack(S);
   printf("拓扑序列:");
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
   	{//对i号顶点的每个邻接顶点
	   k=p->data.adjvex;
	   if(--indegree[k]==0)
	     Push(S,k);
	   if(G.vertices[i].data.ve+p->data.info->weight>G.vertices[k].data.ve) 
	   //顶点i事件的最早发生时间+<i,k>的权值>顶点k事件的最早发生时间
	     G.vertices[k].data.ve=G.vertices[i].data.ve+p->data.info->weight; 
	   //顶点k事件的最早发生时间=顶点i事件的最早发生时间+<i,k>的权值 
	   }//由于i已拓扑有序，故G.vertices[i].data.ve不再改变 
	} 
	if(count<G.vexnum)
	{
		printf("此有向网有回路\n");
		return ERROR;
	 } 
	else
	  return OK;
 } 
 
Status CriticalPath(ALGraph &G)
{//G为有向网，输出G的各项关键活动
  SqStack T;
  int i,j,k;
  ArcNode *p;
  if(!TopologicalOrder(G,T))
    return ERROR;
  j=G.vertices[0].data.ve;//j的初值
  for(i=1;i<G.vexnum;i++)
    if(G.vertices[i].data.ve>j)
	  j=G.vertices[i].data.ve;
  for(i=0;i<G.vexnum;i++)
    G.vertices[i].data.vl=j;
  while(!StackEmpty(T))
    for(Pop(T,j),p=G.vertices[j].firstarc;p;p=p->nextarc)
	{//弹出栈T的元素，赋给j，p指向顶点j的后继事件(出弧)顶点k
	//事件k的最迟发生时间已确定
	 k=p->data.adjvex;
	 if(G.vertices[k].data.vl-p->data.info->weight<G.vertices[j].data.vl)
	 //事件j的最迟发生时间>其直接后继事件k的最迟发生时间-<j,k>的权值
	   G.vertices[j].data.vl=G.vertices[k].data.vl-p->data.info->weight;
	   //事件j的最迟发生时间=事件k的最迟发生时间-<j,k>的权值 
	 } //由于k已逆拓扑有序，故G.vertices[k].data.vl不再改变
   printf("\ni ve vl\n");
   for(i=0;i<G.vexnum;i++)
   {
   	printf("%d",i);
   	Visitel(G.vertices[i].data);
   	 if(G.vertices[i].data.ve==G.vertices[i].data.vl)
   	 //事件(顶点）的最早发生时间=最迟发生时间
	   printf("关键路径经过的顶点");
	 printf("\n"); 
	} 
	printf("j  k 权值 ee  el\n");
	for(j=0;j<G.vexnum;++j)
	  for(p=G.vertices[j].firstarc;p;p=p->nextarc)
	  {//p依次指向其邻接顶点
	   k=p->data.adjvex;
	   p->data.info->ee=G.vertices[j].data.ve;
	   //ee(活动<j,k>的最早开始时间)=(顶点j)事件最早发生时间
	   p->data.info->el=G.vertices[k].data.vl-p->data.info->weight;
	   //el(活动<i,k>的最迟开始时间)=(顶点k)事件最迟发生时间-<j,k>的权值
	   printf("%s->%s",G.vertices[j].data.name,G.vertices[k].data.name);
	   OutputArcwel(p->data.info);
	   if(p->data.info->ee==p->data.info->el)
	   //活动(弧)的最早开始时间=活动的最迟开始时间
	     printf("关键活动");
	   printf("\n"); 
	  }
	return OK;
}

int main()
{
	ALGraph h;
	printf("请选择有向网\n");
	CreateGraph(h);
	Display(h);
	CriticalPath(h);//求h的关键路径 
}
