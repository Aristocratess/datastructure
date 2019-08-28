#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 10
#define STACK_INCREMENT 2
#define N 8
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW 0
typedef int Status;
typedef int SElemType;
struct SqStack{
	SElemType *base;
	SElemType *top;
	int Stacksize;
}; 

void InitStack(SqStack &S)
{
	S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base)
	  exit(OVERFLOW);
	S.top=S.base;
	S.Stacksize=STACK_INIT_SIZE;
}

void DestroyStack(SqStack &S)
{
	free(S.base);
	S.top=S.base=NULL;
	S.Stacksize=0;
 } 
 
void ClearStack(SqStack &S)
{
	S.top==S.base;
}

Status StackEmpty(SqStack &S)
{
	if(S.top==S.base)
	   return TRUE;
	else
	   return FALSE;
}

int StackLength(SqStack &S)
{
	if(S.top>S.base)
	  return (S.top-S.base);
}

Status GetTop(SqStack S,SElemType &e)
{
	if(S.top>S.base)
	  {
	  	e=*(--S.top);
	  	return OK;
	  }
	else
	   return 0;
}

void Push(SqStack &S,SElemType e)
{
	if(S.top-S.base==S.Stacksize)
	   {
	   	S.base=(SElemType*)realloc(S.base,(S.Stacksize+STACK_INCREMENT)*sizeof(SElemType));
	   	if(!S.base)
	   	  exit(OVERFLOW);
	   	S.top=S.base+S.Stacksize;
	   	S.Stacksize+=STACK_INCREMENT;
		} 
    *(S.top)++=e;
}

Status Pop(SqStack &S,SElemType &e)
{
	if(S.top==S.base)
	  return ERROR;
    e=*--S.top;
	return OK;
}

void StackTraverse(SqStack S,void(*visit)(SElemType))
{
	while(S.top>S.base)
	  visit(*S.base++);
	printf("\n");
}

void conversion()
{
	SqStack s;
	unsigned n;
	SElemType e;
	InitStack(s);
	printf("将十进制整数n转换为%d进制数，请输入：n(>=0)=",N);
	scanf("%u",&n);
	while(n)
	{
		Push(s,n%N);
		n=n/N;
	 } 
	while(!StackEmpty(s))
	{
		Pop(s,e);
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
