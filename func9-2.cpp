void Sort(SqList L,int adr[])
{//���adr[1..L.length],adr[i]Ϊ��̬����L�ĵ�i����С��¼�����
  int i=1,p=L.r[0].next;
  while(p)
  {
  	adr[i++]=p;//��p����adr[i],i+1
	p=L.r[p].next; 
   } 
}

void Rearrange(SqList &L,int adr[])
{//adr������̬����L��������򣬼���.r[adr[i]]�ǵ�iС�ļ�¼
   int i,j,k;
   for(i=1;i<L.length;++i)
      if(adr[i]!=i)
	  {
	  	j=i;
	  	L.r[0]=L.r[i];
	  	while(adr[j]!=i)
	  	{
	  		k=adr[j];
	  		L.r[j]=L.r[k];
	  		adr[j]=j;//��¼������ȷλ�õı�־ 
	  		j=k;//�¿ճ���λ�ø���j���Ա����ѭ������ 
		  }
		L.r[j]=L.r[0];
		adr[j]=j;
	   } 
 } 
