Status BiTreeEmpty(BiTree T)
{//初始条件：二叉树T存在。 操作结果：若T为空二叉树，则返回为TRUE
   if(T)
     return FALSE;
   else
     return TRUE; 
}

int BiTreeDepth(BiTree T)
{//初始条件：二叉树T存在。  操作结果：返回T的深度
  int i,j;
  if(!T)
    return 0; 
  i=BiTreeDepth(T->lchild);
  j=BiTreeDepth(T->rchild);
  return i>j?i+1:j+1; 
}

TElemType Root(BiTree T)
{//初始条件：二叉树T存在。 操作结果：返回T的根
  if(BiTreeEmpty(T))
    return Nil;
  else
    return T->data; 
}

TElemType Value(BiTree p)
{//初始条件：二叉树T存在，p指向T中某个结点。操作结果：返回p所指结点的值
  return p->data; 
}

void Assign(BiTree p,TElemType value)
{//给p所指结点赋值为value
  p->data=value; 
}

typedef BiTree QElemType;
#include"c3-2.h"
#include"bo3-2.cpp"
BiTree Point(BiTree T,TElemType s)
{//返回二叉树T中指向元素值为s的结点的指针
  LinkQueue q;
  QElemType a;
  if(T)
  {
  	InitQueue(q);
  	EnQueue(q,T);
  	while(!QueueEmpty(q))
  	{
  		DeQueue(q,a);
  		if(a->data==s)
  		  return a;
  		if(a->lchild)
  		  EnQueue(q,a->lchild);
  	    if(a->rchild)
  	      EnQueue(q,a->rchild);
	  }
   } 
   return NULL;
}

TElemType LeftChild(BiTree T,TElemType e)
{//初始条件：二叉树T存在，e是T中某个结点
//操作结果：返回e的左孩子。若e无左孩子，则返回"空"
  BiTree a;
  if(T)
  {
  	a=Point(T,e);
  	if(a&&a->lchild)//T中存在结点e且e存在右孩子 
  	  return a->lchild->data;
   } 
  return Nil; 
}

TElemType RightChild(BiTree T,TElemType e)
{//初始条件:二叉树T存在，e是T中某个结点
//操作结果:返回e的右孩子。若e无右孩子，则返回空。
  BiTree a;
  if(T)
  {
  	a=Point(T,e);
  	if(a&&a->rchild)//T中存在结点e且e存在右孩子 
  	   return a->rchild->data;
   } 
   return Nil; 
}
Status DeleteChild(BiTree p,int LR)
{//初始条件：二叉树T存在，p指向T中某个结点，LR为0或1
//操作结果：根据LR为0或1，删除T中p所指结点的左或右子树
  if(p)
  {
  	if(LR==0)
  	  ClearBiTree(p->lchild);
  	else
  	  ClearBiTree(p->rchild);
  return OK;
  }
  return ERROR;
}

void PostOrderTraverse(BiTree T,void(*Visit)(TElemType))
{//初始条件：二叉树T存在，Visit是对结点操作的应用函数
//操作结果：后序递归遍历T，对每个结点调用函数Visit一次且仅一次
  if(T)
  {
  	PostOrderTraverse(T->lchild,Visit);
  	PostOrderTraverse(T->rchild,Visit);
  	Visit(T->data);
   } 
}

void LevelOrderTraverse(BiTree T,void(*Visit)(TElemType))
{//初始条件：二叉树T存在，Visit是对结点操作的应用函数
//操作结果：层序递归遍历T（利用队列），对每个结点调用函数Visit一次且仅一次
  LinkQueue q;
  QElemType a;
  if(T)
  {
  	InitQueue(q);
  	EnQueue(q,T);
  	while(!QueueEmpty(q))
  	{
  		DeQueue(q,a);
  		Visit(a->data);
  		if(a->lchild!=NULL)
  		   EnQueue(q,a->lchild);
  		if(a->rchild!=NULL)
  		   EnQueue(q,a->rchild);
	  }
	printf("\n");
   } 
}

