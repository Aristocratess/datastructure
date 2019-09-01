#include"func5-3.cpp"
void InitGList(GList &L)
{
	L=NULL;
}

void CreateGList(GList &L,SString S)
{//采用头尾链表存储结构，由广义表的书写形式串S创建广义表L。设emp="()"
  SString sub,hsub,emp;
  GList p,q;
  StrAssign(emp,"()");
  if(!StrCompare(S,emp))
    L=NULL;
  else
   {if(!(L=(GList)malloc(sizeof(GLNode))))
      exit(OVERFLOW);
    if(StrLength(S)==1)//S为单原子，这种情况只会出现在递归调用中
	{
		L->tag=ATOM;//创建单原子广义表 
		L->atom=S[1];//单原子的值为字符型 
	 } 
	else{
		L->tag=LIST;//L是子表 
		p=L;//p也指向子表
		SubString(sub,S,2,StrLength(S)-2);
		//脱外层括号(去掉第1个字符（左括号）和最后1个字符(右括号))给串sub
		do
		{
			sever(sub,hsub);//从sub中分离出表头串给hsub，其余部分(表尾)给sub
			CreateGList(p->ptr.hp,hsub);//递归创建表头串表示的子表
			q=p;//q指向p所指结点
			if(!StrEmpty(sub))
			{
				if(!(p=(GLNode*)malloc(sizeof(GLNode))))
				    exit(OVERFLOW);
			    p->tag=LIST;//p是子表
				q->ptr.tp=p;//p所指结点接在q所指结点之后，形成q的下一个结点 
			 } 
		 } while(!StrEmpty(sub));
		 q->ptr.tp=NULL;//设置最后一个表尾指针为空 
	} 
	} 
}

void DestroyGList(GList &L)
{//销毁广义表L
  GList q1,q2;
  if(L)
  {if(L->tag==LIST)
  {
  	q1=L->ptr.hp;//q1指向表头
	q2=L->ptr.tp;//q2指向表尾(除表头之外的其余部分)
	DestroyGList(q1);
	DestroyGList(q2); 
  }
  free(L);//释放L所指的存储空间(无论L是表结点还是原子结点)
  L=NULL;//L不指向任何存储单元 
   } 
 } 
 
void CopyGList(GList &T,GList L)
{//采用头尾链表存储结构，由广义表L复制得到广义表T
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
      	CopyGList(T->ptr.hp,L->ptr.hp);//递归复制表头子表
		CopyGList(T->ptr.tp,L->ptr.tp);
	  }
	 } 
 } 
 
 int GListLength(GList L)
 {//返回广义表的长度，即元素个数
    int len=0;
	while(L)
	{
		L=L->ptr.tp;
		len++;
	 } 
	return len;
 }
 
 int GListDepth(GList L)
 {//采用头尾链表存储结构，求广义表L的深度
   int dep,max=0;
   GList pp;
   if(!L)
     return 1;
   if(L->tag==ATOM)
      return 0;
   for(pp=L;pp;pp=pp->ptr.tp)
    {
    	dep=GListDepth(pp->ptr.hp);//递归求以pp->ptr.hp为头指针的子表深度
		if(dep>max)
		  max=dep;//max存本层子表深度的最大值 
	 } 
	return max+1;//非空表的深度是各元素的深度的最大值加1 
 }
 
 Status GListEmpty(GList L)
 {//判定广义表是否为空
   if(!L)
     return TRUE;
   else
     return FALSE; 
 }
 
GList GetHead(GList L)
{//生成广义表L的表头元素，返回指向这个元素的指针
  GList h;
  if(!L)
    return NULL;
  CopyGList(h,L->ptr.hp);
  return h; 
}

GList GetTail(GList L)
{//将广义表L的表尾(除表头之外的部分)生成为广义表，返回指向这个新广义表的指针
  GList t;
  if(!L)
   return NULL;
  CopyGList(t,L->ptr.tp);
  return t; 
}

void InsertFirst_GL(GList &L,GList e)
{//初始条件:广义表L存在。　　操作结果：插入元素ｅ(也可能是子表)作为广义表L的第１个元素(表头)
  GList p=(GList)malloc(sizeof(GLNode));
  if(!p)
    exit(OVERFLOW);
  p->tag=LIST;
  p->ptr.hp=e;//L的表头指针指向e
  p->ptr.tp=L;//L的表尾指针指向原表L
  L=p; 
}

void DeleteFirst_GL(GList &L,GList &e)
{//初始条件:广义表L存在。 操作结果:删除广义表L的第１个元素(表头)，并用e返回其值
  GList p=L;
  e=L->ptr.hp;
  L=L->ptr.tp;//L指向原L的表尾(除表头之外的部分)
  free(p);//释放p所指的表结点 
}

void Traverse_GL(GList L,void(*visit)(AtomType))
{//利用递归算法遍历广义表L
 if(L)
   if(L->tag==ATOM)
     visit(L->atom);
   else
    {
    	Traverse_GL(L->ptr.hp,visit);
    	Traverse_GL(L->ptr.tp,visit);
	 } 
 } 
