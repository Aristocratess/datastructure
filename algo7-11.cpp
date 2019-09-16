#include"c1.h"
#include"func7-1.cpp"
#include"func7-2.cpp"
#include"c7-1.h"
#include"bo7-1.cpp"
typedef char PathMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef VRType DistancMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
#include"func7-8.cpp"
void path(MGraph G,PathMatrix P,int i,int j)
{//求由序号为i的起点城市到序号为j的终点城市最短路径沿途所经过的城市 
  int k,m=i;
  printf("依次经过的城市:\n");
    while(m!=j)
	{
		G.arcs[m][m].adj<INFINITY;
		for(k=0;k<G.vexnum;k++)
		  if(G.arcs[m][k].adj<INFINITY&&P[m][j][k])
		  {
		  	printf("%s",G.vexs[m].name);
		  	G.arcs[m][k].adj=G.arcs[k][m].adj=INFINITY;
		  	m=k;
		  	break;
		  }
	 } 
	printf("%s\n",G.vexs[j].name);
}

int main()
{
	MGraph g;
	int i,j,k,q=1;
	PathMatrix p;
	DistancMatrix d;
	char filename[8]="map.txt";
	CreateFromFile(g,filename,0);
	for(i=0;i<G.vexnum;i++)
	   g.arcs[i][j].adj=0;
	ShortestPath_FLOYD(g,p,d);
	while(p)
	{
		printf("请选择:1 查询  0 结束\n");
		if(q)
		{
			printf("城市代码:\n");
			for(i=0;i<G.vexnum;i++)
			{
				printf("%2d.% -8s",i+1,g.vexs[i].name);
				if(i%7==6)
				  printf("\n");
			}
			printf("\n请输入要查询的起点城市代码 终点城市代码：");
			scanf("%d %d",&i,&j);
			if(d[i-1][j-1]<INFINITY)
			{
				printf("%s到%s的最短距离为%d\n",g.vexs[i-1].name,g.vexs[j-1].name,d[i-1][j-1]);
				path(g,p,i-1,j-1);
			 } 
		    else
		      printf("%s到%s没有路径可通\n",g.vexs[i-1].name,g.vexs[j-1].name);
		    printf("与%s到%s有关的p矩阵:\n",g.vexs[i-1].name,g.vexs[j-1].name);
		    for(k=0;k<g.vexnum;k++)
		      printf("%2d",p[i-1][j-1][k]);
		    printf("\n");
		}
	}
}
