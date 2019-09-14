#include"c1.h"
#include"func7-1.cpp"
#include"func7-4.cpp"
#include"c7-2'.h"
#include"bo7-2.cpp"
#include"func7-5.cpp"
typedef int SElemType;
#include"c3-1.h"
#include"bo3-1.cpp"
Status TopologicalSort(ALGraph G)
{//有向图G采用邻接表存储结构。若G无回路，则输出G的顶点的一个拓扑序列并返回OK
   int i,k,count=0;
   int indegree[MAX_VERTEX_NUM];
   SqStack S;
   ArcNode *p;
   FindInDegree(G,indegree);
   InitStack(S);
   for(i=0;i<G.vexnum;++i)
     if(!indegree[i])
	   Push(S,i);
   while(!StackEmpty(S))
   {
   	Pop(S,i);
   	printf("%s",G.vertices[i].data.name);
	++count;
	for(p=G.vertices[i].firstarc;p;p=p->nextarc)
	{
		k=p->data.adjvex;
		if(!(--indegree[k]))//k的入度减1，若减为0，则将k入栈S
		  Push(S,k); 
	 } 
	} 
	if(count<G.vexnum)
	{
		printf("此有向图有回路\n");
		return ERROR;
	}
	else
	{
		printf("为一个拓扑序列。\n");
		return OK;
	}
}

int main()
{
	ALGraph f;
	printf("请选择有向图\n");
	CreateGraph(f);
	Display(f);
	TopologicalSort(f);
}
