#include"c1.h"
typedef int ElemType;
#define Sq
#ifdef Sq
   #include"c2-1.h"//�������Ա�Ķ�̬����˳��洢�ṹ
   #include"bo2-1.cpp"
   typedef SqList List;//���������������ListΪSqList����
    #define printer print1//ListTraverse()�õ���ͬ���͵��������
   #else
    #include"c2-2.h"//�������Ա�ĵ�����洢�ṹ
	#include"bo2-2.cpp"
	typedef LinkList List;
	#define printer print//ListTraverse()�õ���ͬ���͵��������
   #endif
   #include"func2-2.cpp"
   #include"func2-1.cpp"
   void main()
   {
   	List La,Lb,Lc;
   	int j,b[7]={2,6,8,9,11,15,20};
   	InitList(La);
   	for(j=1;j<=5;j++)
   	 ListInsert(La,j,j);
   	printf("La= ");
   	ListTraverse(La,printer);//�����La������
	InitList(Lb);
	for(j=1;j<=5;j++)
	  ListInsert(Lb,j,2*j);
	 printf("Lb= ");
	 ListTraverse(Lb,printer);//�����Lb������
	 Union(La,Lb);
	 printf("new La=");
	 ListTraverse(La,printer);
	 ClearList(Lb);
	 for(j=1;j<=7;j++)//�ڱ�Lb���������β�������b[]��7��Ԫ��
	   ListInsert(Lb,j,b[j-1]);
	 printf("Lb=");
	 ListTraverse(Lb,printer);
	 MergeList(La,Lb,Lc);
	 printf("Lc=");
	 ListTraverse(Lc,printer);
	 }  
   
