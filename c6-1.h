#define MAX_TYPE_SIZE 100//二叉树的最大结点数
typedef TElemType SqBiTree[MAX_TREE_SIZE];//0号单元存储根结点
struct position
{ 
  int level,order;//结点所在的层，在该层的序号(按满二叉树计算) 
 } ;

