#include"c1.h"
typedef int KeyType;
typedef int InfoType;
#include"c9-1.h"
#define k 5 //k(5)·�鲢������2��ȡ1��
FILE* fp[k+1];//k+1���ļ�ָ��(fp[k]Ϊ���ļ�ָ��),ȫ�ֱ���
typedef int LoserTree[k];
//[1..k-1]�ǰ������ķ�Ҷ�ӽ�㣬[0]����ʤ�ߣ�����ӦҶ�ӵ����
RedType b[k+1];//[0..k-1]�ǰ�������Ҷ��(����),[k]����С�ؼ���
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
		itoa(i,filename,10);//i��Ϊ��ʱ������С�ļ����ļ���
		fp[i]=fopen(filename,"r"); 
	}
	printf("�����������Ĵ��ļ���:");
	scanf("%s",outfile);
	fp[k]=fopen(outfile,"w");
	printf("������ļ�%s�ļ�¼Ϊ:\n",outfile);
	K_Merge(ls);//���ð�������k������С�ļ��еļ�¼�鲢Ϊ1��������ļ�
	printf("\n");
	for(i=0;i<=k;i++)
	  fclose(fp[i]); 
}
