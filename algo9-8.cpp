#include"c1.h"
typedef char KeysType;
typedef int InfoType;
#include"c9-4.h"
typedef SLList SqList;
#define length recnum
#include"func9-2.cpp"
void MadeListFromFile(SLList &L,FILE* f)
{//通过文件f建立顺序表L
  int i;
  fscanf(f,"%d",&L.recnum);
  for(i=1;i<=L.recnum;i++)
    fscanf(f,"%s%d",&L.r[i].keys,&L.r[i].otheritems);
  L.keynum=strlen(L.r[1].keys); 
}

int ord(char c)
{//返回关键字c的序号 
	return c-'0';
}

void Distribute(SLCell r[],int i,ArrType f,ArrType e)
{//静态链表L的r域中记录已按(keys[i-1 ],...,keys[0])有序。keys[i](keys[0]是最低位关键字）建立RADIX个子表，使同一子表中记录的keys[i]相同
//f[0..RADIX-1]和e[0..RADIX-1]分别指向各子表中第一个和最后一个记录
  int j,p;
  for(j=0;j<RADIX;++j)
  {
  	j=ord(r[p].keys[i]);//当前记录的第i位关键字的序号，以下将当前记录按序号插入子表
	if(!f[j])
	  f[j]=p;//表头指向当前记录
	else
	  r[e[j]].next=p;//修改原子表[j]的表尾记录的next域指向当前记录
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
{//本算法按keys[i]自小至大地将f[0..RADIX-1]所指各子表依次链接成一个链表，e[0..RADIX-1]为各子表的尾指针
  int j,t;
  for(j=0;!f[j];j=succ(j));//找第1个非空子表[j],succ为求后继函数
  r[0].next=f[j];//r[0].next指向第1个非空子表[j]的第j个元素
  t=e[j];//t指向第1个非空子表[j]的表尾元素
  while(j<RADIX-1)
  {
  	for(j=succ(j);j<RADIX-1&&!f[j];j=succ(j));//找下一个非空子表
	if(f[j])
	{
		r[t].next=f[j];
		t=e[j];//t指向新的表尾元素 
	 } 
   } 
   r[t].next=0; 
}

void Print2(SLList L)
{//按数组序号输出静态链表
  int i=0;
  printf("keynum=%d recnum=%d i=%d next=%d\n",L.keynum,L.recnum,i,L.r[i].next);
  for(i=1;i<=L.recnum;i++)
     printf("i=%d keys=%s otheritems=%d next=%d\n",i,L.r[i].keys,L.r[i].otheritems,L.r[i].next);
}

void PrintLL(SLList L)
{//按链表顺序输出静态链表L
  int i=L.r[0].next;
  while(i)
  {
  	printf("%s",L.r[i].keys);
  	i=L.r[i].next;
   } 
}

void RadixSoft(SLList &L)
{//L是采用静态链表表示的顺序表。对L作基数排序，使得L成为按关键字自小到大的有序静态链表，L.r[0]为头结点
  int i,j=1;
  ArrType f,e;
  for(i=0;i<L.recnum;++i)
    L.r[i].next=i+1;
  L.r[L.recnum].next=0;
  for(i=L.keynum-1;i>=0;--i,++j)
  {
  	Distribute(L.r,i,f,e);
  	printf("第%d趟分配后:\n",j);
  	Print2(L);
  	Collect(L.r,f,e);
  	printf("第%d趟收集后:\n",j);
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
	printf("排序前(next域还未赋值):\n");
	Print2(m);
	RadixSoft(m);
	adr=(int*)malloc((m.recnum+1)*sizeof(int));
	Sort(m,adr);
	Rearrange(m,adr);
	free(adr);
	printf("\n重排记录后(next域不起作用):\n");
	Print2(m);
}
