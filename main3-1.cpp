#include"c1.h"
typedef int SElemType;//����ջԪ������
#include"c3-1.h"//ջ��˳��洢�ṹ
#include"bo3-1.cpp"
#define ElemType SElemType
#include"func2-2.cpp"
int main()
{
	int j;
	SqStack s;
	SElemType e;
	InitStack(s);
	for(j=1;j<=12;j++)
	  Push(s,j);//��ֵΪj��ջԪ����ջs��
	printf("ջ��Ԫ������Ϊ");
	StackTraverse(s,print);//��ջ�׵�ջ�����ζ�ջs��ÿ��Ԫ�ص���printf()����
	Pop(s,e);//����ջ��Ԫ�أ���ֵ����e
	printf("������ջ��Ԫ��e=%d\n ",e);
	printf("ջ�շ�%d��1���� 0���񣩣� ",StackEmpty(s));
	GetTop(s,e);//���µ�ջ��Ԫ�ظ���e
	printf("ջ��Ԫ��e=%d,ջ�ĳ���Ϊ%d\n",e,StackLength(s));
	ClearStack(s);
	printf("���ջ��ջ�շ�%d��1���� 0����\n",StackEmpty(s));
	DestroyStack(s);//����ջs
	printf("����ջ��s.top=%u,s.base=%u,s.stacksize=%d\n",s.top,s.base,s.stacksize); 
 } 
