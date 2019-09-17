#include"bo6-2.cpp"
#define InitDSTable InitBiTree
#define DestroyDSTable DestroyBiTree
#define TraverseDSTable InOrderTraverse
//按关键字顺序遍历二叉排序树和平衡二叉树与中序遍历二叉树的操作同
BiTree SearchBST(BiTree T,KeyType key)
{//在根指针T所指二叉排序树或平衡二叉树中递归地查找某关键字等于key的数据元素
//若查找成功，则返回指向该数据元素结点的指针，否则返回空指针 
	if(!T||EQ(key,T->data.key))
	   return T;
	else if LT(key,T->data.key)
	   return SearchBST(T->lchild,key);
	else
	   return SearchBST(T->rchild,key);
}
