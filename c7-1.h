#define INFINITY INT_MAX//���������ֵ�����
typedef int VRType;//���嶥���ϵ����Ϊ���ͣ���INFINITY������һ�� 
#define MAX_VERTEX_NUM 26//��󶥵����
enum GraphKind{DG,DN,UDG,UDN
}; 
typedef struct{
	VRType adj;//�����ϵ���͡�����Ȩͼ����1(��)��0(��)��ʾ���ڷ񣬶Դ�Ȩͼ����ΪȨֵ
	InfoType *info;//�û������Ϣ��ָ�루���ޣ� 
}ArcCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
struct MGraph{
	VertexType vexs[MAX_VERTEX_NUM];//��������
	AdjMatrix arcs;//�ڽӾ���
	int vexnum,arcnum;//ͼ�ĵ�ǰ�������ͻ���
	GraphKind kind;//ͼ�������־ 
}; 
 
