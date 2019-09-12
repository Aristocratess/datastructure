#include"c1.h"
#include"c6-5.h"
#include"func6-2.cpp"
void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n)
{//w存放n个字符的权值(均>0),构造赫夫曼树HT，并求出n个字符的赫夫曼编码HC
  int start;
  unsigned f;
  #include"func6-3.cpp"
  HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
  //分配n个字符编码的头指针向量([0]不用）
  cd=(char*)malloc(n*sizeof(char));
  cd[n-1]='\0';
  for(i=1;i<=n;i++)
  {//逐个字符求赫夫曼编码
    start=n-1;
	for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
	  if(HT[f].lchild==c)
	    cd[--start]='0';
	  else
	    cd[--start]='1';
	HC[i]=(char*)malloc((n-start)*sizeof(char));//为第i个字符编码分配空间
	strcpy(HC[i],&cd[start]); 
   } 
   free(cd);
}
#include"func6-4.cpp"
