#include"c1.h"
#include"c8-2.h"//��������ֵ�͹ؼ��ֱȽϵ�Լ��
typedef int KeyType;
typedef int InfoType;
#include"c9-1.h"//��¼���������� 
#include"c9-2.h"//˳������͵Ĵ洢�ṹ 
#include"bo9-1.cpp"//˳����������ĺ��� 
#include"func9-1.cpp"//���׵������������ 
#define k 5//k·�鲢 
#define N 3 //��ÿ��С�ļ������N������
int main()
{
	SqList m;//˳������ڶ�С�ļ������ڲ�����
	FILE* f,*g;
	char filename[3];
	int i,j;
	f=fopen("f10-1.txt","r");
	for(i=0;i<k;i++)//�����ļ�f10-1.txt�����ݷֳ�k��
	{
		for(j=1;j<=N;j++)//ÿ��N������ 
		  InputFromFile(f,m.r[j]);
		m.length=N;
		BInsertSort(m);
		itoa(i,filename,10);//i��Ϊ��ʱ������С�ļ����ļ���
		g=fopen(filename,"w");
		printf("�������ļ�%s������Ϊ:",filename);
		Print(m);
		for(j=1;j<=N;j++)//���ν��������m.r[j]д��С�ļ�0,1,...,k-1
		  fprintf(g,"%d %d\n",m.r[j].key,m.r[j].otherinfo);
		fclose(g);//���ιر�С�ļ�0,1,...,k-1 
	 } 
	 fclose(f);//�ر�δ����Ĵ��ļ�f10-1.txt 
 } 
