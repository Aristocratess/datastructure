int main()
{
	HuffmanTree HT;
	HuffmanCode HC;
	int *w,n,i;
	printf("请输入权值的个数(>1):");
	scanf("%d",&n);
	w=(int*)malloc(n*sizeof(int));
	printf("请依次输入%d个权值(整型):\n",n);
	for(i=0;i<=n-1;i++)
	  scanf("%d",w+i);
	HuffmanCoding(HT,HC,w,n);//根据w所存的n个权值构造赫夫曼树HT，n个赫夫曼编码存于HC
	for(i=1;i<=n;i++) 
	  puts(HC[i]);
 } 
