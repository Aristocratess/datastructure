#include"c1.h"
#include"c4-2.h"//���Ķѷ���洢�ṹ
#include"bo4-2.cpp"
typedef HString String;
#include"func4-1.cpp"
int main()
{
	int i;
	char c,*p="God bye!",*q="God luck!";
	HString t,s,r;
	InitString(t);
	InitString(s);
	InitString(r);
	StrAssign(t,p);//���ַ���p������ת��HString���ͣ�����t
	printf("��tΪ");
	StrPrint(t);
	printf("����Ϊ%d�����շ�%d(1:�� 0:��)\n",StrLength(t),StrEmpty(t));
	StrAssign(s,q);
	printf("��sΪ");
	StrPrint(s);
	i=StrCompare(s,t);
	if(i<0)
	  c='<';
	else if(i==0)
	  c='=';
	else
	  c='>';
	printf("��s%c��t\n",c);
	Concat(r,t,s);
	printf("��t���Ӵ�s�����Ĵ�rΪ");
	StrPrint(r);
	StrAssign(s,"oo");
	printf("��sΪ");
	StrPrint(s);
	StrAssign(t,"o");
	printf("��tΪ");
	Replace(r,t,s);
	printf("�Ѵ�r�кʹ�t��ͬ���Ӵ��ô�s����");
	StrPrint(r);
	ClearString(s);
	printf("��s��պ󣬴���β%d���շ�%d��1����  0����\n",StrLength(s),StrEmpty(s));
	SubString(s,r,6,4);
	printf("��sΪ�Ӵ�r�ĵ�6���ַ����4���ַ�������Ϊ%d����sΪ",s.length);
	StrPrint(s);
	StrCopy(t,r);
	printf("�ɴ�r���Ƶô�t����tΪ");
	StrPrint(t);
	StrInsert(t,6,s);
	printf("�ڴ�t��di6���ַ�ǰ���봮s�󣬴�tΪ");
	StrPrint(t);
	StrDelete(t,1,5);
	printf("�Ӵ�t�ĵ�1���ַ���ɾ��5���ַ��󣬴�tΪ");
	StrPrint(t);
	printf("%d�ǴӴ�t�ĵ�1���ַ��𣬺ʹ�s��ͬ�ĵ�1���Ӵ���λ��\n",Index(t,s,1));
	printf("%d�ǴӴ�t�ĵ�2���ַ��𣬺ʹ�s��ͬ�ĵ�1���Ӵ���λ��\n",Index(t,s,2));
	DestroyString(t); 
 } 
