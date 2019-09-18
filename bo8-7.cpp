void InitHashTable(HashTable &H)
{//操作结果：构造一个空的哈希表
  int i;
  H.count=0;
  H.sizeindex=0;
  m=hashsize[0];
  H.elem=(ElemType*)malloc(m*sizeof(ElemType));
  if(!H.elem)
    exit(OVERFLOW);
  for(i=0;i<m;i++)
    H.elem[i].key=NULL_KEY; 
}

void DestroyHashTable(HashTable &H)
{//初始条件：哈希表H存在。  操作结果：销毁哈希表H
  free(H.elem);
  H.elem=NULL;
  H.count=0;
  H.sizeindex=0; 
}

unsigned Hash(KeyType K)
{//一个简单的哈希函数
   return K%m; 
}

int d(int i)
{
	return i;
}

void collision(KeyType K,int &p,int i)
{
	p=(Hash(K)+d(i))%m;
}

Status SearchHash(HashTable H,KeyType K,int &p,int &c)
{//在开放定址哈希表H中查找关键字为K的元素，若查找成功，以p指示待查数据
//元素在表中位置，并返回SUCCESS，否则，以p指示插入位置，并返回UNSUCCESS
//c用以计冲突次数，其初值置零，供建表插入时参考
  p=Hash(K);
  while(H.elem[p].key!=NULL_KEY&&!EQ(K,H.elem[p].key))
  {//该位置中填有记录，并且与待查找的关键字不相等
    c++;
	if(c<m)
	  collision(K,p,c);
	else
	  break;  
   } 
   if EQ(K,H.elem[p].key)
     return SUCCESS;
   else
     return UNSUCCESS;
}

void RecreateHashTable(HashTable&);
Status InsertHash(HashTable &H,ElemType e)
{//查找不成功时插入数据元素e到开放定址哈希表H中，并返回OK
//若冲突次数过大3，则重建哈希表
  int p,c=0;
  if(SearchHash(H,e.key,p,c))
     return DUPLICATE;
  else if(c<hashsize[H.sizeindex]/2)
  {
  	H.elem[p]=e;
  	++H.count;
  	return OK;
   } 
  else
  {
  	RecreateHashTable(H);
  	return UNSUCCESS;
  }
}

void RecreateHashTable(HashTable &H)
{//重建哈希表H
  int i,count=H.count; 
  ElemType *p,*elem=(ElemType*)malloc(count*sizeof(ElemType));
  //动态生成存放哈希表H原有数据的空间
  p=elem;
  for(i=0;i<m;i++)
    if((H.elem+i)->key!=NULL_KEY)
	  *p++=*(H.elem+i);
  H.count=0;
  H.sizeindex++;
  m=hashsize[H.sizeindex];
  H.elem=(ElemType*)realloc(H.elem,m*sizeof(ElemType));
  for(i=0;i<m;i++)
    H.elem[i].key=NULL_KEY;
  for(p=elem;p<elem+count;p++)
    InsertHash(H,*p);
  free(elem);
}
  
void TraverseHash(HashTable H,void(*Visit)(int,ElemType))
{//按哈希地址的顺序遍历哈希表H
   int i;
   printf("哈希地址0~%d\n",m-1);
   for(i=0;i<m;i++)
     if(H.elem[i].key!=NULL_KEY)
	   Visit(i,H.elem[i]); 
 } 
