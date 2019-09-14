#include"c1.h"
#include"func7-1.cpp"
#include"func7-2.cpp"
#include"c7-1.h"
#include"bo7-1.cpp"
typedef struct Minside{
 //��¼�Ӷ��㼯U��V-U�Ĵ�����С�ıߵĸ������鶨��
 int adjvex;//���㼯U�е��õ�Ϊ��СȨֵ���Ǹ���������
 VRType lowcost; 
}minside[MAX_VERTEX_NUM];

int minimum(minside SZ,MGraph G)
{//��SZ.lowcost����Сֵ������������SZ�е����
    int i=0,j,k,min;
    while(!SZ[i].lowcost)
	   i++;
	min=SZ[i].lowcost;
	k=i;
	for(j=i+1;j<G.vexnum;j++)
	  if(SZ[j].lowcost>0&&SZ[j].lowcost<min)
	  {
	  	min=SZ[j].lowcost;//min��Ǵ���ֵ
		k=j; 
	   } 
	return k;
}

void MiniSpanTree_PRIM(MGraph G,VertexType u)
{//������ķ�㷨�Ӷ���u����������G����С������T�����T�ĸ�����
  int i,j,k;
  minside closedge;
  k=LocateVex(G,u);
  for(j=0;j<G.vexnum;++j)
  {
  	closedge[j].adjvex=k;
  	closedge[j].lowcost=G.arcs[k][j].adj;//����u���õ��Ȩֵ 
   } 
  closedge[k].lowcost=0;
  printf("��С�����������ĸ�����Ϊ\n");
  for(i=1;i<G.vexnum;++i)
  {
  	k=minimum(closedge,G);
  	printf("(%s-%s)\n",G.vexs[closedge[k].adjvex].name,G.vexs[k].name);
  	//�����С������T�ı�
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
	printf("�����������ļ���:");
	scanf("%s",filename);
	CreateFromFile(g,filename,0);
	Display(g);
	MiniSpanTree_PRIM(g,g.vexs[0]);
	
}
