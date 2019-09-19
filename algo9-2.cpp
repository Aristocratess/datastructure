#include"c1.h"
typedef int KeyType;
typedef int InfoType;
#include"c9-1.h"
#include"c9-3.h"
typedef SLinkListType SqList;
#include"func9-2.cpp"
void PrintL(SLinkListType L)
{
	int i;
	for(i=0;i<=L.length;i++)
	   printf("i=%d key=%d ord=%d next=%d\n",i,L.r[i].rc.key,L.r[i].rc.otherinfo,L.r[i].next);
}

void InputFromFile(FILE* f,RedType &c)
{
	fscanf(f,"%d%d",&c.key,&c.otherinfo);
}

void CreatTableFromFile(SLinkListType &SL,FILE* f)
{//�������ļ�f����δ�����˳���SL(next��������)
  int i;
  fscanf(f,"%d",&SL.length);
  for(i=1;i<=SL.length;i++) 
	InputFromFile(f,SL.r[i].rc);
}

void MakeTableSorted(SLinkListType &SL)
{//ʹ�����˳���SL��Ϊ����ľ�̬ѭ������
  int i,p,q;
  SL.r[0].rc.key=INT_MAX;
  SL.r[0].next=0;
  for(i=1;i<=SL.length;i++)
  {
  	q=0;
  	p=SL.r[0].next;//pָ��̬����ĵ�1��Ԫ��
	while(SL.r[p].rc.key<=SL.r[i].rc.key)
	{//p��ָԪ�صĹؼ��ֲ����ڴ����¼�Ĺؼ���(���е�"="ʹ���򷽷����ȶ���)
	  q=p;
	  p=SL.r[p].next;
	 } //p��ָԪ�صĹؼ��ִ��ڴ����¼�Ĺؼ��֣�q��ָԪ�صĹؼ��ֲ����ڴ����¼�Ĺؼ���
	SL.r[q].next=i;
	SL.r[i].next=p; 
   } 
}

void Arrange(SLinkListType &SL)
{//���ݾ�̬����SL�и�����ָ��ֵ������¼λ�ã�ʹ��SL��Ϊ�ǵݼ������˳���
  int i,p,q;
  SLNode t;
  p=SL.r[0].next;
  for(i=1;i<SL.length;++i)
  {//SL.r[1..i-1]�м�¼�Ѱ��ؼ����������У���i����¼��SL�еĵ�ǰλ��Ӧ��С��i
    while(p<i)
	  p=SL.r[p].next;
	q=SL.r[p].next;
    if(p!=i)
	{
		t=SL.r[p];
		SL.r[i]=t;
		SL.r[i].next=p;//ָ�����ߵļ�¼��[i]���ź���ʹ���Ժ����whileѭ���һ�p��ָ��¼ 
	 } 
	 p=q; 
   } 
}

int main()
{
	FILE* f;
	int* adr,i;
	SLinkListType m1,m2;
	f=fopen("f9-1.txt","r");
	CreatTableFromFile(m1,f);
	fclose(f);
	printf("m1����ǰ:\n");
	PrintL(m1);
	MakeTableSorted(m1);
	m2=m1;
	printf("m1��m2��ʽ�����:\n");
	PrintL(m1);
	Arrange(m1);
	printf("m1�����:\n");
	PrintL(m1);
	adr=(int*)malloc((m2.length+1)*sizeof(int));
	Sort(m2,adr);
	for(i=1;i<=m2.length;i++)
	{
		printf("adr[%d]=%d",i,adr[i]);
		if(i%4==0)
		printf("\n");
	}
	Rearrange(m2,adr);
	printf("m2�����:\n");
	PrintL(m2);
	free(adr);
}
