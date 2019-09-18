void InitDSTable(TrieTree &T)
{//操作结果：构造一个空的Trie树T
  T=NULL; 
}

void DestroyDSTable(TrieTree &T)
{//初始条件：Trie树T存在  操作结果：销毁T
   int i,j=0;
   if(T)
   {
   	for(i=0;j<T->bh.num&&i<LENGTH;i++)
   	   if(T->kind==BRANCH&&T->bh.ptr[i])
   	   {
   	   	if(T->bh.ptr[i]->kind==BRANCH)
   	   	   DestroyDSTable(T->bh.ptr[i]);
   	   	else
   	   	   free(T->bh.ptr[i]);
   	   	   j++;
		  }
	free(T);
	T=NULL;
	} 
}

Record* SearchTrie(TrieTree T,KeyType K)
{//在Trie树T中查找关键字等于K的记录
   TrieTree p=T;
   int i;
   for(i=0;p&&p->kind==BRANCH&&i<=K.num;p=p->bh.ptr[ord(K.ch[i++])]);
   //对K的每个字符逐个查找，*p为分支结点，ord()求字符在字母表中序号
   if(p&&p->kind==LEAF&&EQ(p->lf.K.ch,K.ch))
      return p->lf.infoptr;
   else
     return NULL; 
}

void InsertTrie(TrieTree &T,Record* r)
{//初始条件：Trie树T存在，r为待插入的数据元素的指针
//操作结果：若T中不存在其关键字等于r->key.ch的数据元素，则按关键字顺序插r到T中
  TrieTree p=T,q,ap;
  int i,j,k,n;
  if(!T)
  {
  	T=(TrieTree)malloc(sizeof(TrieNode));
  	T->kind=BRANCH;
  	for(i=0;i<LENGTH;i++)
  	  T->bh.ptr[i]=NULL;
  	T->bh.num=1;
  	p=T->bh.ptr[ord(r->key.ch[0])]=(TrieTree)malloc(sizeof(TrieNode));
  	//在关键字首字符对应的指针处动态生成叶子结点
	p->kind=LEAF;
	p->lf.K=r->key;
	p->lf.infoptr=r; 
   } 
   else
   {
   	for(i=0;p&&p->kind==BRANCH&&i<=r->key.num;++i)
   	{
   		q=p;
   		p=p->bh.ptr[ord(r->key.ch[i])];
	   }
	if(!p)
	{
		p=q->bh.ptr[ord(r->key.ch[i-1])]=(TrieTree)malloc(sizeof(TrieNode));
		q->bh.num++;
		p->kind=LEAF;
		p->lf.K=r->key;
		p->lf.infoptr=r;
	}
	else
	{
		if(EQ(p->lf.K.ch,r->key.ch))
		   return;
		else
		{
			for(n=0;r->key.ch[n]==p->lf.K.ch[n];n++);
			n=n-i;
			for(k=0;k<=n;k++)
			{
				ap=q=q->bh.ptr[ord(r->key.ch[i++-1])]=(TrieTree)malloc(sizeof(TrieNode));
				ap->kind=BRANCH;
				for(j=0;j<LENGTH;j++)
				  ap->bh.ptr[j]=NULL;
				ap->bh.num=1;
			}
			ap->bh.num++;
			ap->bh.ptr[ord(p->lf.K.ch[i-1])]=p;
			q=ap->bh.ptr[ord(r->key.ch[i-1])]=(TrieTree)malloc(sizeof(TrieNode));
			//动态生成Tried树结点
			q->kind=LEAF;
			q->lf.K=r->key;
			q->lf.infoptr=r; 
		}
	}
   }
}

void TraverseDSTable(TrieTree T,void(*Visit)(Record*))
{//初始条件：Trie树T存在，Visit是对记录指针操作的应用函数
//操作结果：按关键字的顺序输出关键字及其对应的记录
  TrieTree p;
  int i,n=9;
  if(T) 
	for(i=0;i<LENGTH;i++)
	{
		p=T->bh.ptr[i];
		if(p&&p->kind==LEAF)
		{
			Visit(p->lf.infoptr);
			count++;
			if(count%n==0)
			  printf("\n");
		}
		else if(p&&p->kind==BRANCH)
		   TraverseDSTable(p,Visit);
	}
}
