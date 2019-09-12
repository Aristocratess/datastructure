#define Order
int min(HuffmanTree t,int i)
{//返回赫夫曼树t的前i个结点中权值最小的树的根结点序号，函数select()调用
  int j,m;
  unsigned int k=UINT_MAX;//k存最小权值，初值取为不小于可能的值
  for(j=1;j<=i;j++)
    if(t[j].weight<k&&t[j].parent==0)
	{
		k=t[j].weight;//t[j]的权值赋给k
		m=j;//序号赋给m 
	 } 
	t[m].parent=1;
	return m; 
}

void select(HuffmanTree t,int i,int &s1,int &s2)
{//在赫夫曼树他的前i个结点中选择2个权值最小的树的根结点序号，s1为其中序号(权值)较小的
 #ifdef Order
   int j;
 #endif
   s1=min(t,i);//权值最小的根结点序号 
   s2=min(t,i); //权值第2小的根结点序号
 #ifdef Order
   if(s1>s2)
   {
   	j=s1;
   	s1=s2;
   	s2=j;
	} 
 #endif
}
