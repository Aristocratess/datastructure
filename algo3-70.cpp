#include<stdio.h>
int Ack(int M,int N)
{
	int top=0,m,n;
	int stack[10000][4]={{M,N}};//记录信息m,n,Ack(m,n)，跳转出口种类
	while(true)
	{
		m=stack[top][0];
		n=stack[top][1];
		if(m==0)
		  stack[top][2]=n+1;
		else if(n==0)
		{
			top++;
			stack[top][0]=m-1;
			stack[top][1]=1;
			stack[top][3]=1;
			continue;
			l1:
			stack[top][2]=stack[top+1][2];
		}
		else
		{
			top++;
			stack[top][0]=m-1;
			top++;
			stack[top][0]=m;
			stack[top][1]=n-1;
			stack[top][3]=2;
			continue;
			l2:
			stack[top][1]=stack[top+1][2];
			stack[top][3]=3;
			continue;
			l3:
			stack[top][2]=stack[top+1][2];
		}
		if(top==0)
		   break;
		top--;
		switch(stack[top+1][3])
		{
			case 1:goto l1;
			case 2:goto l2;
			case 3:goto l3; 
		}
	 } 
	 return stack[0][2];
}

int main()
{
	int m,n;
	printf("请输入m，n:");
	scanf("%d %d",&m,&n);
	printf("Ack(%d,%d)=%d\n",m,n,Ack(m,n));
}
