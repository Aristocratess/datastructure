int m,i,s1,s2;
unsigned c;
HuffmanTree p;
char *cd;
if(n<=1)
  return;
m=2*n-1;
HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));
for(p=HT+1,i=1;i<=n;++i,++p,++w)
{//p的初值指向1号单元
  (*p).weight=*w;
  (*p).parent=0;
  (*p).lchild=0;
  (*p).rchild=0; 
}
for(;i<=m;++i,++p)
   (*p).parent=0;
for(i=n+1;i<=m;++i)
{//在HT[1~i-1]中选择parent为0且weight最小的两个结点，其序号分别为s1和s2
  select(HT,i-1,s1,s2);
  HT[s1].parent=HT[s2].parent=i;
  HT[i].lchild=s1;
  HT[i].rchild=s2;
  HT[i].weight=HT[s1].weight+HT[s2].weight;//i号单元的权值是s1和s2的权值之和 
}
