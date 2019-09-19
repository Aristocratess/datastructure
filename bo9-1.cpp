void InsertSort(SqList &L)
{//��˳���L��ֱ�Ӳ�������
  int i,j;
  for(i=2;i<=L.length;++i)
    if LT(L.r[i].key,L.r[i-1].key)
	{//��L.r[i]����[1..i-1]�������ӱ���
	 L.r[0]=L.r[i];
	 for(j=i-1;LT(L.r[0].key,L.r[j].key);--j)
	    L.r[j+1]=L.r[j];
	 L.r[j+1]=L.r[0]; 
	 } 
}

void BInsertSort(SqList &L)
{//��˳���L���۰��������
  int i,j,m,low,high;
  for(i=2;i<=L.length;++i)
    if (L.r[i].key<L.r[i-1].key)
	{//��L.r[i]����[1..i-1]�������ӱ���
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
{//2-·��������(flag=0)�͸Ľ���2-·��������(flag=1),��L.r[1]�Ǵ������¼�йؼ�����С�����ļ�¼ʱ��������Խ�� 
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
  		mid=(first+final+j)/2%L.length;//d���м��¼��λ�� 
	  }
	if(L.r[i].key<d[mid].key)//�����¼������d��ǰ�벿����(flag=0ʱ��mid=0)
	{
		j=first;//jָ��d�ĵ�1����¼
		first=(first-1+L.length)%L.length;
		while(L.r[i].key>d[j].key)
		{
			d[(j-1+L.length)%L.length]=d[j];
			j=(j+1)%L.length; 
		 } 
		d[(j-1+L.length)%L.length]=L.r[i];//�ƶ������������¼����[j]ǰ 
	 } 
	 else//�����¼�����ں�벿����
	 {
	 	j=final++;
	 	while(L.r[i].key<d[j].key)
	 	{
	 		d[(j+1)%L.length]=d[j];//j��ָ��¼���ƣ�flag=0ʱ�������� 
	 		j=(j-1+L.length)%L.length;//jָ����1����¼��flag=0ʱ������� 
		 }
		d[(j+1)%L.length]=L.r[i];
		//�����¼��С��j��ָ��¼������j��flag=0ʱ�������� 
	  } 
  }
   for(i=1;i<=L.length;i++)
      L.r[i]=d[(first+i-1)%L.length];
   free(d);
}
