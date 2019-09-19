#include"c1.h"
typedef int KeyType;
typedef int InfoType;
#include"c9-1.h"
#include"c9-3.h"
typedef SLinkListType SqList;
#include"func9-2.cpp"
void PrintL(SLinkListType L)
{
	int i;
	for(i=0;i<=L.length;i++)
	   printf("i=%d key=%d ord=%d next=%d\n",i,L.r[i].rc.key,L.r[i].rc.otherinfo,L.r[i].next);
}

void InputFromFile(FILE* f,RedType &c)
{
	fscanf(f,"%d%d",&c.key,&c.otherinfo);
}

void CreatTableFromFile(SLinkListType &SL,FILE* f)
{//由数据文件f建立未排序的顺序表SL(next域不起作用)
  int i;
  fscanf(f,"%d",&SL.length);
  for(i=1;i<=SL.length;i++) 
	InputFromFile(f,SL.r[i].rc);
}

void MakeTableSorted(SLinkListType &SL)
{//使无序的顺序表SL成为有序的静态循环链表
  int i,p,q;
  SL.r[0].rc.key=INT_MAX;
  SL.r[0].next=0;
  for(i=1;i<=SL.length;i++)
  {
  	q=0;
  	p=SL.r[0].next;//p指向静态链表的第1个元素
	while(SL.r[p].rc.key<=SL.r[i].rc.key)
	{//p所指元素的关键字不大于待插记录的关键字(上行的"="使排序方法是稳定的)
	  q=p;
	  p=SL.r[p].next;
	 } //p所指元素的关键字大于待插记录的关键字，q所指元素的关键字不大于待插记录的关键字
	SL.r[q].next=i;
	SL.r[i].next=p; 
   } 
}

void Arrange(SLinkListType &SL)
{//根据静态链表SL中各结点的指针值调整记录位置，使得SL成为非递减有序的顺序表
  int i,p,q;
  SLNode t;
  p=SL.r[0].next;
  for(i=1;i<SL.length;++i)
  {//SL.r[1..i-1]中记录已按关键字有序排列，第i个记录在SL中的当前位置应不小于i
    while(p<i)
	  p=SL.r[p].next;
	q=SL.r[p].next;
    if(p!=i)
	{
		t=SL.r[p];
		SL.r[i]=t;
		SL.r[i].next=p;//指向被移走的记录，[i]已排好序，使得以后可由while循环找回p所指记录 
	 } 
	 p=q; 
   } 
}

int main()
{
	FILE* f;
	int* adr,i;
	SLinkListType m1,m2;
	f=fopen("f9-1.txt","r");
	CreatTableFromFile(m1,f);
	fclose(f);
	printf("m1排序前:\n");
	PrintL(m1);
	MakeTableSorted(m1);
	m2=m1;
	printf("m1、m2链式有序后:\n");
	PrintL(m1);
	Arrange(m1);
	printf("m1排序后:\n");
	PrintL(m1);
	adr=(int*)malloc((m2.length+1)*sizeof(int));
	Sort(m2,adr);
	for(i=1;i<=m2.length;i++)
	{
		printf("adr[%d]=%d",i,adr[i]);
		if(i%4==0)
		printf("\n");
	}
	Rearrange(m2,adr);
	printf("m2排序后:\n");
	PrintL(m2);
	free(adr);
}
