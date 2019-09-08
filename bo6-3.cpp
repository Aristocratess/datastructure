Status BiTreeEmpty(BiTree T)
{//��ʼ������������T���ڡ� �����������TΪ�ն��������򷵻�ΪTRUE
   if(T)
     return FALSE;
   else
     return TRUE; 
}

int BiTreeDepth(BiTree T)
{//��ʼ������������T���ڡ�  �������������T�����
  int i,j;
  if(!T)
    return 0; 
  i=BiTreeDepth(T->lchild);
  j=BiTreeDepth(T->rchild);
  return i>j?i+1:j+1; 
}

TElemType Root(BiTree T)
{//��ʼ������������T���ڡ� �������������T�ĸ�
  if(BiTreeEmpty(T))
    return Nil;
  else
    return T->data; 
}

TElemType Value(BiTree p)
{//��ʼ������������T���ڣ�pָ��T��ĳ����㡣�������������p��ָ����ֵ
  return p->data; 
}

void Assign(BiTree p,TElemType value)
{//��p��ָ��㸳ֵΪvalue
  p->data=value; 
}

typedef BiTree QElemType;
#include"c3-2.h"
#include"bo3-2.cpp"
BiTree Point(BiTree T,TElemType s)
{//���ض�����T��ָ��Ԫ��ֵΪs�Ľ���ָ��
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
{//��ʼ������������T���ڣ�e��T��ĳ�����
//�������������e�����ӡ���e�����ӣ��򷵻�"��"
  BiTree a;
  if(T)
  {
  	a=Point(T,e);
  	if(a&&a->lchild)//T�д��ڽ��e��e�����Һ��� 
  	  return a->lchild->data;
   } 
  return Nil; 
}

TElemType RightChild(BiTree T,TElemType e)
{//��ʼ����:������T���ڣ�e��T��ĳ�����
//�������:����e���Һ��ӡ���e���Һ��ӣ��򷵻ؿա�
  BiTree a;
  if(T)
  {
  	a=Point(T,e);
  	if(a&&a->rchild)//T�д��ڽ��e��e�����Һ��� 
  	   return a->rchild->data;
   } 
   return Nil; 
}
Status DeleteChild(BiTree p,int LR)
{//��ʼ������������T���ڣ�pָ��T��ĳ����㣬LRΪ0��1
//�������������LRΪ0��1��ɾ��T��p��ָ�������������
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
{//��ʼ������������T���ڣ�Visit�ǶԽ�������Ӧ�ú���
//�������������ݹ����T����ÿ�������ú���Visitһ���ҽ�һ��
  if(T)
  {
  	PostOrderTraverse(T->lchild,Visit);
  	PostOrderTraverse(T->rchild,Visit);
  	Visit(T->data);
   } 
}

void LevelOrderTraverse(BiTree T,void(*Visit)(TElemType))
{//��ʼ������������T���ڣ�Visit�ǶԽ�������Ӧ�ú���
//�������������ݹ����T�����ö��У�����ÿ�������ú���Visitһ���ҽ�һ��
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
{//�������������������н���ֵ��������������ʾ�Ķ�����T
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
{//��ʼ������������T���ڣ�e��T��ĳ�����
//�����������e��T�ķǸ���㣬�򷵻�����˫�ף����򷵻ء��ա�
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
{//��ʼ������������T���ڣ�e��T��ĳ�����
//�������������e�����ֵܡ���e��T�����ӻ������ֵܣ��򷵻ء��ա�
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
{//��ʼ������������T���ڣ�e��T��ĳ�����
//�������������e�����ֵܡ���e��T���Һ��ӻ������ֵܣ��򷵻�Ϊ��
  TElemType a;
  BiTree p;
  if(T)
  {
  	a=Parent(T,e);
  	if(a!=Nil)
  	{
  		p=Point(T,a);//pָ����a��ָ��
		if(p->lchild&&p->rchild&&p->lchild->data==e)
		   return p->rchild->data; 
	  }
   } 
   return Nil;
}

Status InsertChild(BiTree p,int LR,BiTree c)
{//����ʼ������������T���ڣ���ָ��T��ĳ����㣬LRΪ0��1���ǿն�����c��T���ཻ��������Ϊ��
//�������������LRΪ0��1������cΪT��p��ָ���������������p��ָ����ԭ��������������Ϊc��������
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
{//���ö�������洢�ṹ��Visit�Ƕ�����Ԫ�ز�����Ӧ�ú���
//�������������T�ķǵݹ��㷨(����ջ)����ÿ������Ԫ�ص��ú���Visit
  SqStack S;
  InitStack(S);
  while(T||StackEmpty(S))
  {if(T)
   {//��ָ���ջ������������
     Push(S,T); 
   	 T=T->lchild;
   }
   else//��ָ����ջ�����ʸ���㣬����������
   {
   	 Pop(S,T);
   	 Visit(T->data);
   	 T=T->rchild;
	} 
   } 
   printf("\n");
}

void InOrderTraverse2(BiTree T,void(*Visit)(TElemType))
{//���ö�������洢�ṹ��Visit�Ƕ�����Ԫ�ز�����Ӧ�ú�����
//�������������T�ķǵݹ��㷨(����ջ)����ÿ������Ԫ�ص��ú���Visit
   SqStack S;
   BiTree p;
   InitStack(S);
   Push(S,T);
   while(!StackEmpty(S))
   {
   	while(GetTop(S,p)&&p)
   	   Push(S,p->lchild);//�����ߵ���ͷ����ջ����ָ��
    Pop(S,p);
	if(!StackEmpty(S))
	{
		Pop(S,p);//����ջ��Ԫ��(�ǿ�ָ��)
		Visit(p->data);//���ʸյ����Ľ��(Ŀǰջ��Ԫ�ص�����)
		Push(S,p->rchild); 
	 } 
   }
   printf("\n");
}
