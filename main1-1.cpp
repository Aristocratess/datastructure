#include "c1.h"
typedef int Elemtype;
#include"c1-1.h"
#include"bo1-1.cpp"
#include"func1-1.cpp"
int main()
{
	Triplet T;
	Elemtype m;
	Status i;
	i=InitTriplet(T,5,7,9);
	printf("���ó�ʼ��������u=%d��1���ɹ�����T��3��ֵΪ",i);
	PrintT(T);
	i=Get(T,2,m);
	if(i==OK)
	{
		printf("T�ĵ�2��ֵΪ");
		PrintE(m);//���m(=T[1]) 
	}
	i=Put(T,2,6);
	if(i==OK)
	{
		printf("��T�ĵ�2��ֵ��Ϊ6��T��3��ֵΪ");
		PrintT(T);
	}
	i=IsAscending(T);
	printf("���ò�������ĺ�����i=%d��0���� 1���ǣ�\n",i);
	i=IsDescending(T);
	printf("���ò��Խ���ĺ�����i=%d��0���� 1����)\n",i);
	if((i=Max(T,m))==OK)
	{
		printf("T�е����ֵΪ");
		PrintE(m);//������ֵm 
	}
	if((i=Min(T,m))==OK)
	{
		printf("T�е���СֵΪ��");
		PrintE(m);//�����Сֵm 
	}
	DestroyTriplet(T);//����Ҳ���Բ����ط���ֵ
	printf("����T��T=%u\n",T); 
}
