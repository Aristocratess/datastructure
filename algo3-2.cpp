typedef int SElemType;
#include"c1.h"
#include"c3-1.h"//����˳��ջ
#include"bo3-1.cpp"//����˳��ջ�Ļ�������
void conversion()
{//�������������һ���Ǹ�ʮ������������ӡ��������ֵ��ʮ��������
   SqStack s;
   unsigned n;//�Ǹ�����
   SElemType e;
   InitStack(s);
   printf("��ʮ��������nת��Ϊʮ�����ƣ�������:n��>=0)=");
   scanf("%u",&n);//����Ǹ�ʮ��������n
   while(n)
   {
   	Push(s,n%16);//��ջn����16������
	n=n/16; 
	} 
  while(!StackEmpty(s))
  {
  	Pop(s,e);
  	if(e<=9)
  	  printf("%d",e);//С�ڵ���9��������ֱ�����
	else 
	  printf("%c",e+55);//����9�������������Ӧ���ַ� 
  }
  printf("\n");
}
 
int main()
{
	conversion();
}
