#include"c1.h"
typedef int ElemType;
#include"c2-4.h"//���Ա��˫������洢�ṹ
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
	  ListInsert(L,i,i);//�ڵ�i�����֮ǰ����i
	printf("�����������:");
	ListTraverseBack(L,print);
	j=GetElem(L,2,e);//������ĵ�2��Ԫ�ظ�ֵ��e
	if(j)
	  printf("����ĵ�2��Ԫ��ֵΪ%d\n",e);
	else
	  printf("�����ڵ�2��Ԫ��");
	i=LocateElem(L,n,equal);
	if(i)
	  printf("����%d��Ԫ���ǵ�%d��\n",n,i);
	else
	  printf("û�е���%d��Ԫ��\n",n);
	j=PriorElem(L,n,e);
	if(j)
	  printf("%d��ǰ����%d,",n,e);
	else
	  printf("������%d��ǰ��\n",n);
	j=NextElem(L,n,e);
	if(j)
	  printf("%d�ĺ����%d\�㣬",n,e);
	else
	  printf("������%d�ĺ��\n",n);
	ListDelete(L,2,e);//ɾ�����ͷŵ�2�����
	printf("ɾ����2����㣬ֵΪ%d��������Ϊ",e);
	ListTraverse(L,print);//�������
	printf("�����Ԫ�ظ���Ϊ%d",ListLength(L));
	printf("�����Ƿ�գ�%d��1���� 0����\n",ListEmpty(L));
	DestroyList(L); 
	printf(""); 
 } 
