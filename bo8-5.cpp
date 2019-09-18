void InitDSTable(DLTree &DT)
{//�������������һ���յ�˫������DT 
	DT=NULL; 
}

void DestroyDSTable(DLTree &DT)
{//��ʼ������˫������DT���ڡ�  �������������DT
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
{//��˫������T�в��ҹؼ��ִ�����K�ļ�¼�������ڣ��򷵻�ָ��ü�¼��ָ�룬���򷵻ؿ�ָ��
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
{//��ʼ������˫������DT���ڣ�rΪ�����������Ԫ�ص�ָ��
//�����������DT�в�������ؼ��ִ�����(*r).key.ch������Ԫ�أ��򰴹ؼ���˳���r��DT��
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
{//��ʼ������˫������DT���ڣ�Visit�ǶԼ�¼������Ӧ�ú���
//������������ؼ��ֵ�˳������ؼ��ּ����Ӧ�ļ�¼
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
