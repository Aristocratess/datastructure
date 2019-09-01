#include"func5-3.cpp"
void InitGList(GList &L)
{
	L=NULL;
}

void CreateGList(GList &L,SString S)
{//����ͷβ����洢�ṹ���ɹ�������д��ʽ��S���������L����emp="()"
  SString sub,hsub,emp;
  GList p,q;
  StrAssign(emp,"()");
  if(!StrCompare(S,emp))
    L=NULL;
  else
   {if(!(L=(GList)malloc(sizeof(GLNode))))
      exit(OVERFLOW);
    if(StrLength(S)==1)//SΪ��ԭ�ӣ��������ֻ������ڵݹ������
	{
		L->tag=ATOM;//������ԭ�ӹ���� 
		L->atom=S[1];//��ԭ�ӵ�ֵΪ�ַ��� 
	 } 
	else{
		L->tag=LIST;//L���ӱ� 
		p=L;//pҲָ���ӱ�
		SubString(sub,S,2,StrLength(S)-2);
		//���������(ȥ����1���ַ��������ţ������1���ַ�(������))����sub
		do
		{
			sever(sub,hsub);//��sub�з������ͷ����hsub�����ಿ��(��β)��sub
			CreateGList(p->ptr.hp,hsub);//�ݹ鴴����ͷ����ʾ���ӱ�
			q=p;//qָ��p��ָ���
			if(!StrEmpty(sub))
			{
				if(!(p=(GLNode*)malloc(sizeof(GLNode))))
				    exit(OVERFLOW);
			    p->tag=LIST;//p���ӱ�
				q->ptr.tp=p;//p��ָ������q��ָ���֮���γ�q����һ����� 
			 } 
		 } while(!StrEmpty(sub));
		 q->ptr.tp=NULL;//�������һ����βָ��Ϊ�� 
	} 
	} 
}

void DestroyGList(GList &L)
{//���ٹ����L
  GList q1,q2;
  if(L)
  {if(L->tag==LIST)
  {
  	q1=L->ptr.hp;//q1ָ���ͷ
	q2=L->ptr.tp;//q2ָ���β(����ͷ֮������ಿ��)
	DestroyGList(q1);
	DestroyGList(q2); 
  }
  free(L);//�ͷ�L��ָ�Ĵ洢�ռ�(����L�Ǳ��㻹��ԭ�ӽ��)
  L=NULL;//L��ָ���κδ洢��Ԫ 
   } 
 } 
 
void CopyGList(GList &T,GList L)
{//����ͷβ����洢�ṹ���ɹ����L���Ƶõ������T
  if(!L)
     T=NULL;
  else
    {
      T=(GList)malloc(sizeof(GLNode));
      if(!T)
        exit(OVERFLOW);
      T->tag=L->tag;
      if(L->tag==ATOM)
         T->atom=L->atom;
      else
      {
      	CopyGList(T->ptr.hp,L->ptr.hp);//�ݹ鸴�Ʊ�ͷ�ӱ�
		CopyGList(T->ptr.tp,L->ptr.tp);
	  }
	 } 
 } 
 
 int GListLength(GList L)
 {//���ع����ĳ��ȣ���Ԫ�ظ���
    int len=0;
	while(L)
	{
		L=L->ptr.tp;
		len++;
	 } 
	return len;
 }
 
 int GListDepth(GList L)
 {//����ͷβ����洢�ṹ��������L�����
   int dep,max=0;
   GList pp;
   if(!L)
     return 1;
   if(L->tag==ATOM)
      return 0;
   for(pp=L;pp;pp=pp->ptr.tp)
    {
    	dep=GListDepth(pp->ptr.hp);//�ݹ�����pp->ptr.hpΪͷָ����ӱ����
		if(dep>max)
		  max=dep;//max�汾���ӱ���ȵ����ֵ 
	 } 
	return max+1;//�ǿձ������Ǹ�Ԫ�ص���ȵ����ֵ��1 
 }
 
 Status GListEmpty(GList L)
 {//�ж�������Ƿ�Ϊ��
   if(!L)
     return TRUE;
   else
     return FALSE; 
 }
 
GList GetHead(GList L)
{//���ɹ����L�ı�ͷԪ�أ�����ָ�����Ԫ�ص�ָ��
  GList h;
  if(!L)
    return NULL;
  CopyGList(h,L->ptr.hp);
  return h; 
}

GList GetTail(GList L)
{//�������L�ı�β(����ͷ֮��Ĳ���)����Ϊ���������ָ������¹�����ָ��
  GList t;
  if(!L)
   return NULL;
  CopyGList(t,L->ptr.tp);
  return t; 
}

void InsertFirst_GL(GList &L,GList e)
{//��ʼ����:�����L���ڡ������������������Ԫ�أ�(Ҳ�������ӱ�)��Ϊ�����L�ĵڣ���Ԫ��(��ͷ)
  GList p=(GList)malloc(sizeof(GLNode));
  if(!p)
    exit(OVERFLOW);
  p->tag=LIST;
  p->ptr.hp=e;//L�ı�ͷָ��ָ��e
  p->ptr.tp=L;//L�ı�βָ��ָ��ԭ��L
  L=p; 
}

void DeleteFirst_GL(GList &L,GList &e)
{//��ʼ����:�����L���ڡ� �������:ɾ�������L�ĵڣ���Ԫ��(��ͷ)������e������ֵ
  GList p=L;
  e=L->ptr.hp;
  L=L->ptr.tp;//Lָ��ԭL�ı�β(����ͷ֮��Ĳ���)
  free(p);//�ͷ�p��ָ�ı��� 
}

void Traverse_GL(GList L,void(*visit)(AtomType))
{//���õݹ��㷨���������L
 if(L)
   if(L->tag==ATOM)
     visit(L->atom);
   else
    {
    	Traverse_GL(L->ptr.hp,visit);
    	Traverse_GL(L->ptr.tp,visit);
	 } 
 } 
