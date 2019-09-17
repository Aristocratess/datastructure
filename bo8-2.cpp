Status SearchBST(BiTree &T,KeyType key,BiTree f,BiTree &p)
{//�ڸ�ָ��T��ָ�����������еݹ�ز�����ؼ��ֵ���key������Ԫ�أ������ҳɹ�����ָ��pָ�������Ԫ�ؽ�㣬������TRUE��
//����ָ��pָ�����·���Ϸ��ʵ����һ����㣬������FALSE��ָ��fָ��T��˫�ף����ʼ����ֵΪNULL
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
{//������������T��û�йؼ��ֵ���e.key��Ԫ�أ�����e������TRUE�����򷵻�FALSE
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
{//�Ӷ�����������ɾ��p��ָ��㣬���ؽ��������������
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
{//������������T�д��ڹؼ��ֵ���key������Ԫ��ʱ����ɾ��������Ԫ�ؽ�㣬������TRUE�����򷵻�FALSE
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
