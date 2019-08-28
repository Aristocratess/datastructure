void InitList(DuLinkList &L)
{//�����յ�˫��ѭ������L
  L=(DuLinkList)malloc(sizeof(DuLNode));
  if(L)
   L->next=L->prior=L;
  else
   exit(OVERFLOW); 
}

void ClearList(DuLinkList L)
{//��ʼ������L�Ѵ��ڡ� �����������L����Ϊ�ձ� 
	DuLinkList p=L->next;//pָ���һ�����
	while(p!=L)//pδָ��ͷ���
	{
		p=p->next;
		free(p->prior);//�ͷ�p��ǰ����� 
	 } 
	L->next=L->prior=L;//ͷ��������ָ�����ָ������ 
}

void DestroyList(DuLinkList &L)
{
	ClearList(L);
	free(L);
	L=NULL;
}
 
Status ListEmpty(DuLinkList L)
{//��ʼ����:���Ա�L�Ѵ��ڡ� �����������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE
  if(L->next==L&&L->prior==L)
    return TRUE;
  else
    return FALSE; 
 } 
 
int ListLength(DuLinkList L)
{//��ʼ������L�Ѵ��ڡ� �������������L������Ԫ�ظ���
  int i=0;
  DuLinkList p=L->next;//pָ���һ�����
  while(p!=L)//pδָ��ͷ���
  {
  	i++;
  	p=p->next;
   } 
   return i;
}

Status GetElem(DuLinkList L,int i,ElemType &e)
{//����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
  int j=1;
  DuLinkList p=L->next;//pָ���һ����� 
  while(p!=L&&j<i)//˳ʱ�������ң�ֱ��pָ���i��Ԫ�ػ�pָ��ͷ���
  {
  	j++;
  	p=p->next;
   } 
   if(p==L||j>i)
     return ERROR;
   e=p->data;
   return OK;
}

int LocateElem(DuLinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
{//��ʼ������L�Ѵ��ڣ�compare()������Ԫ���ж�����
 //�������������L�е�i����������ϵ��������()������Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0
   int i=0;
   DuLinkList p=L->next;//pָ���1��Ԫ��
   while(p!=L)//pδָ��ͷ���
   {
   	i++;
   	if(compare(p->data,e))
	   return i;//������λ��
	p=p->next; 
	} 
    return 0;
}

Status PriorElem(DuLinkList L,ElemType cur_e,ElemType &pre_e)
{//�����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ��������OK���������ʧ�ܣ�pre_e�޶��壬����ERROR
  DuLinkList p=L->next->next;//pָ���2��Ԫ��
  while(p!=L)//pδָ��ͷ���
  {
  	if(p->data==cur_e)//pָ��ֵΪcur_e�Ľ��
	  {
	  	pre_e=p->prior->data;//��p��ǰ������ֵ����pre_e
		  return OK;
	   }
	  	p=p->next; 
   } 
	return ERROR; 
 } 
 
 Status NextElem(DuLinkList L,ElemType cur_e,ElemType &next_e)
 {//�����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�����OK�� �������ʧ�ܣ�next_e�޶��壬����ERROR
   DuLinkList p=L->next->next;//pָ���2��Ԫ��
   while(p!=L)
   {if(p->prior->data==cur_e)
      {
      	next_e=p->data;
        return OK;
	  }
	p=p->next;
	} 
	return ERROR;
 }
 
DuLinkList GetElemP(DuLinkList L,int i)
 {//��˫������L�з��ص�i��Ԫ�صĵ�ַ��iΪ0������ͷ���ĵ�ַ������i��Ԫ�ز����ڣ�����NULL
    int j;
     DuLinkList p=L;
	 if(i<0||i>ListLength(L))
	   return NULL;
	 for(j=1;j<=i;j++)//pָ���i�����
	   p=p->next;
	 return p; 
 }
 
Status ListInsert(DuLinkList L,int i,ElemType e)
 {//�ڴ�ͷ����˫��ѭ�����Ա�L�е�i��λ��֮ǰ����Ԫ��e��i�ĺϷ�ֵΪ1<=i<=��+1���Ľ��㷨2.18�������޷��ڵڱ�+1�����֮ǰ����Ԫ�� 
    DuLinkList p,s;
	if(i<1||i>ListLength(L)+1)
	  return ERROR;
	p=GetElemP(L,i-1);//��L��ȷ����i�����ǰ����λ��ָ��p
	if(!p)//p=NULL,����i������ǰ��������
	  return ERROR;
	s=(DuLinkList)malloc(sizeof(DuLNode));
	if(!s)
	  return ERROR;
	s->data=e;
	s->prior=p;//�½���ǰ��Ϊ��i-1�����
	s->next=p->next;//�½��ĺ��Ϊ��i�����
	p->next->prior=s;//��i������ǰ��ָ���½��
	p->next=s;//��i-1�����ĺ��ָ���½��
	return OK; 
  } 
 
Status ListDelete(DuLinkList L,int i,ElemType &e)
 {//ɾ����ͷ����˫��ѭ�����Ա�L�ĵ�i��Ԫ�أ�i�ĺϷ�ֵΪ1<=i<=��
    DuLinkList p;
    if(i<1)
      return ERROR;
    p=GetElemP(L,i);//��L��ȷ����i��Ԫ�ص�λ��ָ��p
	if(!p)
	 return ERROR;
	e=p->data;
	p->prior->next=p->next;//��i-1�����ĺ��ָ��ԭ��i+1�����
	p->next->prior=p->prior;//ԭ��i+1������ǰ��ָ���i-1�����
	free(p);
	return OK; 
  } 
  
void ListTraverse(DuLinkList L,void(*visit)(ElemType))
{//��˫��ѭ�����Ա�L��ͷ�������������ÿ������Ԫ�ص��ú���visit()
   DuLinkList p=L->next;
   while(p!=L)
   {
   	visit(p->data);//��p��ָ�����ú���visit()
	p=p->next; 
	} 
   printf("\n");
}

void ListTraverseBack(DuLinkList L,void(*visit)(ElemType))
{//��˫��ѭ�����Ա�L��ͷ�������������ÿ������Ԫ�ص��ú���visit()
  DuLinkList p=L->prior;//pָ��β���
  while(p!=L)//pδָ��ͷ���
  {
  	visit(p->data);//��p��ָ�����ú���visit()
	p=p->prior; 
   } 
   printf("\n");
}
