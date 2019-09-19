void InsertSort(SqList &L)
{//对顺序表L作直接插入排序
  int i,j;
  for(i=2;i<=L.length;++i)
    if LT(L.r[i].key,L.r[i-1].key)
	{//将L.r[i]插入[1..i-1]的有序子表中
	 L.r[0]=L.r[i];
	 for(j=i-1;LT(L.r[0].key,L.r[j].key);--j)
	    L.r[j+1]=L.r[j];
	 L.r[j+1]=L.r[0]; 
	 } 
}

void BInsertSort(SqList &L)
{//对顺序表L作折半插入排序
  int i,j,m,low,high;
  for(i=2;i<=L.length;++i)
    if (L.r[i].key<L.r[i-1].key)
	{//将L.r[i]插入[1..i-1]的有序子表中
	 L.r[0]=L.r[i];
	 low=1;
	 high=i-1;
	 while(low<=high)
	 {
	 	m=(low+high)/2;
	 	if (L.r[0].key<L.r[m].key)
	 	  high=m-1;
	 	else
	 	  low=m+1;
	  } 
	for(j=i-1;j>=high+1;--j)
	  L.r[j+1]=L.r[j];
	L.r[high+1]=L.r[0];
	 } 
}

void P2_InsertSort(SqList &L,int flag)
{//2-路插入排序(flag=0)和改进的2-路插入排序(flag=1),当L.r[1]是待排序记录中关键字最小或最大的记录时，仍有优越性 
  int i,j,first,final,mid=0;
  RedType *d;
  d=(RedType*)malloc(L.length*sizeof(RedType));
  d[0]=L.r[1];
  first=final=0;
  for(i=2;i<=L.length;++i)
  {
  	if(flag)
  	{
  		if(first>final)
  		  j=L.length;
  		else
  		  j=0;
  		mid=(first+final+j)/2%L.length;//d的中间记录的位置 
	  }
	if(L.r[i].key<d[mid].key)//待插记录将插在d的前半部分中(flag=0时，mid=0)
	{
		j=first;//j指向d的第1个记录
		first=(first-1+L.length)%L.length;
		while(L.r[i].key>d[j].key)
		{
			d[(j-1+L.length)%L.length]=d[j];
			j=(j+1)%L.length; 
		 } 
		d[(j-1+L.length)%L.length]=L.r[i];//移动结束，待插记录插在[j]前 
	 } 
	 else//待插记录将插在后半部分中
	 {
	 	j=final++;
	 	while(L.r[i].key<d[j].key)
	 	{
	 		d[(j+1)%L.length]=d[j];//j所指记录后移，flag=0时不必求余 
	 		j=(j-1+L.length)%L.length;//j指向上1个记录，flag=0时不必求会 
		 }
		d[(j+1)%L.length]=L.r[i];
		//待插记录不小于j所指记录，插在j后，flag=0时不必求余 
	  } 
  }
   for(i=1;i<=L.length;i++)
      L.r[i]=d[(first+i-1)%L.length];
   free(d);
}
