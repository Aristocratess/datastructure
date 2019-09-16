#include"c1.h"
#include"func7-1.cpp"
#include"func7-2.cpp"
#include"c7-1.h"
#include"bo7-1.cpp"
typedef Status PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef VRType ShortPathTable[MAX_VERTEX_NUM];
void ShortestPath_DIJ(MGraph G,int v0,PathMatrix P,ShortPathTable D)
{//用Dijkstras算法求有向网G的v0顶点到其余顶点v的最短路径P[v]及带权长度D[v]
//若P[v][w]为TRUE，则w是从v0到v当前求得最短路径上的顶点
//final[v]为TRUE当且仅当v∈S，即已经求得从v0到v的最短路径
  int v,w,i,j;
  VRType min;
  Status final[MAX_VERTEX_NUM];
  //辅助矩阵，为真表示该顶点到v0的最短距离已求出，初值为假 
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
  {//开始主循环，每次求得v0到某个顶点v的最短路径，并将v并入S集
    min=INFINITY;
	for(w=0;w<G.vexnum;++w)
	  if(!final[w]&&D[w]<min)
	  {//找离v0最近的顶点w，并将其赋给v，距离赋给min
	    v=w;//在S集之外的离v0最近的顶点序号 
		min=D[w]; 
	   } 
	final[v]=TRUE;
	for(w=0;w<G.vexnum;++w)//根据新并入的顶点，更新不在S集的顶点到v0的距离和路径数组
	  if(!final[w]&&min<INFINITY&&G.arcs[v][w].adj<INFINITY&&(min+G.arcs[v][w].adj<D[w]))
	  {//w不属于S集且v0->v->w的距离<目前v0->w的距离
	   D[w]=min+G.arcs[v][w].adj;
	   for(j=0;j<G.vexnum;++j)
	   //修改P[w],v0到w经过的顶点包括v0到v经过的顶点再加上顶点w
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
	//以g中序号为0的顶点为源点，求其到其余各顶点的最短距离。存于d中
	printf("最短路径数组p[i][j]如下:\n");
	for(i=0;i<g.vexnum;++i)
	{for(j=0;j<g.vexnum;++j)
	   printf("%2d",p[i][j]);
	 printf("\n");
	 } 
	printf("%s到各顶点的最短路径长度为\n",g.vexs[0].name);
	for(i=0;i<g.vexnum;++i)
	  if(i!=0)
	    printf("%s->%s:%d\n",g.vexs[0].name,g.vexs[i].name,d[i]);
}
