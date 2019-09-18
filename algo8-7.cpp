#include"c1.h"
#define N 20
struct Others{
	int order;
};

#define Nil '$'
#include"c8-7.h"
#include"c8-4.h"
#include"c8-8.h"
#include"bo8-5.cpp"
#include"func8-7.cpp"
int main()
{
	DLTree t;
	int i,j=0;
	KeyType k;
	Record* p,r[N];
	FILE* f;
	InitDSTable(t);
	f=fopen("f8-5.txt","r");
	do{
		i=fscanf(f,"%s%d",&r[j].key.ch,&r[j].others.order);
		if(i!=-1)
		{
			r[j].key.num=strlen(r[j].key.ch);
			p=SearchDLTree(t,r[j].key);//��˫������t�в��ҹؼ��ִ�����r[j].key�ļ�¼
			if(!p)
			{
				InsertDSTable(t,&r[j]);
				j++;
			}
			else
			  printf("��t���Ѵ��ڹؼ���Ϊ%s�ļ�¼����(%s,%d)�޷����롣\n",r[j].key.ch,r[j].key.ch,r[j].others.order);	 
		}
	}while(!feof(f)&&j<N);
	fclose(f);
	printf("���ؼ��ַ�����˳�������t:\n");
	TraverseDSTable(t,Visit);
	printf("\n����������Ҽ�¼�Ĺؼ��ַ���:");
	InputKey(k.ch);
	k.num=strlen(k.ch);
	p=SearchDLTree(t,k);
	if(p)
	  Visit(p);
	else
	  printf("δ�ҵ�");
	printf("\n");
	DestroyDSTable(t);
}
