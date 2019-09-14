#include"c1.h"
#include"func7-1.cpp"
#include"func7-4.cpp"
#include"c7-2'.h"
#include"bo7-2.cpp"
int count,lowcount=1;
int low[MAX_VERTEX_NUM],lowOrder[MAX_VERTEX_NUM];
//全局数组，low[]存顶点的low值，lowOrder存顶点求得low值的顺序
int visited[MAX_VERTEX_NUM];
void DFSArticul(ALGraph G,int v0)
{//从第v0各顶点出发深度优先遍历图G，查找并输出关节点
  int min,w;
  ArcNode *p;
  visited[v0]=min=++count;
  for(p=G.vertices[v0].firstarc;p;p=p->nextarc)
  {
  	w=p->data.adjvex;
  	if(visited[w]==0)
  	{
  		DFSArticul(G,w);
  		//从第w个顶点出发深度优先遍历图G，查找并输出关节点。返回前求得low[w] 
  		if(low[w]<min)
  		  min=low[w];
  		else if(low[w]>=visited[v0])//v0的孩子结点w只与v0相连，则v0是关节点
		  printf("%d %s\n",v0,G.vertices[v0].data.name); 
	  }
	else if(visited[w]<min)//w已访问，则w是v0在生成树上的祖先，它的访问顺序必小于min
	  min=visited[w]; 
   } 
   low[v0]=min;//v0的low[]值为三者中的最小值
   lowOrder[v0]=lowcount++;
   //记录v0求得low[]值的顺序，总是在返回主调函数之前求得low[] 
 } 
 
void FindArticul(ALGraph G)
{//连通图G以邻接表作存储结构，查找并输出G上全部关节点。全局量count对访问计数。
  int i,v;
  ArcNode *p;
  count=1;
  visited[0]=count;
  for(i=1;i<G.vexnum;++i)
    visited[i]=0;
  p=G.vertices[0].firstarc;
  v=p->data.adjvex;
  DFSArticul(G,v);
  if(count<G.vexnum)
  {//说明生成树的根有至少两棵子树，则根是关节点
    printf("%d %s\n",0,G.vertices[0].data.name);//根是关节点，输出根
		while(p->nextarc)
		{
			p=p->nextarc;
			v=p->data.adjvex;
			if(visited[v]==0)
			  DFSArticul(G,v);
		}
   } 
 } 
 
int main()
{
	int i;
	ALGraph g;
	char filename[13];
	printf("请输入数据文件名:");
	scanf("%s",filename);
	CreateFromFile(g,filename);
	Display(g);
	printf("输出关节点：\n");
	FindArticul(g);
	printf("i G.vertices[i].data visited[i] low[i] lowOrder[i]\n");
	for(i=0;i<g.vexnum;++i)
	  printf("%2d %9r[i] s %14d %8d %8d\n",i,g.vertices[i].data.name,visited[i],low[i],lowOrder[i]);
}
