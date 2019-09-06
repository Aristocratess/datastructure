#define ClearBiTree InitBiTree
#define DestroyBiTree InitBiTree
void InitBiTree(SqBiTree T)
{//构造空二叉树T。因为T是数组名，故不需要&
   int i;
   for(i=0;i<MAX_TREE_SIZE;i++)
     T[i]=Nil;//初值为空(Nil在主程中定义) 
 } 

void CreateBiTree(SqBiTree T)
{//按层次序输入二叉树中结点的值(字符型或整型)，9构造顺序存储的二叉树T
   int i=0;
   InitBiTree(T);
   #if CHAR//CHAR值为非零，结点类型为字符
   int n;
   char s[MAX_TREE_SIZE];
   printf("请按层序输入结点的值(字符)，空格表示空结点，结点数<=%d:\n",MAX_TREE_SIZE);
   gets(s);//输入字符串
   n=strlen(s);
   for(;i<n;i++)
     T[i]=S[i];
   #else
     printf("请按层序输入结点的值(整型)，0表示空结点，输999结束。结点数<=%d:\n",MAX_TREE_SIZE);
	 while(1)
	 {
	 	scanf("%d",&T[i]);
	 	if(T[i]==999)//输入结束
		  {
		  	T[i]=Nil;
		  	break;
		   } 
		i++;
	  } 
	#endif
	  for(i=1;i<MAX_TREE_SIZE;i++)
	    if(T[i]!=Nil&&T[(i+1)/2-1]==Nil)//此结点不空但无双亲
		{
			printf("出现无双亲的非根结点“form”\n",T[i]);
			exit(OVERFLOW);
		 } 
 } 
 
 Status BiTreeEmpty(SqBiTree T)
 {//初始条件:二叉树T存在。 操作结果: 若T为空二叉树，则返回TRUE，否则返回FALSE
   if(T[0]==Nil)
     return TRUE;
   else
     return FALSE; 
 }
 
 int BiTreeDepth(SqBiTree T)
 {//初始条件：二叉树T存在。  操作结果：返回T的深度
   int i;
   if(T[0]==Nil)
     return 0;
   for(i=MAX_TREE_SIZE-1;i>=0;i--)
     if(T[i]!=Nil)//找到最后一个结点，其序号为i
	   break;
   return (int)(log(i+1)/log(2)+1.1);//序号为i的结点的深度就是树的深度 
 }
 
 Status Root(SqBiTree T,TElemType &e)
 {//初始条件：二叉树T存在
 //操作结果：当T不空，用e返回T的根，返回OK，否则返回ERROR，e无定义
   if(BiTreeEmpty(T))
     return ERROR;
   else
    {
    	e=T[0];
    	return OK;
	 } 
 }
 
 TElemType Value(SqBiTree T,position e)
 {//初始条件：二叉树T存在，e是T中某个结点（的位置）
 //操作结果：返回处于位置e（层，本层序号）的结点的值
   return T[int(pow(2,e.level-1)+e.order-2)]; 
 }
 
 Status Assign(SqBiTree T,position e,TElemType value)
 {//初始条件：二叉树T存在，e是T中某个结点(的位置）
 //操作结果：给处于位置e(层，本层序号)的结点赋新值value
   int i=int(pow(2,e.level-1)+e.order-2);//将层、本层序号转为数组的序号
   if(i!=0&&value!=Nil&&T[(i+1)/2-1]==Nil)//不是根结点，值非空，但双亲为空
     return ERROR;
   else if(value==Nil&&(T[i*2+1]!=Nil||T[i*2+2]!=Nil))
     return ERROR;
   T[i]=value;
   return OK; 
  } 

TElemType Parent(SqBiTree T,TElemType e)
{//初始条件：二叉树T存在，e是T中某个结点
//操作结果：若e是T的非根结点，则返回它的双亲; 否则返回“空”
  int i;
  if(T[0]==Nil)
    return Nil;
  for(i=1;i<=MAX_TREE_SIZE-1;i++)
    if(T[i]==e)
	  return T[(i+1)/2-1];//返回其双亲结点的值
  return Nil; 
}

