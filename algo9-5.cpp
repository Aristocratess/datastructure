#include<stdio.h>
typedef int KeyType;
typedef int InfoType;
#include"c9-1.h"
#include"c9-2.h"
#include"func9-1.cpp"
#include"func9-3.cpp"
#include"bo9-2.cpp"
int main()
{
	FILE* f;
	SqList m;
	int i;
	f=fopen("f9-1.txt","r");
	fscanf(f,"%d",&m.length);
	for(i=1;i<=m.length;i++)
	   InputFromFile(f,m.r[i]);
    fclose(f);
    printf("ÅÅÐòÇ°:\n");
    Print(m);
    QuickSort(m);
    printf("ÅÅÐòºó:\n");
    Print(m);
}
