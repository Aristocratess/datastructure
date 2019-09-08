#define ClearBiTree DestroyBiTree
void InitBiTree(BiTree &T)
{//操作结果：构造空二叉树T
  T=NULL; 
}

void DestroyBiTree(BiTree &T)
{//初始条件：二叉树T存在。  操作结果：销毁二叉树T
  if(T)
  {
  	DestroyBiTree(T->lchild);
    DestroyBiTree(T->rchild);
	free(T);
	T=NULL; 
   } 
}

void PreOrderTraverse(BiTree T,void(*Visit)(TElemType))
{//初始条件：二叉树T存在，Visit是对结点操作的应用函数。
//操作结果：先序递归遍历T，对每个结点调用函数Visit一次且仅一次
if(T)
  {
  	Visit(T->data);
  	PreOrderTraverse(T->lchild,Visit);
  	PreOrderTraverse(T->rchild,Visit);
   } 
}

void InOrderTraverse(BiTree T,void(*Visit)(TElemType))
{//初始条件：二叉树T存在，Visit是对节点操作的应用函数
//操作结果：中序递归遍历T，对每个结点调用函数Visit一次且仅一次
  if(T)
  {
  	InOrderTraverse(T->lchild,Visit);
  	Visit(T->data);
  	InOrderTraverse(T->rchild,Visit);
   } 
}
