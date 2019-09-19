#include"c1.h"
typedef char KeysType;
typedef int InfoType;
#include"c9-4.h"
typedef SLList SqList;
#define length recnum
#include"func9-2.cpp"
void MadeListFromFile(SLList &L,FILE* f)
{//ͨ���ļ�f����˳���L
  int i;
  fscanf(f,"%d",&L.recnum);
  for(i=1;i<=L.recnum;i++)
    fscanf(f,"%s%d",&L.r[i].keys,&L.r[i].otheritems);
  L.keynum=strlen(L.r[1].keys); 
}

int ord(char c)
{//���عؼ���c����� 
	return c-'0';
}

void Distribute(SLCell r[],int i,ArrType f,ArrType e)
{//��̬����L��r���м�¼�Ѱ�(keys[i-1 ],...,keys[0])����keys[i](keys[0]�����λ�ؼ��֣�����RADIX���ӱ�ʹͬһ�ӱ��м�¼��keys[i]��ͬ
//f[0..RADIX-1]��e[0..RADIX-1]�ֱ�ָ����ӱ��е�һ�������һ����¼
  int j,p;
  for(j=0;j<RADIX;++j)
  {
  	j=ord(r[p].keys[i]);//��ǰ��¼�ĵ�iλ�ؼ��ֵ���ţ����½���ǰ��¼����Ų����ӱ�
	if(!f[j])
	  f[j]=p;//��ͷָ��ǰ��¼
	else
	  r[e[j]].next=p;//�޸�ԭ�ӱ�[j]�ı�β��¼��next��ָ��ǰ��¼
	e[j]=p; 
   } 
   printf("\nf[j]=");
   for(j=0;j<RADIX;++j)
     if(f[j])
       printf("%3d",e[j]);
     else
       printf("%3d",0);
   printf("\n");
}

int succ(int i)
{
  return ++i;	
}

void Collect(SLCell r[],ArrType f,ArrType e)
{//���㷨��keys[i]��С����ؽ�f[0..RADIX-1]��ָ���ӱ��������ӳ�һ������e[0..RADIX-1]Ϊ���ӱ��βָ��
  int j,t;
  for(j=0;!f[j];j=succ(j));//�ҵ�1���ǿ��ӱ�[j],succΪ���̺���
  r[0].next=f[j];//r[0].nextָ���1���ǿ��ӱ�[j]�ĵ�j��Ԫ��
  t=e[j];//tָ���1���ǿ��ӱ�[j]�ı�βԪ��
  while(j<RADIX-1)
  {
  	for(j=succ(j);j<RADIX-1&&!f[j];j=succ(j));//����һ���ǿ��ӱ�
	if(f[j])
	{
		r[t].next=f[j];
		t=e[j];//tָ���µı�βԪ�� 
	 } 
   } 
   r[t].next=0; 
}

void Print2(SLList L)
{//��������������̬����
  int i=0;
  printf("keynum=%d recnum=%d i=%d next=%d\n",L.keynum,L.recnum,i,L.r[i].next);
  for(i=1;i<=L.recnum;i++)
     printf("i=%d keys=%s otheritems=%d next=%d\n",i,L.r[i].keys,L.r[i].otheritems,L.r[i].next);
}

void PrintLL(SLList L)
{//������˳�������̬����L
  int i=L.r[0].next;
  while(i)
  {
  	printf("%s",L.r[i].keys);
  	i=L.r[i].next;
   } 
}

void RadixSoft(SLList &L)
{//L�ǲ��þ�̬�����ʾ��˳�����L����������ʹ��L��Ϊ���ؼ�����С���������̬����L.r[0]Ϊͷ���
  int i,j=1;
  ArrType f,e;
  for(i=0;i<L.recnum;++i)
    L.r[i].next=i+1;
  L.r[L.recnum].next=0;
  for(i=L.keynum-1;i>=0;--i,++j)
  {
  	Distribute(L.r,i,f,e);
  	printf("��%d�˷����:\n",j);
  	Print2(L);
  	Collect(L.r,f,e);
  	printf("��%d���ռ���:\n",j);
  	Print2(L);
  	PrintLL(L);
   } 
}

int main()
{
	FILE* f;
	SLList m;
	int *adr;
	f=fopen("f9-4.txt","r");
	MadeListFromFile(m,f);
	fclose(f);
	printf("����ǰ(next��δ��ֵ):\n");
	Print2(m);
	RadixSoft(m);
	adr=(int*)malloc((m.recnum+1)*sizeof(int));
	Sort(m,adr);
	Rearrange(m,adr);
	free(adr);
	printf("\n���ż�¼��(next��������):\n");
	Print2(m);
}
