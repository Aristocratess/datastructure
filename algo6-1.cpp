#include"c1.h"
#include"c6-5.h"
#include"func6-2.cpp"
void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n)
{//w���n���ַ���Ȩֵ(��>0),����շ�����HT�������n���ַ��ĺշ�������HC
  int start;
  unsigned f;
  #include"func6-3.cpp"
  HC=(HuffmanCode)malloc((n+1)*sizeof(char*));
  //����n���ַ������ͷָ������([0]���ã�
  cd=(char*)malloc(n*sizeof(char));
  cd[n-1]='\0';
  for(i=1;i<=n;i++)
  {//����ַ���շ�������
    start=n-1;
	for(c=i,f=HT[i].parent;f!=0;c=f,f=HT[f].parent)
	  if(HT[f].lchild==c)
	    cd[--start]='0';
	  else
	    cd[--start]='1';
	HC[i]=(char*)malloc((n-start)*sizeof(char));//Ϊ��i���ַ��������ռ�
	strcpy(HC[i],&cd[start]); 
   } 
   free(cd);
}
#include"func6-4.cpp"
