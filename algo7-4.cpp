#include"c1.h"
#include"func7-1.cpp"
#include"func7-2.cpp"
#include"c7-1.h"
#include"bo7-1.cpp"
typedef struct Minside{
 //记录从顶点集U到V-U的代价最小的边的辅助数组定义
 int adjvex;//顶点集U中到该点为最小权值的那个顶点的序号
 VRType lowcost; 
}minside[MAX_VERTEX_NUM];

int minimum(minside SZ,MGraph G)
{//求SZ.lowcost的最小值，并返回其在SZ中的序号
    int i=0,j,k,min;
    while(!SZ[i].lowcost)
	   i++;
	min=SZ[i].lowcost;
	k=i;
	for(j=i+1;j<G.vexnum;j++)
	  if(SZ[j].lowcost>0&&SZ[j].lowcost<min)
	  {
	  	min=SZ[j].lowcost;//min标记此正值
		k=j; 
	   } 
	return k;
}

void MiniSpanTree_PRIM(MGraph G,VertexType u)
{//用普里姆算法从顶点u出发构造网G的最小生成树T，输出T的各条边
  int i,j,k;
  minside closedge;
  k=LocateVex(G,u);
  for(j=0;j<G.vexnum;++j)
  {
  	closedge[j].adjvex=k;
  	closedge[j].lowcost=G.arcs[k][j].adj;//顶点u到该点的权值 
   } 
  closedge[k].lowcost=0;
  printf("最小代价生成树的各条边为\n");
  for(i=1;i<G.vexnum;++i)
  {
  	k=minimum(closedge,G);
  	printf("(%s-%s)\n",G.vexs[closedge[k].adjvex].name,G.vexs[k].name);
  	//输出最小生成树T的边
	closedge[k].lowcost=0;
	for(j=0;j<G.vexnum;++j)
	  if(G.arcs[k][j].adj<closedge[j].lowcost)
	  {
	  	closedge[j].adjvex=k;
	  	closedge[j].lowcost=G.arcs[k][j].adj;
	   } 
   } 
}

int main()
{
	MGraph g;
	char filename[13];
	printf("请输入数据文件名:");
	scanf("%s",filename);
	CreateFromFile(g,filename,0);
	Display(g);
	MiniSpanTree_PRIM(g,g.vexs[0]);
	
}
