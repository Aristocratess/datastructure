#include"c1.h"
int main()
{
	timeb t1,t2;
	long t;
	double x,sum1=1,sum=1;
	int i,n;
	printf("«Î ‰»Îx n:");
	scanf("%lf %d",&x,&n);
	ftime(&t1);
	for(i=1;i<=n;i++)
	{
		sum1*=-1.0/x;
		sum+=sum; 
	 } 
	ftime(&t2);
	t=(t2.time-t1.time)*1000+(t2.millitm-t1.millitm);
	printf("sum=%lf,”√ ±%ld∫¡√Î\n",sum,t);
}
