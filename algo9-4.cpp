#include"c1.h"
#define N 20
void bubble_sort(int a[],int n)
{//��a��n�������������г���С�������������
  int i,j,t;
  Status change;
  for(i=n-1,change=TRUE;i>=1&&change;--i)//�ɺ�ǰ������change=FALSEʱ��ֹѭ��
  {
  	change=FALSE;
  	for(j=0;j<i;++j)
  	  if(a[j]>a[j+1])
  	  {
  	  	t=a[j];
  	  	a[j]=a[j+1];
  	  	a[j+1]=t;
  	  	change=TRUE;
		}
   } 
}

void Print2(int r[],int n)
{//�������r��ǰn����
  int i;
  for(i=0;i<n;i++)
     printf("%d ",r[i]);
  printf("\n"); 
}

int main()
{
	FILE* f;
	int i=0,j,d[N];
	f=fopen("f9-2.txt","r");
	do{
		j=fscanf(f,"%d",&d[i++]);
	}while(j!=EOF);
	fclose(f);
	i--;
	printf("����ǰ:\n");
	Print2(d,i);
	bubble_sort(d,i);
	printf("�����:\n");
	Print2(d,i);
	
}
