#include"c1.h"
typedef int KeyType;
typedef int InfoType;
#include"c9-1.h"
#define k 5 //k(5)路归并，以下2行取1行
FILE* fp[k+1];//k+1个文件指针(fp[k]为大文件指针),全局变量
typedef int LoserTree[k];
//[1..k-1]是败者树的非叶子结点，[0]中是胜者，存相应叶子的序号
RedType b[k+1];//[0..k-1]是败者树的叶子(外结点),[k]存最小关键字
#define MIN_KEY INT_MIN
#define MAX_KEY INT_MAX
#define M 10
void Print(RedType t)
{
	printf("(%d,%d)",t.key,t.otherinfo);
 } 
#include"bo10-1.cpp"
int main()
{
	LoserTree ls;
	int i;
	char outfile[10],filename[3];
	for(i=0;i<k;i++)
	{
		itoa(i,filename,10);//i作为临时的有序小文件的文件名
		fp[i]=fopen(filename,"r"); 
	}
	printf("请输入排序后的大文件名:");
	scanf("%s",outfile);
	fp[k]=fopen(outfile,"w");
	printf("有序大文件%s的记录为:\n",outfile);
	K_Merge(ls);//利用败者树将k个有序小文件中的记录归并为1个有序大文件
	printf("\n");
	for(i=0;i<=k;i++)
	  fclose(fp[i]); 
}