TElemType LeftChild(SqBiTree T,TElemType e)
{//初始条件：二叉树T存在，e是T中某个结点
//操作结果：返回e的左孩子。若e无左孩子，则返回为"空"
  int i;
  for(i=0;i<=(MAX_TREE_SIZE-2)/2;i++)
     if(T[i]==e)
	   return T[i*2+1];
  return Nil; 
}

TElemType RightChild(SqBiTree T,TElemType e)
{//初始条件：二叉树T存在，e是T中某个结点
//操作结果：返回e的右孩子。若e无右孩子，则返回“空”
  int i;
  if(T[0]==Nil)
    return Nil;
  for(i=1;i<=MAX_TREE_SIZE-1;i++)
    if(T[i]==e&&i%2==0)
	  return T[i-1];//返回e的左兄弟的值
  return Nil; 
 } 
 
TElemType LeftSibling(SqBiTree T,TElemType e)
{//初始条件：二叉树T存在，e是T中某个结点
//操作结果：返回e的左兄弟。若e是T的左孩子或无左兄弟，则返回"空"
  int i;
  if(T[0]==Nil)
    return Nil;
  for(i=1;i<=MAX_TREE_SIZE-1;i++)
    if(T[i]==e&&i%2==0)//找到e且其序号为偶数(是右孩子) 
	  return T[i-1];//返回e的左兄弟的值 
  return Nil; 
 } 
 
TElemType RightSibling(SqBiTree T,TElemType e)
{//初始条件：二叉树T存在，e是T中某个结点
//操作结果：返回e的右兄弟。若e是T的右孩子或无右兄弟，则返回"空"
  int i;
  if(T[0]==Nil)
    return Nil;
  for(i=1;i<=MAX_TREE_SIZE-2;i++)
    if(T[i]==e&&i%2)//找到e且其序号为奇数
	  return T[i+1];
  return Nil; 
 } 
 
void Move(SqBiTree q,int j,SqBiTree T,int i)
{//把从q的j结点开始的子树移为从T的i结点开始的子树
  if(i>=MAX_TREE_SIZE)
    exit(OVERFLOW);
  if(q[2*j+1]!=Nil)
    Move(q,(2*j+1),T,(2*i+1));//把q的j结点的左子树移为T的i结点的左子树
  if(q[2*j+2]!=Nil)
    Move(q,(2*j+2),T,(2*i+2));//把q的j结点的右子树移为T的i结点的右子树
  T[i]=q[j];//把q的j结点移为T的i结点
  q[j]=Nil;//把q的j结点置空 
}

void InsertChild(SqBiTree T,TElemType p,int LR,SqBiTree c)
{//初始条件：二叉树T存在，p是T中某个结点的值，LR为0或1，非空二叉树c与T不相交且右子树为空
 //操作结果：根据LR为0或1，插入c为T中p结点的左或右子树。p结点的原有左或右子树则成为c的右子树
   int j,k;
   for(j=0;j<int(pow(2,BiTreeDepth(T)))-1;j++) 
     if(T[j]==p)
       break;
   k=2*j+1+LR;//k为p的左或右孩子的序号
   if(T[k]!=Nil)
     Move(T,k,c,2);//把从T的k结点开始的子树移为c的右子树
   Move(c,0,T,k);//把树c移为从T的k结点开始的子树 
 } 
 
typedef int QElemType;
#include"c3-2.h"
#include"bo3-2.cpp"
Status DeleteChild(SqBiTree T,position p,int LR)
{//初始条件：二叉树T存在，ｐ指向T中某个结点，LR为０或１
//操作结果：根据LR为0或1，删除T中p所指的左或右子树
  int i;
  Status k=OK;
  LinkQueue q;
  InitQueue(q);//初始化队列，用于存放待删除的结点
  i=(int)pow(2,p.level-1)+p.order-2;//将层、本层序号转为数组的序号
  if(T[i]==Nil)
    return ERROR;
  i=i*2+1+LR;//待删除子树的根结点在数组中的序号
  while(k)
  {
  	if(T[2*i+1]!=Nil)//左结点不空
	  EnQueue(q,2*i+1);
	if(T[2*i+2]!=Nil)
	  EnQueue(q,2*i+2);
	T[i]=Nil;
	k=DeQueue(q,i);//出队结点的序号，其值赋给i，成功（队列不空）返回OK，否则返回ERROR 
   } 
  return OK; 
 } 
 
