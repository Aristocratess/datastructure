#include"c1.h"
#include"c8-2.h"
typedef int KeyType;
typedef int InfoType;
#include"c9-1.h"
#include"c9-2.h"
#include"func9-1.cpp"
typedef SqList HeapType;
#include"bo9-3.cpp"
int main()
{
	FILE* f;
	SqList m1,m2,m3;
	int i;
	f=fopen("f9-1.txt","r");
	fscanf(f,"%d",&m1.length);
	for(i=1;i<=m1.length;i++)
	   InputFromFile(f,m1.r[i]);
	fclose(f);
	m2=m3=m1;
	printf("ÅÅÐòÇ°:\n");
	Print(m1);
	SelectSort(m1);
	printf("¼òµ¥Ñ¡ÔñÅÅÐòºó:\n");
	Print(m1);
	TreeSort(m2);
	printf("Ê÷ÐÎÑ¡ÔñÅÅÐòºó:\n");
	Print(m2);
	HeapSort(m3);
	printf("¶ÑÅÅÐòºó:\n");
	Print(m3);
 } 
