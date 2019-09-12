#define ClearTree DestroyTree
void InitTree(CSTree &T)
{
	T=NULL;
}

void DestroyTree(CSTree &T)
{//初始条件：树T存在  操作结果：销毁树T
  if(T)
  {
  	DestroyTree(T->firstchild);
  	DestroyTree(T->nextsibling);
  	free(T);
  	T=NULL;
   } 
}

typedef CSTree QElemType;
#include"c3-2.h"
#include"bo3-2.cpp"
void CreateTree(CSTree &T)
{
	char c[20];
	CSTree p,p1;
	LinkQueue q;
	int i,m;
	InitQueue(q);
	printf("请输入根结点(字符型，空格为空)：");
	scanf("%c%*c",&c[0]);//输入根结点的值
	if(c[0]!=Nil)
	{
		T=(CSTree)malloc(sizeof(CSNode));
		T->data=c[0];
		T->nextsibling=NULL;
		EnQueue(q,T);
		while(!QueueEmpty(q))
		{
			DeQueue(q,p);
			printf("请按长幼顺序输入结点%c的所有孩子：",p->data);
			gets(c);
			m=strlen(c);
			if(m>0)
			{
				p1=p->firstchild=(CSTree)malloc(sizeof(CSNode));
				p1->data=c[0];
				EnQueue(q,p1);
				for(i=1;i<m;i++)
				{
					p1->nextsibling=(CSTree)malloc(sizeof(CSNode));
					p1->data=c[0];
					EnQueue(q,p1);
					for(i=1;i<m;i++)
					{
						p1->nextsibling=(CSTree)malloc(sizeof(CSNode));
						p1=p1->nextsibling;
						p1->data=c[i];
						EnQueue(q,p1);
					}
					p1->nextsibling=NULL;
				}
			}
			else
			  p->firstchild=NULL;
		}
	
	 } 
	 else
	   T=NULL;
}

Status TreeEmpty(CSTree T)
{//初始条件：树T存在。 操作结果：若T为空树，则返回TRUE，否则返回FALSE
  if(T)
    return FALSE;
  else
    return TRUE; 
 } 
 
int TreeDepth(CSTree T)
{//初始条件：树T存在  操作结果：返回T的深度
  CSTree p;
  int depth,max=0;
  if(!T)
    return 0;
  for(p=T->firstchild;p;p=p->nextsibling)//对于树T根结点的所有孩子结点（由p指向）
  {//求子树深度的最大值 
  	 depth=TreeDepth(p);
  	 if(depth>max)
  	    max=depth;
   } 
   return max+1;
}

TElemType Value(CSTree p)
{//返回p所指结点的值
    return p->data; 
}

TElemType Root(CSTree T)
{//初始条件：树T存在   操作结果：返回T的根
  if(T)
     return Value(T);
  else
     return Nil; 
}

CSTree Point(CSTree T,TElemType s)
{//返回二叉链表（孩子-兄弟）树T中指向元素值为s的结点的指针
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
  	    if(a->firstchild)
  	      EnQueue(q,a->firstchild);
  	    if(a->nextsibling)
  	      EnQueue(q,a->nextsibling);
	  }
  }
  return NULL;
}

Status Assign(CSTree &T,TElemType cur_e,TElemType value)
{//初始条件：树T存在，cur_e是树T中结点的值。 操作结果：改cur_e为value
  CSTree p;
  if(T)
  {
  	p=Point(T,cur_e);
  	if(p)
  	{
  		p->data=value;
  		return OK;
	  }
   } 
   return ERROR;
}

TElemType Parent(CSTree T,TElemType cur_e)
{//初始条件：树T存在，cur_e 是T中某个结点
//操作结果：若cur_e是T的非根结点，则返回它的双亲；否则函数值为"空"
  CSTree p,t;
  LinkQueue q;
  InitQueue(q);
  if(T)
  {
  	if(Value(T)==cur_e)
  	   return Nil;
  	EnQueue(q,T);
  	while(!QueueEmpty(q))
  	{
  		DeQueue(q,p);
  		if(p->firstchild)
  		{if(p->firstchild->data==cur_e)
  		    return Value(p);
  		 t=p;//双亲指针赋给t
		 p=p->firstchild;
		 EnQueue(q,p);
		 while(p->nextsibling)
		 {
		 	p=p->nextsibling;//p指向下一个兄弟
			if(Value(p)==cur_e)
			  return Value(t);
			EnQueue(q,p);//入队下一个兄弟 
		  } 
		  }
	  }
   } 
   return Nil;//树空或未找到cur_e 
}

