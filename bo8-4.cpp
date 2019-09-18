void InitDSTable(BTree &DT)
{//�������������һ���յ�B_��DT
   DT=NULL; 
}

void DestroyDSTable(BTree &DT)
{//��ʼ����:B_��DT����  �������������DT
   int i;
   if(DT)
   {
   	for(i=0;i<=DT->keynum;i++)
   	   DestroyDSTable(DT->ptr[i]);
   	free(DT);
   	DT=NULL;
	} 
}

void TraverseDSTable(BTree DT,void(*Visit)(BTNode,int))
{//��ʼ������B_��DT���ڣ�Visit�ǶԽ�������Ӧ�ú���
//������������ؼ��ֵ�˳���DT��ÿ�������ú���Visit()һ��������һ��
  int i;
  if(DT)
    for(i=0;i<=DT->keynum;i++)
	{
		if(i>0)
		  Visit(*DT,i);
		if(DT->ptr[i])
		  TraverseDSTable(DT->ptr[i],Visit);
	 } 
}

int Search(BTNode* p,KeyType K)
{//�����۰���ҷ���p->key[1..keynum]�в���i��ʹ��p->key[i]<=K<p->key[i+1]
  int mid,low=1,high=p->keynum;
  if LT(K,p->key[low])
    return 0;
  while(low<high)
  {
  	mid=(low+high)/2;
  	if EQ(K,p->key[mid])
  	  return mid;
  	if LT(K,p->key[mid])
  	  high=mid-1;
  	else
  	  low=mid;
   } 
   return low;
}

Result SearchBTree(BTree T,KeyType K)
{//��m��B_��T�ϲ��ҹؼ���K�����ؽ��(pt,i,tag).�����ҳɹ���������ֵtag=1��ָ��pt��ָ����е�i���ؼ��ֵ���K��
//��������ֵtag=0������K�Ĺؼ���Ӧ������ָ��Pt��ָ����е�i�͵�i+1���ؼ���֮��
  BTree p=T,q=NULL;
  Status found=FALSE;
  int i=0;
  Result r;
  while(p&&!found)
  {
  	i=Search(p,K);
  	if(i>0&&p->key[i]==K)
  	  found=TRUE;
  	else
  	{
  		q=p;
  		p=p->ptr[i];
	  }
   } 
   if(found)
   {
   	r.pt=p;
   	r.tag=1;
   }
   else
   {
   	r.pt=q;
   	r.tag=0;
   }
   r.i=i;
   return r;
}

void split(BTree q,BTree &ap)
{//�����*q���ѳ�������㣬ǰһ�뱣����*q����һ�������������*ap
  int i;
  ap=(BTree)malloc(sizeof(BTNode));
  ap->ptr[0]=q->ptr[s];
  if(ap->ptr[0])
    ap->ptr[0]->parent=ap;
  for(i=s+1;i<=m;i++)
  {
  	ap->key[i-s]=q->key[i];
  	ap->recptr[i-s]=q->recptr[i];
  	ap->ptr[i-s]=q->ptr[i];
  	if(ap->ptr[i-s])
  	  ap->ptr[i-s]->parent=ap;
   } 
   ap->keynum=m-s;
   q->keynum=s-1;
}

void Insert(BTree q,int i,Record* r,BTree ap)
{
	int j;
	for(j=q->keynum;j>i;j--)
	{
		q->key[j+1]=q->key[j];
		q->recptr[j+1]=q->recptr[j];
		q->ptr[j+1]=q->ptr[j]; 
	}
	q->key[i+1]=r->key;
	q->recptr[i+1]=r;
	q->ptr[i+1]=ap;
	if(ap)
	  ap->parent=q;
	q->keynum++;
}

void NewRoot(BTree &T,Record* r,BTree ap)
{//���ɺ���Ϣ(T,r,ap)���µĸ����*T��ԭ�����T��apΪ������ָ��
  BTree p=(BTree)malloc(sizeof(BTNode));
  p->parent=NULL;
  p->keynum=1;
  p->key[1]=r->key;
  p->recptr[1]=r;
  p->ptr[0]=T;
  if(T)
    T->parent=p;
  p->ptr[1]=ap;
  if(ap)
    ap->parent=p;
  T=p; 
}

void InsertBTree(BTree &T,Record* r,BTree q,int i)
{//��m��B_��T�Ͻ��*q��key[i]��key[i+1]֮�����ؼ���r->k�͵�ַr�����������������˫�������б�Ҫ�Ľ����ѵ�����ʹT����m��B_��
  BTree ap=NULL;
  Status finished=FALSE;
  while(q&&!finished)
  {
  	Insert(q,i,r,ap);
  	if(q->keynum<m)
  	  finished=TRUE;
  	else
  	{
  		r=q->recptr[s];
  		split(q,ap);
  		q=q->parent;
  		if(q)
  		  i=Search(q,r->key);
	  }
   } 
   if(!finished)
     NewRoot(T,r,ap);
}
