#define N 8//定义待转换的进制N（2~9）
typedef int SElemType;//定义栈元素类型为整型
#include"c1.h"
#include"c3-1.h"
#include"bo3-1.cpp"
void conversion()
{//对于输入的任意一个非负十进制整数，打印输出与其等值的N进制数
  SqStack s;
  unsigned n;//非负整数
  SElemType e;
  InitStack(s);//初始化栈
  printf("将十进制整数n转换为%d进制数，请输入：n(>=0)=",N);
  scanf("%u",&n);//输入非负十进制整数n
  while(n)
  {
  	Push(s,n%N);//入栈n除以N的 余数（N进制的低位）
	n=n/N; 
   } 
  while(!StackEmpty(s))
  {
  	Pop(s,e);//弹出栈顶元素且赋值给e
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
