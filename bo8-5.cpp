void InitDSTable(DLTree &DT)
{//操作结果：构造一个空的双链键树DT 
	DT=NULL; 
}

void DestroyDSTable(DLTree &DT)
{//初始条件：双链键树DT存在。  操作结果：销毁DT
  if(DT)
  {
  	if(DT->kind==BRANCH)
  	  DestroyDSTable(DT->first);
  	DestroyDSTable(DT->next);
  	free(DT);
  	DT=NULL;
   } 
}

Record* SearchDLTree(DLTree T,KeyType K)
{//在双链键树T中查找关键字串等于K的记录，若存在，则返回指向该记录的指针，否则返回空指针
   DLTree p=T;
   int i=0;
   if(T)
   {
   	while(p&&i<K.num)
   	{
   		while(p&&p->symbol!=K.ch[i])
   		  p=p->next;
   		if(p&&i<K.num)
   		  p=p->first;
   		++i;
	   }
	if(!p)
	  return NULL;
	else
	  return p->infoptr;
	} 
    else
      return NULL;
 } 
 
void InsertDSTable(DLTree &DT,Record* r)
{//初始条件：双链键树DT存在，r为待插入的数据元素的指针
//操作结果：若DT中不存在其关键字串等于(*r).key.ch的数据元素，则按关键字顺序插r到DT中
  DLTree p=NULL,q,ap;
  int i=0;
  KeyType K=r->key;
  if(!DT&&K.num)
  {
  	DT=ap=(DLTree)malloc(sizeof(DLTNode));
  	for(;i<K.num;i++)
  	{
  		if(p)
  		  p->first=ap;
  		ap->next=NULL;
  		ap->symbol=K.ch[i];
  		ap->kind=BRANCH;
  		p=ap;
  		ap=(DLTree)malloc(sizeof(DLTNode));
	  }
	p->first=ap;
	ap->next=NULL;
	ap->symbol=Nil;
	ap->kind=LEAF;
	ap->infoptr=r;
   } 
   else
   {
   	p=DT;
   	while(p&&i<K.num)
   	{
   		while(p&&p->symbol<K.ch[i])
   		{
   			q=p;
   			p=p->next;
		   }
		if(p&&p->symbol==K.ch[i])
		{
			q=p;
			p=p->first;
			++i;
		}
		else
		{
			ap=(DLTree)malloc(sizeof(DLTNode));
			if(q->first==p)
			   q->first=ap;
			else
			   q->next=ap;
			ap->next=p;
			ap->symbol=K.ch[i];
			ap->kind=BRANCH;
			p=ap;
			ap=(DLTree)malloc(sizeof(DLTNode));
			i++;
			for(;i<K.num;i++)
			{
				p->first=ap;
				ap->next=NULL;
				ap->symbol=K.ch[i];
				ap->kind=BRANCH;
				p=ap;
				ap=(DLTree)malloc(sizeof(DLTNode));
			 } 
			 p->first=ap;
			 ap->next=NULL;
			 ap->symbol=Nil;
			 ap->kind=LEAF;
			 ap->infoptr=r;
		}
	   }
   }
}

struct SElemType{
	char ch;
	DLTree p;
};
#include"c3-1.h"
#include"bo3-1.cpp"
void TraverseDSTable(DLTree DT,void(*Visit)(Record*))
{//初始条件：双链键树DT存在，Visit是对记录操作的应用函数
//操作结果：按关键字的顺序输出关键字及其对应的记录
  SqStack s;
  SElemType e;
  DLTree p;
  int i=0,n=9;
  if(DT)
  {
  	InitStack(s);
  	e.p=DT;
  	e.ch=DT->symbol;
	Push(s,e);
	p=DT->first;
	while(p->kind==BRANCH)
	{
		e.p=p;
		e.ch=p->symbol;
		Push(s,e);
		p=p->first;
	   }   
	e.p=p;
	e.ch=p->symbol;
	Push(s,e);
	Visit(p->infoptr);
	i++;
	while(!StackEmpty(s))
	{
		Pop(s,e);
		p=e.p;
		if(p->next)
		{
			p=p->next;
			while(p->kind==BRANCH)
			{
				e.p=p;
				e.ch=p->symbol;
				Push(s,e);
				p=p->first;
			}
			e.p=p;
			e.ch=p->symbol;
			Push(s,e);
			Visit(p->infoptr);
			i++;
			if(i%n==0)
			  printf("\n");
		}
	}
   } 
}
