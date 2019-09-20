#include"c1.h"
#include"c8-2.h"//对两个数值型关键字比较的约定
typedef int KeyType;
typedef int InfoType;
#include"c9-1.h"//记录的数据类型 
#include"c9-2.h"//顺序表类型的存储结构 
#include"bo9-1.cpp"//顺序表插入排序的函数 
#include"func9-1.cpp"//配套的输入输出函数 
#define k 5//k路归并 
#define N 3 //设每个小文件最多有N个数据
int main()
{
	SqList m;//顺序表，用于对小文件进行内部排序
	FILE* f,*g;
	char filename[3];
	int i,j;
	f=fopen("f10-1.txt","r");
	for(i=0;i<k;i++)//将大文件f10-1.txt的数据分成k组
	{
		for(j=1;j<=N;j++)//每组N个数据 
		  InputFromFile(f,m.r[j]);
		m.length=N;
		BInsertSort(m);
		itoa(i,filename,10);//i作为临时的有序小文件的文件名
		g=fopen(filename,"w");
		printf("有序子文件%s的数据为:",filename);
		Print(m);
		for(j=1;j<=N;j++)//依次将已排序的m.r[j]写入小文件0,1,...,k-1
		  fprintf(g,"%d %d\n",m.r[j].key,m.r[j].otherinfo);
		fclose(g);//依次关闭小文件0,1,...,k-1 
	 } 
	 fclose(f);//关闭未排序的大文件f10-1.txt 
 } 
