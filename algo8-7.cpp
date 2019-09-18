#include"c1.h"
#define N 20
struct Others{
	int order;
};

#define Nil '$'
#include"c8-7.h"
#include"c8-4.h"
#include"c8-8.h"
#include"bo8-5.cpp"
#include"func8-7.cpp"
int main()
{
	DLTree t;
	int i,j=0;
	KeyType k;
	Record* p,r[N];
	FILE* f;
	InitDSTable(t);
	f=fopen("f8-5.txt","r");
	do{
		i=fscanf(f,"%s%d",&r[j].key.ch,&r[j].others.order);
		if(i!=-1)
		{
			r[j].key.num=strlen(r[j].key.ch);
			p=SearchDLTree(t,r[j].key);//在双链键树t中查找关键字串等于r[j].key的记录
			if(!p)
			{
				InsertDSTable(t,&r[j]);
				j++;
			}
			else
			  printf("树t中已存在关键字为%s的记录，故(%s,%d)无法插入。\n",r[j].key.ch,r[j].key.ch,r[j].others.order);	 
		}
	}while(!feof(f)&&j<N);
	fclose(f);
	printf("按关键字符串的顺序遍历树t:\n");
	TraverseDSTable(t,Visit);
	printf("\n请输入待查找记录的关键字符串:");
	InputKey(k.ch);
	k.num=strlen(k.ch);
	p=SearchDLTree(t,k);
	if(p)
	  Visit(p);
	else
	  printf("未找到");
	printf("\n");
	DestroyDSTable(t);
}
