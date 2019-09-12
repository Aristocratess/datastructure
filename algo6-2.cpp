#include"c1.h"
#include"c6-5.h"
#include"func6-2.cpp"
void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n)
{//w存放n个字符的权值(均>0)，构造赫夫曼树HT，并求出n个字符的赫夫曼编码HC
  unsigned cdlen;
 #include"func6-3.cpp"
  HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
  cd=(char*)malloc(n*sizeof(char));
  c=m;
  cdlen=0;
  for(i=1;i<=m;++i)
     HT[i].weight=0;
  while(c)
  {
  	if(HT[c].weight==0)
  	{
  		HT[c].weight=1;
  		if(HT[c].lchild!=0)
  		{
  			c=HT[c].lchild;//置c为其左孩子序号
			cd[cdlen++]='0'; 
		  }
		else if(HT[c].rchild==0)
		{
			HC[c]=(char*)malloc((cdlen+1)*sizeof(char));
			cd[cdlen]='\0';
			strcpy(HC[c],cd);
		}
		
	  }
	else if(HT[c].weight==1)
	{
		HT[c].weight=2;
		if(HT[c].rchild!=0)
		{
			c=HT[c].rchild;//置c为其右孩子序号 
			cd[cdlen++]='1';
		}
	}
	else//左右孩子均被访问过(HT[c].weight==2),向根结点方向退一步
	{
		c=HT[c].parent;//置c为其双亲序号
		--cdlen; 
	 } 
   } 
   free(cd);
 } 
 #include"func6-4.cpp"
