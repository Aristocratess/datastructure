#include"c1.h"
#include"c4-1.h"
#include"bo4-1.cpp"
typedef SString String;
#include"func4-1.cpp"
int main()
{
	int i,j;
	Status k;
	char s,c[MAX_STR_LEN+1];//c�а�����������
	SString t,s1,s2;
	printf("�����봮s1:");
	gets(c);//�ɼ��������ַ�����c
	k=StrAssign(s1,c);//���ַ���cתΪSSͬ���Ǹ����ͣ�����s1
	if(!k)
	{
		printf("��������MAX_STR_LEN��=%d)\n",MAX_STR_LEN);
		exit(OVERFLOW);
	 } 
	printf("����β%d,���շ�?%d(1:�� 0:��)\n",StrLength(s1),StrEmpty(s1));
	StrCopy(s2,s1);
	printf("����s1���ɵĴ�Ϊ");
	StrPrint(s2);
	printf("�����봮s2:");
	gets(c);
	StrAssign(s2,c);
	i=StrCompare(s1,s2);
	if(i<0)
	  s='<';
	else if(i==0)
	  s='=';
	else
	  s='>';
	printf("��s1���Ӵ�s2�õ��Ĵ�tΪ");
	StrPrint(t);
	if(k==FALSE)
	  printf("��t�ɽض�\n");
	ClearString(s1);
	printf("��պ󣬴�S1Ϊ");
	StrPrint(s1);//�����s1
	printf("����Ϊ%d,���շ�?%d(1:��  0:��)\n",StrLength(s1),StrEmpty(s1));
	printf("��t���Ӵ����������Ӵ�����ʼλ�ã��Ӵ�����:");
	scanf("%d,%d",&i,&j);
	k=SubString(s2,t,i,j);//��s2Ϊ��t�ĵ�i���ַ��𣬳���Ϊj���Ӵ�
	if(k)
	{
		printf("�Ӵ�s2Ϊ");
		StrPrint(s2);//�����s2 
	 } 
	printf("�Ӵ�t�ĵ�pos���ַ���ɾ��len���ַ���������pos,len��");
	scanf("%d,%d",&i,&j);
	StrDelete(t,i,j);//����t�ĵ�i���ַ����j���ַ�ɾ��
	printf("ɾ����Ĵ�tΪ");
	StrPrint(t);
	i=StrLength(s2)/2;//iΪ��s2���ȵ�һ��ȡ�� 
	StrInsert(s2,i,t); //�ڴ�s2�ĵ�i���ַ�֮ǰ���봮t
	printf("�ڴ�s2�ĵ�%d���ַ�֮ǰ���봮t�󣬴�s2Ϊ",i);
	StrPrint(s2);
	i=Index1(s2,t,1);//�Ӵ�s2�ĵ�1���ַ�����Ҵ�t
	printf("s2�ĵ�%d���ַ����t��һ��ƥ��\n",i);
	SubString(t,s2,1,1);//��tΪ��s2�ĵ�1���ַ�
	printf("��tΪ");
	StrPrint(t);
	Concat(s1,t,t);
	printf("��s1Ϊ");
	StrPrint(s1);
	k=Replace(s2,t,s1);//������s2�е����в��ص��Ĵ�t���ô�s1�滻
	if(k)
	{
		printf("�ô�s1ȡ����s2�кʹ�t��ͬ�Ĳ��ص��Ĵ��󣬴�s2Ϊ");
		StrPrint(s2);
	 } 
	 DestroyString(s2);//���ٲ�������ղ���������ͬ 
}
