#define MAX_VERTEX_NUM 20//��󶥵���
enum GraphKind{DG,DN,UDG,UDN
}; 
struct ArcNode{
	int adjvex;//�û���ָ��Ķ����λ��(��ţ�
	InfoType *info;//�û������Ϣ��ָ�� 
	ArcNode *nextarc;//ָ����һ������ָ�� 
};
typedef struct{
	VertexType data;
	ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];
struct ALGraph
{
	AdjList vertices;//ͷ���(����)����
	int vexnum,arcnum;
	GraphKind kind; 
 } ;
 
