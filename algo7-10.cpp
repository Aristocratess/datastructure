#include"c1.h"
#include"func7-1.cpp"
#include"func7-2.cpp"
#include"c7-1.h"
#include"bo7-1.cpp"
typedef char PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef VRType DistancMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
#include"func7-8.cpp"
int main()
{
	MGraph g;
	int i,j,k;
	PathMatrix p;
	CreateDN(g);
	for(i=0;i<G.vexnum;i++)
	  g.arcs[i][i].adj=0;
	Display(g);
	ShortestPath_FLOYD(g,p,d);
	printf("d矩阵:\n");
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<g.vexnum;j++)
		  printf("%6d",d[i][j]);
		printf("\n");
	 } 
	printf("p矩阵:\n");
	for(i=0;i<G.vexnum;i++)
	  for(j=0;j<g.vexnum;j++)
	    if(i!=j)
	    {
	    	printf("有%s到%s经过：",g.vexs[i].name,g.vexs[j].name);
	    	for(k=0;k<g.vexnum;k++)
	    	  if(p[i][j][k]==1)
	    	    printf("%s",g.vexs[k].name);
	    	printf("\n");
		}
}
