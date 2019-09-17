#include"c1.h"
#include"func8-3.cpp"
#include"c8-1.h"
#include"c8-2.h"
#include"bo8-1.cpp"
typedef ElemType TElemType;
#include"c6-2.h"
#include"bo6-2.cpp"
#define N 100
Status SecondOptimal(BiTree &T,ElemType R[],int sw[],int low,int high)
{//由有序表R[low..high]及其累计权值表sw(其中sw[0]==0)递归构造次优查找树T
  int j,i=low;
  double dw=sw[high]+sw[low-1];
  double min=fabs(sw[high]-sw[low]);
  for(j=low+1;j<=high;++j)
     if(fabs(dw-sw[j]-sw[j-1])<min)
	 {
	 	i=j;
	 	min=fabs(dw-sw[j]-sw[j-1]);
	  } 
	if(!(T=(BiTree)malloc(sizeof(BiTNode))))
	   return ERROR;
	T->data=R[i];
	if(i==low)
	  T->lchild=NULL;
	else
	  SecondOptimal(T->lchild,R,sw,low,i-1);
	if(i==high)
	  T->rchild=NULL;
	else
	  SecondOptimal(T->rchild,R,sw,i+1,high);
	return OK;
 } 
 
void FindSW(int sw[],SSTable ST)
{//按照有序表ST中各数据元素的Weight域求累计权值数组sw，CreateSOSTree()调用
  int i;
  sw[0]=0;//置边界值
  printf("\nsw=0");
  for(i=1;i<=ST.length;i++)//由小到大计算累计权值sw[i]并输出 
  {
  	sw[i]=sw[i-1]+ST.elem[i].weight;//累计权值[i]=累计权值[i-1]+[i]项权值
	printf("%5d",sw[i]); 
   } 
}

typedef BiTree SOSTree;
void CreateSOSTree(SOSTree &T,SSTable ST)
{//由有序表ST构造一颗次优查找树T。ST的数据元素含有权域weight。
  int sw[N+1];
  if(ST.length==0)
     T=NULL;
  else
  {
  	FindSW(sw,ST);
  	SecondOptimal(T,ST.elem,sw,1,ST.length);
  	//由有序表ST[1..ST.length]及其累计权值表sw(其中sw[0]==0)递归构造次优查找树T 
   } 
}

Status Search_SOSTree(SOSTree &T,KeyType key)
{//在次优查找树T中查找主关键字等于key的元素。找到则返回OK，T指向该元素
   while(T)
      if(T->data.key==key)
	     return OK;
	  else if(T->data.key>key)
	     T=T->lchild;
	  else
	     T=T->rchild;
	return FALSE; 
}

int main()
{
	SSTable st;
	SOSTree t;
	Status i;
	KeyType s;
	Creat_OrdFromFile(st,"f8-3.txt");
	printf("     ");
	Traverse(st,Visit);
	CreateSOSTree(t,st);
	printf("\n请输入待查找的字符:");
	InputKey(s);
	i=Search_SOSTree(t,s);
	if(i)
	  printf("%c的权值是%d\n",s,t->data.weight);
	else
	  printf("表中不存在次字符\n");
	DestroyBiTree(t); 
}