void(*VisitFunc)(TElemType);
void PreTraverse(SqBiTree T,int e)
{//递归先序遍历二叉树T中序号为e的子树
  VisitFunc(T[e]);
  if(T[2*e+1]!=Nil)//序号为e的结点的左子树不空
    PreTraverse(T,2*e+1);//递归先序遍历树T中序号为e的结点的左子树
  if(T[2*e+2]!=Nil)
    PreTraverse(T,2*e+2); 
}

void PreOrderTraverse(SqBiTree T,void(*Visit)(TElemType))
{//初始条件：二叉树存在，visit是对结点操作的应用函数
//操作结果：先序遍历T，对每个结点调用函数Visit一次且仅一次
  VisitFunc=Visit;
  if(!BiTreeEmpty(T))
    PreTraverse(T,0);//递归先序遍历树T中序号为0的树 
  printf("\n"); 
}

void InTraverse(SqBiTree T,int e)
{//递归中序遍历二叉树T中序号为e的子树
  if(T[2*e+1]!=Nil)//序号为e的结点的左子树不空
    InTraverse(T,2*e+1);//递归中序遍历树T中序号为e的结点的左子树
  VisitFunc(T[e]);
  if(T[2*e+2]!=Nil)//序号为e的结点的右子树不空
    InTraverse(T,2*e+2); 
 } 
 
void InOrderTraverse(SqBiTree T,void(*Visit)(TElemType))
{//初始条件：二叉树存在，Visit是对结点操作的应用函数
//操作结果：中序遍历T，对每个结点调用函数Visit一次且仅一次
  VisitFunc=Visit;
  if(!BiTreeEmpty(T))
    InTraverse(T,0);//递归中序遍历树中序号为0的树
  printf("\n"); 
}

void PostTraverse(SqBiTree T,int e)
{//递归后序遍历二叉树T中序号为e的子树
  if(T[2*e+1]!=Nil)//序号为e的结点的左子树不空
    PostTraverse(T,2*e+1);//递归后序遍历树T中序号为e的结点的左子树
  if(T[2*e+2]!=Nil)
    PostTraverse(T,2*e+2);
  VisitFunc(T[e]);	 
}

void PostOrderTraverse(SqBiTree T,void(*Visit)(TElemType))
{//初始条件：二叉树T存在，Visit是对结点操作的应用函数
//操作结果：后序遍历T，对每个结点调用函数Visit一次仅一次
  VisitFunc=Visit;
  if(!BiTreeEmpty(T))
    PostTraverse(T,0);//递归后序遍历树T中序号为0的树
  printf("\n"); 
 } 
 
void LevelOrderTraverse(SqBiTree T,void(*Visit)(TElemType))
{//层序遍历二叉树
  int i=MAX_TREE_SIZE-1,j;
  while(T[i]==Nil)
    i--;//找到最后一个非空节点的序号 
  for(j=0;j<=i;j++)//从根结点起，按层序遍历二叉树
    if(T[j]!=Nil)
	  Visit(T[j]);//只遍历非空的结点  
  printf("\n"); 
}

void Print(SqBiTree T)
{//逐层、按本层序号输出二叉树T
   int j,k;
   position p;
   TElemType e;
   for(j=1;j<=BiTreeDepth(T);j++)//j为当前层
   {
   	printf("第%d层:",j);
   	p.level=j;//当前结点所在层
    for(k=1;k<=pow(2,j-1);k++)
	{
		p.order=k;//当前结点在本层的顺序
		e=Value(T,p);//该结点的值赋给e
		if(e!=Nil)
		  printf("%d:"form"",k,e); 
	 } 
	 printf("\n");
	} 
}
