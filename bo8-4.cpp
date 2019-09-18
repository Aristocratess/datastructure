void InitDSTable(BTree &DT)
{//操作结果：构造一个空的B_树DT
   DT=NULL; 
}

void DestroyDSTable(BTree &DT)
{//初始条件:B_树DT存在  操作结果：销毁DT
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
{//初始条件：B_树DT存在，Visit是对结点操作的应用函数
//操作结果：按关键字的顺序对DT的每个结点调用函数Visit()一次且至多一次
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
{//采用折半查找法在p->key[1..keynum]中查找i，使得p->key[i]<=K<p->key[i+1]
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
{//在m阶B_树T上查找关键字K，返回结果(pt,i,tag).若查找成功，则特征值tag=1，指针pt所指结点中第i个关键字等于K；
//否则特征值tag=0，等于K的关键字应插入在指针Pt所指结点中第i和第i+1个关键字之间
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
{//将结点*q分裂成两个结点，前一半保留在*q，后一半移入新生结点*ap
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
{//生成含信息(T,r,ap)的新的根结点*T，原根结点T和ap为其子树指针
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
{//在m阶B_树T上结点*q的key[i]与key[i+1]之间插入关键字r->k和地址r。若引起结点过大，则沿双亲链进行必要的结点分裂调整，使T仍是m阶B_树
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
