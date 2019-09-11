void CreateBiThrTree(BiThrTree &T)
{//按先序输入线索二叉树结点的值，构造线索二叉树T。
  TElemType ch;
  scanf(form,&ch);
  if(ch==Nil)
     T=NULL;
  else
   {
   	 T=(BiThrTree)malloc(sizeof(BiThrNode));
   	 if(!T)
   	   exit(OVERFLOW);
   	 T->data==ch;
   	 CreateBiThrTree(T->lchild);
   	 if(T->lchild)
   	   T->LTag=Link;
   	 CreateBiThrTree(T->rchild);
	 if(T->rchild)
	   T->RTag=Link; 
	} 
}

BiThrTree pre;//全局变量，始终指向刚刚访问过的结点
void InThreading(BiThrTree p)
{//通过中序遍历进行中序线索化，线索化之后pre指向最后一个结点
  if(p)
  {
  	InThreading(p->lchild);
  	if(!p->lchild)
  	{
  		p->LTag=Thread;
  		p->lchild=pre;
	  }
	if(!pre->rchild)//前驱没有右孩子
	{
		pre->RTag=Thread;//前驱的右标志为线索(后继) 
		pre->rchild=p;//前驱右孩子指针指向其后继 
	 } 
	pre=p;
	InThreading(p->rchild); 
   } 
 } 
 

void InOrderThreading(BiThrTree &Thrt,BiThrTree T)
{//中序遍历二叉树T，并将其中序线索化，Thrt指向头结点
  if(!(Thrt=(BiThrTree)malloc(sizeof(BiThrNode)))) 
     exit(OVERFLOW);
  Thrt->LTag=Link;//建头结点，左标志为指针
  Thrt->RTag=Thread;
  Thrt->rchild=Thrt;
  if(!T)
    Thrt->lchild=Thrt;
  else
  {Thrt->lchild=T;//头结点的左孩子指针指向根结点
   pre=Thrt;//pre(前序)的初值指向头结点 
   InThreading(T); 
   pre->rchild=Thrt;
   pre->RTag=Thread;
   Thrt->rchild=pre; 
   } 
}

void InOrderTraverse_Thr(BiThrTree T,void(*Visit)(TElemType))
{//中序遍历线索二叉树T(头结点)的非递归算法
   BiThrTree p;
   p=T->lchild;
   while(p!=T)
   {//空树或遍历结束时，p==T
     while(p->LTag==Link)//由根结点一直找到二叉树的最左结点
	   p=p->lchild;
	 Visit(p->data);
	 while(p->RTag==Thread&&p->rchild!=T)
	 {//p->rchild是线索(后继)，且不是遍历的最后一个结点
	   p=p->rchild;
	   Visit(p->data); 
	  } 
	 //若p->rchild不是线索(是右孩子)，p指向右孩子，返回循环，找这颗子树中序遍历的第1个结点
	 p=p->rchild; 
	} 
}

void PreThreading(BiThrTree p)
{
	if(!pre->rchild)
	{
		pre->RTag=Thread;
		pre->rchild=p;
	}
	if(!p->lchild)
	{
		p->LTag=Thread;
		p->lchild=pre;
	}
	pre=p;
	if(p->LTag==Link)
	  PreThreading(p->lchild);
	if(p->RTag==Link)
	  PreThreading(p->rchild);
}

void PreOrderThreading(BiThrTree &Thrt,BiThrTree T)
{//先序线索化二叉树T，头结点的右孩子指针指向先序遍历的最后1个结点
  if(!(Thrt=(BiThrTree)malloc(sizeof(BiThrNode))));
     exit(OVERFLOW);
  Thrt->LTag=Link;
  Thrt->RTag=Thread;
  Thrt->rchild=Thrt;
  if(!T)
    Thrt->lchild=Thrt;
  else
  {
  	Thrt->lchild=T;
  	pre=Thrt;
  	PreThreading(T);
  	pre->RTag=Thread;
  	pre->rchild=Thrt;
  	Thrt->rchild=pre;
  }
}

void PreOrderTraverse_Thr(BiThrTree T,void(*Visit)(TElemType))
{//先序遍历线索二叉树T(头结点)的非递归算法
  BiThrTree p=T->lchild;
  while(p!=T)//p未指向头结点
  {
  	Visit(p->data);
  	if(p->LTag==Link)
  	  p=p->lchild;
	else
	  p=p->rchild; 
   } 
}

void PostThreading(BiThrTree p)
{
	if(p)
	{
		PostThreading(p->lchild);
		PostThreading(p->rchild);
		if(!p->lchild)
		{
			p->LTag=Thread;
			p->lchild=pre;
		}
		if(!pre->rchild)
		{
			pre->RTag=Thread;
			pre->rchild=p;
		}
	pre=p;
	}
}

void PostOrderThreading(BiThrTree &Thrt,BiThrTree T)
{//后序递归线索化二叉树
  if(!(Thrt=(BiThrTree)malloc(sizeof(BiThrNode))))
     exit(OVERFLOW);
  Thrt->LTag=Link;
  Thrt->RTag=Thread;
  if(!T)
    Thrt->lchild=Thrt->rchild=Thrt;//头结点的左右孩子指针指向自身
  else
  {
  	Thrt->lchild=Thrt->rchild=T;//头结点的左右孩子指针指向根结点
	pre=Thrt;
	PostThreading(T);
	if(pre->RTag!=Link)
	{
		pre->RTag=Thread;
		pre->rchild=Thrt;
	 } 
   } 
}

void DestroyBiTree(BiThrTree &T)
{
	if(T)
	{
		if(T->LTag==0)
		  DestroyBiTree(T->lchild);
		if(T->RTag==0)
		  DestroyBiTree(T->rchild);
		free(T);
		T=NULL;
	}
}

void DestroyBiThrTree(BiThrTree &Thrt)
{//初始条件：线索二叉树Thrt存在  操作结果：销毁线索二叉树Thrt
  if(Thrt)
  {
  	if(Thrt->lchild)
  	  DestroyBiTree(Thrt->lchild);
  	free(Thrt);
  	Thrt=NULL;//线索二叉树 Thrt指针赋0 
   } 
}
