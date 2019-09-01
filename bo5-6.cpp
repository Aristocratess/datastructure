#include"func5-3.cpp"
int InitGList(GListl &L)
{
	L=(GListl)malloc(sizeof(GLNodel));
	L->tag=LIST;//给表头结点的标志域赋值
	L->hp=L->tp=NULL;//给表头结点的指针域赋值 
 } 

void Create(GListl &L,SString S)
{//由广义表的书写形式串S创建子表L，CreateGlist()调用
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
   	L->tag=ATOM;//给结点的标志域赋值 
   	L->atom=S[1];//给结点的值域赋值 
	} 
   else
   {
   	L->tag=LIST;
	SubString(sub,S,2,StrLength(S)-2);
	//脱外层括号(去掉第1个字符(左括号)和最后1个字符(右括号))给串sub
	server(sub,hsub);//从sub中分离出表头串hsub(外层逗号之前的),表尾串赋给sub
	Create(L->hp,hsub);
	p=L->hp;//p指向子表的表头元素
	while(!StrEmpty(sub))
	{
		sever(sub,hsub);//从sub中分离出表头串hsub
		Create(p->tp,hsub);
		p=p->tp;//p向后移 
	 } 
	 }  
	L->tp=NULL; 
 } 
 
void CreateGList(GListl &L,SString S)
{//采用扩展线性链表存储结构，由广义表的书写形式串S创建广义表L。L最初为为空的广义表
    SString emp,sub,hsub;
    GListl p;
	StrAssign(emp,"()");
	if(!StrCompare(S,emp))
	  InitGList(L);
	else
	{
		SubString(sub,S,2,StrLength(S)-2);
		//脱外层括号(去掉第1个字符（左括号）和最后一个字符（右括号）)给串sub
		server(sub,hsub);//从sub中分离出表头串hsub(外层逗号之前的)，表尾串赋给sub
		Create(L->hp,hsub);
		p=L->hp;
		while(!StrEmpty(sub))//表尾不空，则继续创建子表
		{
			server(sub,hsub);//从sub中分离出最前面的串给hsub，其余部分赋给sub
			Create(p->tp,hsub);
			p=p->tp; 
		 } 
	p->tp=NULL;	 
	}
}

void DestroyGList(GListl &L)
{//初始条件：广义表L存在  操作结果:销毁广义表L
  GListl ph,pt;
  if(L)
  {
  	//由ph和pt接替L的两个指针
	if(L->tag)//是子表
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
{//初始条件：广义表L存在。 操作结果:由广义表L复制得到广义表T
  T=NULL;
  if(L)
  {
  	T=(GListl)malloc(sizeof(GLNodel));
  	if(!T)
  	  exit(OVERFLOW);
  	T->tag=L->tag;//复制枚举变量
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
{//初始条件: 广义表L存在。  操作结果：由广义表L复制得到广义表T
  int len=0;
  GListl p=L->hp;//p指向第1个yuans
  while(p)
  {
  	len++;
  	p=p->tp;
   };
  return len; 
}

int GListDepth(GListl L)
{//初始条件：广义表L存在。  操作结果：求广义表L的深度
    int max=0,dep;
    GListl p;
	if(L->tag==LIST&&!L->hp)
	  return 1;//空表深度为1
	else if(L->tag==ATOM)
	  return 0;//单原子表深度为0，只会出现在递归调用中
	else//求一般表的深度
	  for(p=L->hp;p;p=p->tp)
	  {
	  	dep=GListDepth(p);//求以p为头指针的子表深度
		if(dep>max)
		 max=dep; 
	   } 
	return max+1;//非空表的深度是各元素的深度的最大值加1 
}

Status GListEmpty(GListl L)
{//初始条件:广义表L存在。 操作结果：判定广义表L是否为空
  if(!L->hp)
    return OK;
  else
    return ERROR; 
 } 
 
GListl GetHead(GListl L)
{//初始条件:广义表L存在。  操作结果:生成广义表L的表头元素，返回指向这个元素的指针
   GListl h,p;
   if(!L->hp)
     return NULL;
   p=L->hp->tp;
   L->hp->tp=NULL;//截去L的表尾部分
   CopyGList(h,L->hp);//将表头元素复制给h
   L->hp->tp=p;//恢复L的表尾 
}

GListl GetTail(GListl L)
{//初始条件：广义表L存在。  操作结果：将L的表尾生成广义表，返回指向这个新广义表的指针
  GListl t;
  InitGList(t);
  if(L->hp)
    CopyGList(t->hp,L->hp->tp);//将L的表尾复制给t的表头
  return t; 
}

void InsertFirst_GL(GListl &L,GListl e)
{//初始条件:广义表L存在。 操作结果:插入元素e(也可能是子表)作为L的第1个元素(表头)
  GListl p=L->hp;//p指向广义表L的第1个元素
  L->hp=e;//广义表L的头指针指向e
  e-tp=p;//e(只是1个元素，其尾指针必为NULL)的尾指针指向L原来的第１个元素 
}

void DeleteFirst_GL(GListl &L,GListl &e)
{//初始条件：广义表L存在。 操作结果：删除广义表L的第1个元素，并用e返回其指针
  e=L->hp;//e指向L的第1个元素
  if(L->hp)//L非空
  {
  	 L->hp=e->tp;//L的头指针指向原第2个元素
	 e->tp=NULL;//e的尾指针设为空 
   } 
 } 
 
void Travese_GL(GListl L,void(*visit)(AtomType))
{//利用递归算法遍历广义表L
  if(L)
  {
  	if(L->tag==ATOM)
  	  visit(L->atom);
  	else
  	  Traverse_GL(L->hp,visit);
  	Traverse_GL(L->tp,visit);
   } 
 } 
 
 
