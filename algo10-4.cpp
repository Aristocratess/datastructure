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
	int rnum;//�����鲢�εĶκ� 
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
{//��wa[q]�𵽰������ĸ��Ƚ�ѡ��ǰ�ε���С��¼��ls[0]
  int s,p,t=(w+q)/2;//t�ǰ�������wa[q]��˫�׽�����
  for(p=ls[t];t>0;t=t/2,p=ls[t])
    if(wa[p].rnum<wa[q].rnum||wa[p].rnum==wa[q].rnum&&wa[p].rec.key<wa[q].rec.key)//wa[q]��˫�׽��Ķ�ֵС���ֵͬ�ؼ���С
	{
		s=q;//wa[q]��Ϊ�µİ���
		q=ls[t];
		ls[t]=s; 
	 } 
	ls[0]=q;//����ʤ���ߵ���Ÿ���ls[0] 
}

void Construct_Loser(LoserTree ls,WorkArea wa,FILE* fi)
{//����w����¼���ڴ湤����wa�����ð�����ls��ѡ���ؼ�����С�ļ�¼����s[0]ָʾ����wa�е�λ��
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
{//���һ����ʼ�鲢�Σ�fiΪ�����ļ�ָ�룬foΪ����ļ�ָ�룬rcΪ��ǰ��
  int q;
  KeyType minimax;
  while(wa[ls[0]].rnum==rc)
  {
  	q=ls[0];//qָʾѡ�õļ�¼��wa[]�е�λ��
	minimax=wa[q].rec.key;
	OutputToFile(fo,wa[q].rec);
	printf("(%d,%d)",wa[q].rec.key,wa[q].rec.otherinfo);
	InputFromFile(fi,wa[q].rec);
	if(feof(fi))
	  wa[q].rnum=rmax+1;
	else
	 {
	 	if(wa[q].rec.key<minimax)
	 	{//�¶����¼�Ĺؼ���С�ڸ�������ļ��ļ�¼�Ĺؼ���
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
{//�ڰ�����ls���ڴ湤����wa�����û�-ѡ���������ʼ�鲢�Σ�fiΪ�Ѵ򿪵������ļ�(ֻ���ļ�)ָ��
  int rc,rmax;
  FILE* fo;
  char filename[3];
  Construct_Loser(ls,wa,fi);
  rc=rmax=1;
  do//rmaxָʾwa�йؼ���������ʼ�鲢�Ķκţ���ֵΪ1
  {
  	itoa(rc-1,filename,10);
  	fo=fopen(filename,"w");
  	printf("%s������Ϊ:",filename);
  	get_run(ls,wa,rc,rmax,fi,fo);//��öκ�Ϊrc�ĳ�ʼ�鲢���ļ�
	printf("\n");
	fclose(fo);
	rc=wa[ls[0]].rnum; 
   }while(rc<=rmax);
  printf("������%d����ʼ�鲢���ļ�\n",rc-1); 
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
