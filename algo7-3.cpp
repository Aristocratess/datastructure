#include"c1.h"
#include"func7-1.cpp"
#include"func7-4.cpp"
typedef VertexType TElemType;
#include"c6-4.h"
#include"bo6-6.cpp"
#include"c7-2'.h"
Boolean visited[MAX_VERTEX_NUM];
#include"bo7-2.cpp"
typedef ALGraph Graph;
void DFSTree(Graph G,int v,CSTree &T)
{//从第v个顶点出发深度优先遍历图G，建立以T为根的生成树
  Boolean first=TRUE;
  int w;
  CSTree p,q;
  visited[v]=TRUE;
  for(w=FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,w))
    if(!visited[w])
	{
		p=(CSTree)malloc(sizeof(CSNode));
		p->data=GetVex(G,w);
		p->firstchild=NULL;
		p->nextsibling=NULL;
		if(first)
		{
			T->firstchild=p;
			first=FALSE;
		}
		else
		  q->nextsibling=p;
		
		q=p;
		DFSTree(G,w,q);
	 } 
}

void DFSForest(Graph G,CSTree &T)
{//建立无向图G的深度优先生成森林的(最左)孩子(下一个)兄弟链表T
  CSTree p,q;
  int v;
  T=NULL;
  for(v=0;v<G.vexnum;++v) 
    visited[v]=FALSE;
  for(v=0;v<G.vexnum;++v)
    if(!visited[v])
    {//第v个顶点为新的生成树的根结点
	 p=(CSTree)malloc(sizeof(CSNode));
	 p->data=GetVex(G,v);
	 p->firstchild=NULL;
	 p->nextsibling=NULL;
	 if(!T)
	   T=p;
	 else
	   q->nextsibling=p;
	 q=p;
	 DFSTree(G,v,p); 
	}
}

int main()
{
	Graph g;
	CSTree t;
	printf("请选择无向图\n");
	CreateGraph(g);
	Display(g);
	DFSForest(g,t);
	printf("先序遍历生成森林:\n");
	PreOrderTraverse(t,Visit);
	printf("\n");
}
