void CreateBiThrTree(BiThrTree &T)
{//������������������������ֵ����������������T��
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

BiThrTree pre;//ȫ�ֱ�����ʼ��ָ��ոշ��ʹ��Ľ��
void InThreading(BiThrTree p)
{//ͨ�������������������������������֮��preָ�����һ�����
  if(p)
  {
  	InThreading(p->lchild);
  	if(!p->lchild)
  	{
  		p->LTag=Thread;
  		p->lchild=pre;
	  }
	if(!pre->rchild)//ǰ��û���Һ���
	{
		pre->RTag=Thread;//ǰ�����ұ�־Ϊ����(���) 
		pre->rchild=p;//ǰ���Һ���ָ��ָ������ 
	 } 
	pre=p;
	InThreading(p->rchild); 
   } 
 } 
 

void InOrderThreading(BiThrTree &Thrt,BiThrTree T)
{//�������������T��������������������Thrtָ��ͷ���
  if(!(Thrt=(BiThrTree)malloc(sizeof(BiThrNode)))) 
     exit(OVERFLOW);
  Thrt->LTag=Link;//��ͷ��㣬���־Ϊָ��
  Thrt->RTag=Thread;
  Thrt->rchild=Thrt;
  if(!T)
    Thrt->lchild=Thrt;
  else
  {Thrt->lchild=T;//ͷ��������ָ��ָ������
   pre=Thrt;//pre(ǰ��)�ĳ�ֵָ��ͷ��� 
   InThreading(T); 
   pre->rchild=Thrt;
   pre->RTag=Thread;
   Thrt->rchild=pre; 
   } 
}

void InOrderTraverse_Thr(BiThrTree T,void(*Visit)(TElemType))
{//�����������������T(ͷ���)�ķǵݹ��㷨
   BiThrTree p;
   p=T->lchild;
   while(p!=T)
   {//�������������ʱ��p==T
     while(p->LTag==Link)//�ɸ����һֱ�ҵ���������������
	   p=p->lchild;
	 Visit(p->data);
	 while(p->RTag==Thread&&p->rchild!=T)
	 {//p->rchild������(���)���Ҳ��Ǳ��������һ�����
	   p=p->rchild;
	   Visit(p->data); 
	  } 
	 //��p->rchild��������(���Һ���)��pָ���Һ��ӣ�����ѭ���������������������ĵ�1�����
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
{//����������������T��ͷ�����Һ���ָ��ָ��������������1�����
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
{//�����������������T(ͷ���)�ķǵݹ��㷨
  BiThrTree p=T->lchild;
  while(p!=T)//pδָ��ͷ���
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
{//����ݹ�������������
  if(!(Thrt=(BiThrTree)malloc(sizeof(BiThrNode))))
     exit(OVERFLOW);
  Thrt->LTag=Link;
  Thrt->RTag=Thread;
  if(!T)
    Thrt->lchild=Thrt->rchild=Thrt;//ͷ�������Һ���ָ��ָ������
  else
  {
  	Thrt->lchild=Thrt->rchild=T;//ͷ�������Һ���ָ��ָ������
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
{//��ʼ����������������Thrt����  �����������������������Thrt
  if(Thrt)
  {
  	if(Thrt->lchild)
  	  DestroyBiTree(Thrt->lchild);
  	free(Thrt);
  	Thrt=NULL;//���������� Thrtָ�븳0 
   } 
}
