#define N 8//�����ת���Ľ���N��2~9��
typedef int SElemType;//����ջԪ������Ϊ����
#include"c1.h"
#include"c3-1.h"
#include"bo3-1.cpp"
void conversion()
{//�������������һ���Ǹ�ʮ������������ӡ��������ֵ��N������
  SqStack s;
  unsigned n;//�Ǹ�����
  SElemType e;
  InitStack(s);//��ʼ��ջ
  printf("��ʮ��������nת��Ϊ%d�������������룺n(>=0)=",N);
  scanf("%u",&n);//����Ǹ�ʮ��������n
  while(n)
  {
  	Push(s,n%N);//��ջn����N�� ������N���Ƶĵ�λ��
	n=n/N; 
   } 
  while(!StackEmpty(s))
  {
  	Pop(s,e);//����ջ��Ԫ���Ҹ�ֵ��e
	printf("%d",e); 
  }
  printf("\n");
}

int main()
{
	while(1)
	{
		conversion();	
	}
}
