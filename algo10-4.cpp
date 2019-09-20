#include"c1.h"
typedef int KeyType;
typedef int InfoType;
#include"c9-1.h"
#define MAX_KEY INT_MAX
#define w 6
#define M 10
typedef int LoserTree[w];
typedef struct workarea{
	RedType rec;
	int rnum;//所属归并段的段号 
}WorkArea[w];
void InputFromFile(FILE* f,RedType &c)
{
	fscanf(f,"%d%d",&c.key,&c.otherinfo);
 } 
 
void OutputToFile(FILE* f,RedType &c)
{
	fprintf(f,"%d %d\n",c.key,c.otherinfo);
}

void Select_MiniMax(LoserTree ls,WorkArea wa,int q)
{//从wa[q]起到败者树的根比较选择当前段的最小记录给ls[0]
  int s,p,t=(w+q)/2;//t是败者树上wa[q]的双亲结点序号
  for(p=ls[t];t>0;t=t/2,p=ls[t])
    if(wa[p].rnum<wa[q].rnum||wa[p].rnum==wa[q].rnum&&wa[p].rec.key<wa[q].rec.key)//wa[q]的双亲结点的段值小或段值同关键字小
	{
		s=q;//wa[q]作为新的败者
		q=ls[t];
		ls[t]=s; 
	 } 
	ls[0]=q;//最终胜利者的序号赋给ls[0] 
}

void Construct_Loser(LoserTree ls,WorkArea wa,FILE* fi)
{//输入w个记录到内存工作区wa，建得败者树ls，选出关键字最小的记录并由s[0]指示其在wa中的位置
  int i;
  for(i=0;i<w;++i)
    wa[i].rnum=ls[i]=0;
  for(i=w-1;i>=0;--i)
  {
  	InputFromFile(fi,wa[i].rec);
  	wa[i].rnum=1;
  	Select_MiniMax(ls,wa,i);
   } 
}

void get_run(LoserTree ls,WorkArea wa,int rc,int &rmax,FILE* fi,FILE* fo)
{//求得一个初始归并段，fi为输入文件指针，fo为输出文件指针，rc为当前段
  int q;
  KeyType minimax;
  while(wa[ls[0]].rnum==rc)
  {
  	q=ls[0];//q指示选得的记录在wa[]中的位置
	minimax=wa[q].rec.key;
	OutputToFile(fo,wa[q].rec);
	printf("(%d,%d)",wa[q].rec.key,wa[q].rec.otherinfo);
	InputFromFile(fi,wa[q].rec);
	if(feof(fi))
	  wa[q].rnum=rmax+1;
	else
	 {
	 	if(wa[q].rec.key<minimax)
	 	{//新读入记录的关键字小于刚输出到文件的记录的关键字
		  rmax=rc+1;
		  wa[q].rnum=rmax; 
		 }
		else
		  wa[q].rnum=rc;
	  } 
	Select_MiniMax(ls,wa,q);
  }
}

void Replace_Selection(LoserTree ls,WorkArea wa,FILE* fi)
{//在败者树ls和内存工作区wa上用置换-选择排序求初始归并段，fi为已打开的输入文件(只读文件)指针
  int rc,rmax;
  FILE* fo;
  char filename[3];
  Construct_Loser(ls,wa,fi);
  rc=rmax=1;
  do//rmax指示wa中关键字所属初始归并的段号，初值为1
  {
  	itoa(rc-1,filename,10);
  	fo=fopen(filename,"w");
  	printf("%s的内容为:",filename);
  	get_run(ls,wa,rc,rmax,fi,fo);//求得段号为rc的初始归并段文件
	printf("\n");
	fclose(fo);
	rc=wa[ls[0]].rnum; 
   }while(rc<=rmax);
  printf("共产生%d个初始归并段文件\n",rc-1); 
}

int main()
{
	FILE* fi;
	LoserTree ls;
	WorkArea wa;
	fi=fopen("f10-2.txt","r");
	Replace_Selection(ls,wa,fi);
	fclose(fi); 
}
