enum PointerTag{
	Link,Thread
}; 
struct BiThrNode
{
	TElemType data;
	BiThrNode *lchild,*rchild;
	PointerTag LTag:2;//���־
	PointerTag RTag:2;//�ұ�־ 
};
typedef BiThrNode *BiThrTree;
