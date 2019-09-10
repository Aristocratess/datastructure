enum PointerTag{
	Link,Thread
}; 
struct BiThrNode
{
	TElemType data;
	BiThrNode *lchild,*rchild;
	PointerTag LTag:2;//左标志
	PointerTag RTag:2;//右标志 
};
typedef BiThrNode *BiThrTree;
