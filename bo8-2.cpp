Status SearchBST(BiTree &T,KeyType key,BiTree f,BiTree &p)
{//在根指针T所指二叉排序树中递归地查找其关键字等于key的数据元素，若查找成功，则指针p指向该数据元素结点，并返回TRUE，
//否则指针p指向查找路径上访问的最后一个结点，并返回FALSE，指针f指向T的双亲，其初始调用值为NULL
  if(!T)
  {
  	p=f;
  	return FALSE;
   } 
  else if EQ(key,T->data.key)
  {
  	p=T;
  	return TRUE;
  }
  else if LT(key,T->data.key)
    return SearchBST(T->lchild,key,T,p);
  else
    return SearchBST(T->rchild,key,T,p);
 } 
 
Status InsertBST(BiTree &T,ElemType e)
{//若二叉排序树T中没有关键字等于e.key的元素，插入e并返回TRUE，否则返回FALSE
  BiTree p,s;
  if(!SearchBST(T,e.key,NULL,p))
  {
  	s=(BiTree)malloc(sizeof(BiTNode));
  	s->data=e;
  	s->lchild=s->rchild=NULL;
	if(!p)
	  T=s;
	else if LT(e.key,p->data.key)
	  p->lchild=s;
	else
	  p->rchild=s;
	return TRUE; 
   } 
   else
     return FALSE;
}

void Delete(BiTree &p)
{//从二叉排序树中删除p所指结点，并重接它的左或右子树
  BiTree s,q=p;
  if(!p->rchild)
  {
  	p=p->lchild;
  	free(q);
   } 
  else if(!p->lchild)
  {
  	p=p->rchild;
  	free(q);
  }
  else
  {
  	s=p->lchild;
  	while(s->rchild)
  	{
  		q=s;
  		s=s->rchild;
	  }
	p->data=s->data;
	if(q!=p)
	   q->rchild=s->lchild;
	else
	  q->lchild=s->lchild;
	free(s);
  }
}

Status DeleteBST(BiTree &T,KeyType key)
{//若二叉排序树T中存在关键字等于key的数据元素时，则删除该数据元素结点，并返回TRUE，否则返回FALSE
   if(!T)
      return FALSE;
   else
    {
    	if(EQ(key,T->data.key))
    	  Delete(T);
    	else if LT(key,T->data.key)
    	  DeleteBST(T->lchild,key);
    	else
    	  DeleteBST(T->rchild,key);
        return TRUE;
	 } 
}
