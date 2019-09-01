#include"func5-3.cpp"
int InitGList(GListl &L)
{
	L=(GListl)malloc(sizeof(GLNodel));
	L->tag=LIST;//����ͷ���ı�־��ֵ
	L->hp=L->tp=NULL;//����ͷ����ָ����ֵ 
 } 

void Create(GListl &L,SString S)
{//�ɹ�������д��ʽ��S�����ӱ�L��CreateGlist()����
  SString emp,sub,hsub;
  GListl p;
  StrAssign(emp,"()");
  if(!(L=(GListl)malloc(sizeof(GLNodel))))
    exit(OVERFLOW);
  if(!StrCompare(S,emp))
    {
    	L->tag=LIST;
    	L->hp=NULL;
	   }   
   else if(StrLength(S)==1)
   {
   	L->tag=ATOM;//�����ı�־��ֵ 
   	L->atom=S[1];//������ֵ��ֵ 
	} 
   else
   {
   	L->tag=LIST;
	SubString(sub,S,2,StrLength(S)-2);
	//���������(ȥ����1���ַ�(������)�����1���ַ�(������))����sub
	server(sub,hsub);//��sub�з������ͷ��hsub(��㶺��֮ǰ��),��β������sub
	Create(L->hp,hsub);
	p=L->hp;//pָ���ӱ�ı�ͷԪ��
	while(!StrEmpty(sub))
	{
		sever(sub,hsub);//��sub�з������ͷ��hsub
		Create(p->tp,hsub);
		p=p->tp;//p����� 
	 } 
	 }  
	L->tp=NULL; 
 } 
 
void CreateGList(GListl &L,SString S)
{//������չ��������洢�ṹ���ɹ�������д��ʽ��S���������L��L���ΪΪ�յĹ����
    SString emp,sub,hsub;
    GListl p;
	StrAssign(emp,"()");
	if(!StrCompare(S,emp))
	  InitGList(L);
	else
	{
		SubString(sub,S,2,StrLength(S)-2);
		//���������(ȥ����1���ַ��������ţ������һ���ַ��������ţ�)����sub
		server(sub,hsub);//��sub�з������ͷ��hsub(��㶺��֮ǰ��)����β������sub
		Create(L->hp,hsub);
		p=L->hp;
		while(!StrEmpty(sub))//��β���գ�����������ӱ�
		{
			server(sub,hsub);//��sub�з������ǰ��Ĵ���hsub�����ಿ�ָ���sub
			Create(p->tp,hsub);
			p=p->tp; 
		 } 
	p->tp=NULL;	 
	}
}

void DestroyGList(GListl &L)
{//��ʼ�����������L����  �������:���ٹ����L
  GListl ph,pt;
  if(L)
  {
  	//��ph��pt����L������ָ��
	if(L->tag)//���ӱ�
	  ph=L->hp;
	else
	  ph=NULL;
	pt=L->tp;
    DestroyGList(ph);
	DestroyGList(pt);
	free(L);
	L=NULL; 
   } 
}

void CopyGList(GListl &T,GListl L)
{//��ʼ�����������L���ڡ� �������:�ɹ����L���Ƶõ������T
  T=NULL;
  if(L)
  {
  	T=(GListl)malloc(sizeof(GLNodel));
  	if(!T)
  	  exit(OVERFLOW);
  	T->tag=L->tag;//����ö�ٱ���
	if(L->tag==ATOM)
	  T->atom=L->atom;
	else
	  CopyGList(T->hp,L->hp);
	if(L->tp==NULL)
	  T->tp=L->tp;
	else
	 CopyGList(T->tp,L->tp); 
   } 
}

int GListLength(GListl L)
{//��ʼ����: �����L���ڡ�  ����������ɹ����L���Ƶõ������T
  int len=0;
  GListl p=L->hp;//pָ���1��yuans
  while(p)
  {
  	len++;
  	p=p->tp;
   };
  return len; 
}

int GListDepth(GListl L)
{//��ʼ�����������L���ڡ�  ���������������L�����
    int max=0,dep;
    GListl p;
	if(L->tag==LIST&&!L->hp)
	  return 1;//�ձ����Ϊ1
	else if(L->tag==ATOM)
	  return 0;//��ԭ�ӱ����Ϊ0��ֻ������ڵݹ������
	else//��һ�������
	  for(p=L->hp;p;p=p->tp)
	  {
	  	dep=GListDepth(p);//����pΪͷָ����ӱ����
		if(dep>max)
		 max=dep; 
	   } 
	return max+1;//�ǿձ������Ǹ�Ԫ�ص���ȵ����ֵ��1 
}

Status GListEmpty(GListl L)
{//��ʼ����:�����L���ڡ� ����������ж������L�Ƿ�Ϊ��
  if(!L->hp)
    return OK;
  else
    return ERROR; 
 } 
 
GListl GetHead(GListl L)
{//��ʼ����:�����L���ڡ�  �������:���ɹ����L�ı�ͷԪ�أ�����ָ�����Ԫ�ص�ָ��
   GListl h,p;
   if(!L->hp)
     return NULL;
   p=L->hp->tp;
   L->hp->tp=NULL;//��ȥL�ı�β����
   CopyGList(h,L->hp);//����ͷԪ�ظ��Ƹ�h
   L->hp->tp=p;//�ָ�L�ı�β 
}

GListl GetTail(GListl L)
{//��ʼ�����������L���ڡ�  �����������L�ı�β���ɹ��������ָ������¹�����ָ��
  GListl t;
  InitGList(t);
  if(L->hp)
    CopyGList(t->hp,L->hp->tp);//��L�ı�β���Ƹ�t�ı�ͷ
  return t; 
}

void InsertFirst_GL(GListl &L,GListl e)
{//��ʼ����:�����L���ڡ� �������:����Ԫ��e(Ҳ�������ӱ�)��ΪL�ĵ�1��Ԫ��(��ͷ)
  GListl p=L->hp;//pָ������L�ĵ�1��Ԫ��
  L->hp=e;//�����L��ͷָ��ָ��e
  e-tp=p;//e(ֻ��1��Ԫ�أ���βָ���ΪNULL)��βָ��ָ��Lԭ���ĵڣ���Ԫ�� 
}

void DeleteFirst_GL(GListl &L,GListl &e)
{//��ʼ�����������L���ڡ� ���������ɾ�������L�ĵ�1��Ԫ�أ�����e������ָ��
  e=L->hp;//eָ��L�ĵ�1��Ԫ��
  if(L->hp)//L�ǿ�
  {
  	 L->hp=e->tp;//L��ͷָ��ָ��ԭ��2��Ԫ��
	 e->tp=NULL;//e��βָ����Ϊ�� 
   } 
 } 
 
void Travese_GL(GListl L,void(*visit)(AtomType))
{//���õݹ��㷨���������L
  if(L)
  {
  	if(L->tag==ATOM)
  	  visit(L->atom);
  	else
  	  Traverse_GL(L->hp,visit);
  	Traverse_GL(L->tp,visit);
   } 
 } 
 
 
