#define MAX_VERTEX_NUM 20//最大顶点数
enum GraphKind{DG,DN,UDG,UDN
}; 
struct ArcNode{
	int adjvex;//该弧所指向的顶点的位置(序号）
	InfoType *info;//该弧相关信息的指针 
	ArcNode *nextarc;//指向下一条弧的指针 
};
typedef struct{
	VertexType data;
	ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];
struct ALGraph
{
	AdjList vertices;//头结点(顶点)数组
	int vexnum,arcnum;
	GraphKind kind; 
 } ;
 
