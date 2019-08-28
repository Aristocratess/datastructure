#define DestroyList ClearList
void InitList(LinkList &L)
{//操作结果：构造一个空的线性表L 
	L=NULL;//指针为空 
}

void ClearList(LinkList &L)
{//初始条件：线性表L已存在。操作结果：将L重置为空表
  LinkList p;
  while(L)
  {
  	p=L;//p指向首元结点
	L=L->next; 
  	free(p);
   } 
}

Status ListEmpty(LinkList L)
{//初始条件：线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE 
	if(L)
	   return FALSE;
	else
	   return TRUE;
}

int ListLength(LinkList L)
{//初始条件：线性表L已存在。操作结果：返回L中数据元素的个数 
	int i=0;//计数器初值为0
	LinkList p=L;//p指向第1个结点
	while(p)
	{
		i++;
		p=p->next;
	 } 
	 return i;
}

Status GetElem(LinkList L,int i,ElemType &e)
{//L为不设头结点的单链表的头指针。当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR 
   int j=1;
   LinkList p=L;//p指向第1个结点
   if(i<1)//i值不合法 
    return ERROR;
   while(j<i&&p)//未到第i个元素，也未到表尾
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
{//初始条件：线性表L已存在，compare（）是数据元素判定函数
//操作结果：返回L中第1个与e满足关系compare()的数据元素的位序，若这样的数据元素不存在，则返回值为0
  int i=0;
  LinkList p=L;//p指向第1个结点
  while(p)
  {
  	i++;
  	if(compare(p->data,e))
  	  return i;
    p=p->next;//p指向下一个结点 
   } 
	return 0; 
}

Status ListInsert(LinkList &L,int i,ElemType e)
{//在不设头结点的单链线性表L中第i个位置之前插入元素e
  int j=1;
  LinkList s,p=L;//p指向第1个结点
  if(i<1)
    return ERROR;
  s=(LinkList)malloc(sizeof(LNode));//生成新结点，以下将其插入L中 
  s->data=e;//给s的data域赋值e
  if(i==1)
   {
   	s->next=L;//新结点指向原第1个结点 
   	L=s;//L指向新结点 
	} 
   else
   {//插在表的其余出 
   	while(p&&j<i-1)//寻找第i-1个结点
	   {
	   	j++;//计数器+1
		p=p->next; 
		} 
	if(!p)//i大于表长+1
	    return ERROR;
	s->next=p->next;//新结点指向原第i个结点
	p->next=s;//原第i-1个结点指向新结点  
   }
   return OK;
}


Status ListDelete(LinkList &L,int i,ElemType &e)
{//在不设头结点的单链线性表L中，删除第i个元素，并由e返回其值
  int j=1;//计数器初值为1
  LinkList q,p=L;//p指向第1个结点
  if(!L)//表L空
   return ERROR;//删除失败
  else if(i==1)//删除第1个结点
  {
  	L=p->next;//L由第2个结点开始（改变L） 
  	e=p->data;
	free(p); 
   } 
  else
  {
  	while(p->next&&j<i-1)//寻找第i个结点，并令p指向其前驱
	  {
	  	j++;
	  	p=p->next;
	   } 
	 if(!p->next||j>i-1)//删除位置不合理
	   return ERROR;
	 q=p->next;
	 p->next=q->next;
	 e=q->data;
	 free(q);
  }
   return OK;
}

void ListTraverse(LinkList L,void(*vii)(ELemType))
{//初始条件：线性表L已存在。操作结果：依次对L的每个数据元素调用函数vi（）
   LinkList p=L;
   while(p)
   {
   	vii(p->data);
   	p=p->next;
   }
	printf("\n");
}