TElemType LeftChild(CSTree T,TElemType cur_e)
{//初始条件：树T存在，cur_e是T中某个结点
//操作结果：若cur_e是T 非叶子结点，则返回它的最左孩子，否则返回"空"
  CSTree f;
  f=Point(T,cur_e);
  if(f&&f->firstchild)//找到结点cur_e且结点cur_e有长子
    return f->firstchild->data;//返回结点cur_e的长子的值
  else
    return Nil; 
 } 

TElemType RightSibling(CSTree T,TElemType cur_e)
{//初始条件：树T存在，cur_e是T中某个结点
//操作结果：若cur_e有右兄弟，则返回它的右兄弟，否则返回"空"
  CSTree f;
  f=Point(T,cur_e);
  if(f&&f->nextsibling)//找到结点cur_e且结点cur_e有右兄弟
    return f->nextsibling->data;
  else
    return Nil; 
}

Status InsertChild(CSTree &T,CSTree p,int i,CSTree c)
{//初始条件：树T存在，p指向T中某个结点，1<=i<=p所指结点的度+1，非空树c与T不相交
//操作结果：插入c为T中p结点的第i棵子树。因为p所指结点的地址不会改变，故p不需要是引用类型
  int j;
  CSTree q;
  if(T)
  {
  	if(i==1)
  	{
  		c->nextsibling=p->firstchild;//p的原长子现是c的下一个兄弟
		p->firstchild=c;//p的长子指针指向c 
	  }
	else
	{
		q=p->firstchild;
		j=2;
		while(q&&j<i)
		{
			q=q->nextsibling;
			j++;
		}
		if(j==i)
		{
			c->nextsibling=q->nextsibling;//c的下一个兄弟指向p的原第i个孩子
			q->nextsibling=c;//在p中插入c作为p的第i个孩子 
		}
		else
		  return ERROR; 
	}
	return OK;
   } 
   else
     return ERROR;
}

Status DeleteChild(CSTree &T,CSTree p,int i)
{//初始条件：树T存在，p指向T中某个结点，1<=i<=p所指结点的度
//操作结果:删除T中p所指结点的第i棵子树。因为p所指结点的地址不会改变，故p不需要是引用类型
  CSTree b,q;
  int j;
  if(T)
  {
  	if(i==1)
  	{//把长子结点子树从p中分离出来
	    b=p->firstchild;
		p->firstchild=b->nextsibling;
		b->nextsibling=NULL; 
  		DestroyTree(b);
	  }
	else
	{
		q=p->firstchild;
		j=2;
		while(q&&j<i)
	    {
	    	q=q->nextsibling;
	    	j++;
		}
		if(j==i)
		{
			b=q->nextsibling;
			q->nextsibling=b->nextsibling;
			b->nextsibling=NULL;//待删除子树的根结点的下一个兄弟指针为空 
			DestroyTree(b);
		}
		else
		  return ERROR; 
	}
	return OK;
   } 
   else
     return ERROR;
}

void PostOrderTraverse(CSTree T,void(*Visit)(TElemType))
{//后根遍历孩子-兄弟二叉链表结构的树T
  CSTree p;
  if(T)
  {
  	if(T->firstchild)
  	{
  		PostOrderTraverse(T->firstchild,Visit);
  		p=T->firstchild->nextsibling;//p指向长子的下一个兄弟
		while(p)
		{
			PostOrderTraverse(p,Visit);
			p=p->nextsibling;
		 } 
	  }
	  Visit(Value(T));
   } 
}

void LevelOrderTraverse(CSTree T,void(*Visit)(TElemType))
{//层序遍历孩子-兄弟二叉链表结构的树T
  CSTree p;
  LinkQueue q;
  InitQueue(q);
  if(T)
  {
  	Visit(Value(T));
  	EnQueue(q,T);
  	while(!QueueEmpty(q))
  	{
  		DeQueue(q,p);
  		if(p->firstchild)
  		{
  			p=p->firstchild;
  			Visit(Value(p));
  			EnQueue(q,p);
  			while(p->nextsibling)
  			{
  				p=p->nextsibling;
  				Visit(Value(p));
  				EnQueue(q,p);
			  }
		  }
	  }
  }
  printf("\n");
}



