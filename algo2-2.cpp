#include"c1.h"
typedef int ElemType;
#define Sq
#ifdef Sq
   #include"c2-1.h"//采用线性表的动态分配顺序存储结构
   #include"bo2-1.cpp"
   typedef SqList List;//定义抽象数据类型List为SqList类型
    #define printer print1//ListTraverse()用到不同类型的输出函数
   #else
    #include"c2-2.h"//采用线性表的单链表存储结构
	#include"bo2-2.cpp"
	typedef LinkList List;
	#define printer print//ListTraverse()用到不同类型的输出函数
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
   	ListTraverse(La,printer);//输出表La的内容
	InitList(Lb);
	for(j=1;j<=5;j++)
	  ListInsert(Lb,j,2*j);
	 printf("Lb= ");
	 ListTraverse(Lb,printer);//输出表Lb的内容
	 Union(La,Lb);
	 printf("new La=");
	 ListTraverse(La,printer);
	 ClearList(Lb);
	 for(j=1;j<=7;j++)//在表Lb中重新依次插入数组b[]的7个元素
	   ListInsert(Lb,j,b[j-1]);
	 printf("Lb=");
	 ListTraverse(Lb,printer);
	 MergeList(La,Lb,Lc);
	 printf("Lc=");
	 ListTraverse(Lc,printer);
	 }  
   
