int InitList(SqList &L)
{//�������������һ���յ�˳�����Ա�L
  L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
  if(!L.elem)//�洢����ʧ��
    exit(OVERFLOW);
  L.length=0;//�ձ���Ϊ0
  L.listsize=LIST_INIT_SIZE;//��ʼ�洢���� 
}

void DestroyList(SqList &L)
{//��ʼ������˳�����Ա�L�Ѵ��ڡ��������������˳�����Ա�L
   free(L.elem);//�ͷ�L.elem��ָ�Ĵ洢�ռ�
   L.elem=NULL;//L.elem����ָ���κδ洢��Ԫ
   L.length=0;
   L.listsize=0; 
 } 
 
void ClearList(SqList &L)
{//��ʼ������˳�����Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�
   L.length=0; 
}

Status ListEmpty(SqList L)
{//��ʼ������˳�����Ա�L�Ѵ���
//�����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
  if(L.length==0)
     return TRUE;
  else
     return FALSE;
}

int Listlength(SqList L)
{//��ʼ������˳�����Ա�L�Ѵ��ڣ��������������L������Ԫ�صĸ���
   return L.length;	
}

Status GetElem(SqList L,int i,ElemType &e)
{//��ʼ������˳�����Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)
//�����������e����L�е�i������Ԫ�ص�ֵ
  if(i<1||i>L.length)//i���ڱ�L�ķ�Χ֮��
    return ERROR;
  e=*(L.elem+i-1);//����L�ĵ�i��Ԫ�ص�ֵ����e
  return OK; 
}

int LocateElem(SqList L,ElemType e,Status(*compare)(ElemType,ElemType))
{//��ʼ������˳�����Ա�L�Ѵ��ڣ�compare()������Ԫ���жϺ���������Ϊ1������Ϊ0��
//�������������L�е�1����e�����ϵcompare����������Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0.
  int i=1;
  ElemType *p=L.elem;//p�ĳ�ֵΪ��һ��Ԫ�صĴ洢λ��
  while(i<L.length&&!compare(*p++,e))//iδ������ķ�Χ��δ�ҵ������ϵ������Ԫ��
    ++i;
  if(i<=L.length)
    return i;
  else
    return 0; 
}

Status PriorElem(SqList L,ElemType cur_e,ElemType &pre_e)
{//��ʼ������˳�����Ա�L�Ѵ���
//�����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ�� ������pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶���
   int i=2;
   ElemType *p=L.elem+1;//pָ���2��Ԫ��
   while(i<=L.length&&*p!=cur_e)//iδ������ķ�Χ��δ�ҵ�cur_e��Ԫ��
   {
   	p++;
   	i++;
	} 
	if(i>L.length)//�����������δ�ҵ�ֵΪcur_e��Ԫ��
	   return ERROR;
	else
	  {
	  	pre_e=*--p;//pָ��ǰһ��Ԫ�أ�cur_e��ǰ����������ָԪ�ص�ֵ����pre_e
		return OK; 
	   } 
 } 
 
 Status NextElem(SqList L,ElemType cur_e,ElemType &next_e)
 {//��ʼ������˳�����Ա�L�Ѵ���
 //�����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶���
    int i=1;
	ElemType *p=L.elem;
	while(i<L.length&&*p!=cur_e)//iδ����β��δ�ҵ�ֵΪcur_e��Ԫ��
	{
		p++;
		i++;
	 } 
	if(i==L.length)//����β��ǰһ��Ԫ�ػ�δ�ҵ�ֵΪcur_e��Ԫ��
	   return ERROR;
    else
	{
		next_e=*++p;//pָ����һ��Ԫ��(cur_e�ĺ��),����ָԪ�ص�ֵ����next_e
		return OK; 
	 } 
 }
 
 Status ListInsert(SqList &L,int i,ElemType e)
 {//��ʼ������˳�����Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)+1
 //�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e,L�ĳ��ȼ�1
   ElemType *newbase,*q,*p;
   if(i<1||i>L.length+1)
     return ERROR;
   if(L.length==L.listsize)//��ǰ�洢�ռ����������ӷ��䣬�޸�
   {
   	newbase=(ElemType*)realloc(L.elem,(L.listsize+LIST_INCREMENT)*sizeof(ElemType));
   	if(!newbase)
   	 exit(OVERFLOW);
    L.elem=newbase;//�»�ַ����L.elem
	L.listsize+=LIST_INCREMENT;//���Ӵ洢���� 
	} 
	q=L.elem+i-1;//qΪ����λ��
	for(p=L.elem+L.length-1;p>=q;--p)//����λ�ü�֮���Ԫ�����ƣ��ɱ�βԪ�ؿ�ʼ�ƣ�
	   *(p+1)=*p;
	*q=e;//����e
	++L.length;
	return OK;
}

Status ListDelete(SqList &L,int i,ElemType &e)
{//��ʼ������˳�����Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)
//���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1
  ElemType *p,*q;
  if(i<1||i>L.length)
    return ERROR;
  p=L.elem+i-1;//p��ɾ��Ԫ�ص�λ��
  e=*p;//��ɾ��Ԫ�ص�ֵ����e
  q=L.elem+L.length-1;//qΪ��βԪ�ص�λ��
  for(++p;p<=q;++p)
     *(p-1)=*p;
  L.length--;//����1
  return OK;
}
	 
void ListTraverse(SqList L, void(*visit)(ELemType&))
{//��ʼ������˳�����Ա�L�Ѵ���
//������������ζ�L��ÿ������Ԫ�ص��ú���visit()��visit()���βμ�'&'��������ͨ������visit()�ı�Ԫ�ص�ֵ 
  ElemType *p=L.elem;//pָ���һ��Ԫ��
  int i;
  for(i=1;i<=L.length;i++)//�ӱ�L�ĵ�һ��Ԫ�ص����һ��Ԫ��
     visit(*p++);//��ÿ������Ԫ��
   printf("\n"); 
}
 