void CreateBiTree(BiTree &T)
{//按先序次序输入二叉树中结点的值，构造二叉链表表示的二叉树T
  TElemType ch;
  scanf(form,&ch);
  if(ch==Nil)
    T=NULL;
  else
   {
   	T=(BiTree)malloc(sizeof(BiTNode));
   	if(!T)
   	  exit(OVERFLOW);
   	T->data=ch;
   	CreateBiTree(T->lchild);
   	CreateBiTree(T->rchild);
	} 
}

TElemType Parent(BiTree T,TElemType e)
{//初始条件：二叉树T存在，e是T中某个结点
//操作结果：若e是T的非根结点，则返回它的双亲，否则返回“空”
  LinkQueue q;
  QElemType a;
  if(T)
  {
  	InitQueue(q);
  	EnQueue(q,T);
  	while(!QueueEmpty(q))
  	{DeQueue(q,a);
  	 if(a->lchild&&a->lchild->data==e||a->rchild&&a->rchild->data==e)
  	    return a->data;
  	 else
     {
     	if(a->lchild)
     	  EnQueue(q,a->lchild);
     	if(a->rchild)
     	  EnQueue(q,a->rchild);
	 }
	}
   } 
   return Nil;
}

TElemType LeftSibling(BiTree T,TElemType e)
{//初始条件：二叉树T存在，e是T中某个结点
//操作结果：返回e的左兄弟。若e是T的左孩子或无左兄弟，则返回“空”
  TElemType a;
  BiTree p;
  if(T)
  {
  	a=Parent(T,a);
  	if(a!=Nil)
  	{
  		p=Point(T,a);
  		if(p->lchild&&p->rchild&&p->rchild->data==e)
  		  return p->lchild->data;
	  }
   } 
   return Nil;
}

TElemType RightSibling(BiTree T,TElemType e)
{//初始条件：二叉树T存在，e是T中某个结点
//操作结果：返回e的右兄弟。若e是T的右孩子或无右兄弟，则返回为空
  TElemType a;
  BiTree p;
  if(T)
  {
  	a=Parent(T,e);
  	if(a!=Nil)
  	{
  		p=Point(T,a);//p指向结点a的指针
		if(p->lchild&&p->rchild&&p->lchild->data==e)
		   return p->rchild->data; 
	  }
   } 
   return Nil;
}

Status InsertChild(BiTree p,int LR,BiTree c)
{//出初始条件：二叉树T存在，ｐ指向T中某个结点，LR为0或1，非空二叉树c与T不相交且右子树为空
//操作结果：根据LR为0或1，插入c为T中p所指结点的左或右子树。p所指结点的原有左或右子树则成为c的右子树
  if(p)
  {if(LR==0)
   {
   	c->rchild=p->lchild;
   	p->lchild=c;
   }
   else
   {
   	c->rchild=p->rchild;
   	p->rchild=c;
   }
   return OK;
   } 
   return ERROR;
}

typedef BiTree SElemType;
#include"c3-1.h"
#include"bo3-1.cpp"
void InOrderTraverse1(BiTree T,void(*Visit)(TElemType))
{//采用二叉链表存储结构，Visit是对数据元素操作的应用函数
//中序遍历二叉树T的非递归算法(利用栈)，对每个数据元素调用函数Visit
  SqStack S;
  InitStack(S);
  while(T||StackEmpty(S))
  {if(T)
   {//根指针进栈，遍历左子树
     Push(S,T); 
   	 T=T->lchild;
   }
   else//根指针退栈，访问根结点，遍历右子树
   {
   	 Pop(S,T);
   	 Visit(T->data);
   	 T=T->rchild;
	} 
   } 
   printf("\n");
}

void InOrderTraverse2(BiTree T,void(*Visit)(TElemType))
{//采用二叉链表存储结构，Visit是对数据元素操作的应用函数。
//中序遍历二叉树T的非递归算法(利用栈)，对每个数据元素调用函数Visit
   SqStack S;
   BiTree p;
   InitStack(S);
   Push(S,T);
   while(!StackEmpty(S))
   {
   	while(GetTop(S,p)&&p)
   	   Push(S,p->lchild);//向左走到尽头，入栈左孩子指针
    Pop(S,p);
	if(!StackEmpty(S))
	{
		Pop(S,p);//弹出栈顶元素(非空指针)
		Visit(p->data);//访问刚弹出的结点(目前栈顶元素的左孩子)
		Push(S,p->rchild); 
	 } 
   }
   printf("\n");
}
