typedef int SElemType;
#include"c1.h"
#include"c3-1.h"//采用顺序栈
#include"bo3-1.cpp"//利用顺序栈的基本操作
void conversion()
{//对于输入的任意一个非负十进制整数，打印输出与其等值的十六进制数
   SqStack s;
   unsigned n;//非负整数
   SElemType e;
   InitStack(s);
   printf("将十进制整数n转换为十六进制，请输入:n（>=0)=");
   scanf("%u",&n);//输入非负十进制整数n
   while(n)
   {
   	Push(s,n%16);//入栈n除以16的余数
	n=n/16; 
	} 
  while(!StackEmpty(s))
  {
  	Pop(s,e);
  	if(e<=9)
  	  printf("%d",e);//小于等于9的余数，直接输出
	else 
	  printf("%c",e+55);//大于9的余数，输出相应的字符 
  }
  printf("\n");
}
 
int main()
{
	conversion();
}
