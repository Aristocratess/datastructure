Boolean visite[MAX_VERTEX_NUM];
void (*VisitFunc)(VertexType);
void DFS(Graph G,int v)
{//从第v个顶点出发递归地深度优先遍历图G
  int w;
  visite[v]=TRUE;
  VisitFunc(GetVex(G,v));
  for(w=FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,w));
    if(!visite[w])
	  DFS(G,w); 
}

void DFSTraverse(Graph G,void(*Visit)(VertexType))
{//初始条件：图G存在，Visit是顶点的应用函数
//操作结果：从第1个顶点起，深度优先遍历图G，并对每个每个顶点调用函数Visit一次且仅一次
  int v;
  VisitFunc=Visit;
  for(v=0;v<G.vexnum;v++)
     visite[v]=FALSE;
  for(v=0;v<G.vexnum;v++)
     if(!visite[v])
	   DFS(G,v);
  printf("\n"); 
}

typedef int QElemType;
#include"c3-2.h"
#include"bo3-2.cpp"
void BFSTraverse(Graph G,void(*Visit)(VertexType))
{//初始条件：图G存在，Visit是顶点的应用函数
//操作结果：从第1个顶点起，按广度优先非递归遍历图G，并对每个顶点调用函数Visit一次且仅一次
  int v,u,w;
  LinkQueue Q;
  for(v=0;v<G.vexnum;v++)
    visite[v]=FALSE;
  InitQueue(Q);
  for(v=0;v<G.vexnum;v++)
    if(!visite[v])
	{
		visite[v]=TRUE;
		Visit(GetVex(G,v));
		EnQueue(Q,v);
		while(!QueueEmpty(Q)){
			DeQueue(Q,u);
			for(w=FirstAdjVex(G,u);w>=0;w=NextAdjVex(G,u,w))
			  if(!visite[w])
			  {
			  	visite[w]=TRUE;
			  	Visit(GetVex(G,w));
			  	EnQueue(Q,w);
			  }
		}
  printf("\n");
} 


}
