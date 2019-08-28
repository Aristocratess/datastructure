#include"c1.h"
typedef int ElemType;
#include"c2-4.h"//线性表的双向链表存储结构
#include"bo2-7.cpp"
#include"func2-2.cpp"
int main()
{
	DuLinkList L;
	int i,n=4;
	Status j;
	ElemType e;
	InitList(L);
	for(i=1;i<=5;i++)
	  ListInsert(L,i,i);//在第i个结点之前插入i
	printf("逆序输出链表:");
	ListTraverseBack(L,print);
	j=GetElem(L,2,e);//将链表的第2个元素赋值给e
	if(j)
	  printf("链表的第2个元素值为%d\n",e);
	else
	  printf("不存在第2个元素");
	i=LocateElem(L,n,equal);
	if(i)
	  printf("等于%d的元素是第%d个\n",n,i);
	else
	  printf("没有等于%d的元素\n",n);
	j=PriorElem(L,n,e);
	if(j)
	  printf("%d的前驱是%d,",n,e);
	else
	  printf("不存在%d的前驱\n",n);
	j=NextElem(L,n,e);
	if(j)
	  printf("%d的后继是%d\你，",n,e);
	else
	  printf("不存在%d的后继\n",n);
	ListDelete(L,2,e);//删除并释放第2个结点
	printf("删除第2个结点，值为%d，其余结点为",e);
	ListTraverse(L,print);//正序输出
	printf("链表的元素个数为%d",ListLength(L));
	printf("链表是否空？%d（1：是 0：否）\n",ListEmpty(L));
	DestroyList(L); 
	printf(""); 
 } 
