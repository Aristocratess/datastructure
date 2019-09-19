void Sort(SqList L,int adr[])
{//求得adr[1..L.length],adr[i]为静态链表L的第i个最小记录的序号
  int i=1,p=L.r[0].next;
  while(p)
  {
  	adr[i++]=p;//将p赋给adr[i],i+1
	p=L.r[p].next; 
   } 
}

void Rearrange(SqList &L,int adr[])
{//adr给出静态链表L的有序次序，即Ｌ.r[adr[i]]是第i小的记录
   int i,j,k;
   for(i=0;i<L.length;++i)
     if(adr[i]!=i)
	 {
	 	j=i;
	 	L.r[0]=L.r[i];//暂存记录[i]到[0](空出[i]或[j]来) 
	 	while(adr[j]!=i)
	 	{//调整L.r[adr[j]]的记录到位，直到adr[h]=i为止
		  k=adr[j];
		  L.r[j]=L.r[k];
		  adr[j]=j;
		  j=k; 
		 }
		L.r[j]=L.r[0];
		adr[j]=j;
	  } 
 } 
