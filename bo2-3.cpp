#define DestroyList ClearList
void InitList(LinkList &L)
{//�������������һ���յ����Ա�L 
	L=NULL;//ָ��Ϊ�� 
}

void ClearList(LinkList &L)
{//��ʼ���������Ա�L�Ѵ��ڡ������������L����Ϊ�ձ�
  LinkList p;
  while(L)
  {
  	p=L;//pָ����Ԫ���
	L=L->next; 
  	free(p);
   } 
}

Status ListEmpty(LinkList L)
{//��ʼ���������Ա�L�Ѵ��ڡ������������LΪ�ձ��򷵻�TRUE�����򷵻�FALSE 
	if(L)
	   return FALSE;
	else
	   return TRUE;
}

int ListLength(LinkList L)
{//��ʼ���������Ա�L�Ѵ��ڡ��������������L������Ԫ�صĸ��� 
	int i=0;//��������ֵΪ0
	LinkList p=L;//pָ���1�����
	while(p)
	{
		i++;
		p=p->next;
	 } 
	 return i;
}

Status GetElem(LinkList L,int i,ElemType &e)
{//LΪ����ͷ���ĵ������ͷָ�롣����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR 
   int j=1;
   LinkList p=L;//pָ���1�����
   if(i<1)//iֵ���Ϸ� 
    return ERROR;
   while(j<i&&p)//δ����i��Ԫ�أ�Ҳδ����β
   {
   	 j++;
   	 p=p->next; 
	} 
	if(j==i&&p)
	{
		e=p->data;
		return OK;
	}
	return ERROR;
}

int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
{//��ʼ���������Ա�L�Ѵ��ڣ�compare����������Ԫ���ж�����
//�������������L�е�1����e�����ϵcompare()������Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0
  int i=0;
  LinkList p=L;//pָ���1�����
  while(p)
  {
  	i++;
  	if(compare(p->data,e))
  	  return i;
    p=p->next;//pָ����һ����� 
   } 
	return 0; 
}

Status ListInsert(LinkList &L,int i,ElemType e)
{//�ڲ���ͷ���ĵ������Ա�L�е�i��λ��֮ǰ����Ԫ��e
  int j=1;
  LinkList s,p=L;//pָ���1�����
  if(i<1)
    return ERROR;
  s=(LinkList)malloc(sizeof(LNode));//�����½�㣬���½������L�� 
  s->data=e;//��s��data��ֵe
  if(i==1)
   {
   	s->next=L;//�½��ָ��ԭ��1����� 
   	L=s;//Lָ���½�� 
	} 
   else
   {//���ڱ������� 
   	while(p&&j<i-1)//Ѱ�ҵ�i-1�����
	   {
	   	j++;//������+1
		p=p->next; 
		} 
	if(!p)//i���ڱ�+1
	    return ERROR;
	s->next=p->next;//�½��ָ��ԭ��i�����
	p->next=s;//ԭ��i-1�����ָ���½��  
   }
   return OK;
}


Status ListDelete(LinkList &L,int i,ElemType &e)
{//�ڲ���ͷ���ĵ������Ա�L�У�ɾ����i��Ԫ�أ�����e������ֵ
  int j=1;//��������ֵΪ1
  LinkList q,p=L;//pָ���1�����
  if(!L)//��L��
   return ERROR;//ɾ��ʧ��
  else if(i==1)//ɾ����1�����
  {
  	L=p->next;//L�ɵ�2����㿪ʼ���ı�L�� 
  	e=p->data;
	free(p); 
   } 
  else
  {
  	while(p->next&&j<i-1)//Ѱ�ҵ�i����㣬����pָ����ǰ��
	  {
	  	j++;
	  	p=p->next;
	   } 
	 if(!p->next||j>i-1)//ɾ��λ�ò�����
	   return ERROR;
	 q=p->next;
	 p->next=q->next;
	 e=q->data;
	 free(q);
  }
   return OK;
}

void ListTraverse(LinkList L,void(*vii)(ELemType))
{//��ʼ���������Ա�L�Ѵ��ڡ�������������ζ�L��ÿ������Ԫ�ص��ú���vi����
   LinkList p=L;
   while(p)
   {
   	vii(p->data);
   	p=p->next;
   }
	printf("\n");
}


