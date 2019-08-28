void InitList(DuLinkList &L)
{//产生空的双向循环链表L
  L=(DuLinkList)malloc(sizeof(DuLNode));
  if(L)
   L->next=L->prior=L;
  else
   exit(OVERFLOW); 
}

void ClearList(DuLinkList L)
{//初始条件：L已存在。 操作结果：将L重置为空表 
	DuLinkList p=L->next;//p指向第一个结点
	while(p!=L)//p未指向头结点
	{
		p=p->next;
		free(p->prior);//释放p的前驱结点 
	 } 
	L->next=L->prior=L;//头结点的两个指针域均指向自身 
}

void DestroyList(DuLinkList &L)
{
	ClearList(L);
	free(L);
	L=NULL;
}
 
Status ListEmpty(DuLinkList L)
{//初始条件:线性表L已存在。 操作结果：若L为空表，则返回TRUE，否则返回FALSE
  if(L->next==L&&L->prior==L)
    return TRUE;
  else
    return FALSE; 
 } 
 
int ListLength(DuLinkList L)
{//初始条件：L已存在。 操作结果：返回L中数据元素个数
  int i=0;
  DuLinkList p=L->next;//p指向第一个结点
  while(p!=L)//p未指向头结点
  {
  	i++;
  	p=p->next;
   } 
   return i;
}

Status GetElem(DuLinkList L,int i,ElemType &e)
{//当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
  int j=1;
  DuLinkList p=L->next;//p指向第一个结点 
  while(p!=L&&j<i)//顺时针向后查找，直到p指向第i个元素或p指向头结点
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
{//初始条件：L已存在，compare()是数据元素判定函数
 //操作结果：返回L中第i个与ｅ满足关系ｃｏｍｐａｒｅ()的数据元素的位序，若这样的数据元素不存在，则返回值为0
   int i=0;
   DuLinkList p=L->next;//p指向第1个元素
   while(p!=L)//p未指向头结点
   {
   	i++;
   	if(compare(p->data,e))
	   return i;//返回其位序
	p=p->next; 
	} 
    return 0;
}

Status PriorElem(DuLinkList L,ElemType cur_e,ElemType &pre_e)
{//操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，返回OK；否则操作失败，pre_e无定义，返回ERROR
  DuLinkList p=L->next->next;//p指向第2个元素
  while(p!=L)//p未指向头结点
  {
  	if(p->data==cur_e)//p指向值为cur_e的结点
	  {
	  	pre_e=p->prior->data;//将p的前驱结点的值赋给pre_e
		  return OK;
	   }
	  	p=p->next; 
   } 
	return ERROR; 
 } 
 
 Status NextElem(DuLinkList L,ElemType cur_e,ElemType &next_e)
 {//操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继，返回OK。 否则操作失败，next_e无定义，返回ERROR
   DuLinkList p=L->next->next;//p指向第2个元素
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
 {//在双向链表L中返回第i个元素的地址。i为0，返回头结点的地址。若第i个元素不存在，返回NULL
    int j;
     DuLinkList p=L;
	 if(i<0||i>ListLength(L))
	   return NULL;
	 for(j=1;j<=i;j++)//p指向第i个结点
	   p=p->next;
	 return p; 
 }
 
Status ListInsert(DuLinkList L,int i,ElemType e)
 {//在带头结点的双链循环线性表L中第i个位置之前插入元素e，i的合法值为1<=i<=表长+1，改进算法2.18，否则无法在第表长+1个结点之前插入元素 
    DuLinkList p,s;
	if(i<1||i>ListLength(L)+1)
	  return ERROR;
	p=GetElemP(L,i-1);//在L中确定第i个结点前驱的位置指针p
	if(!p)//p=NULL,即第i个结点的前驱不存在
	  return ERROR;
	s=(DuLinkList)malloc(sizeof(DuLNode));
	if(!s)
	  return ERROR;
	s->data=e;
	s->prior=p;//新结点的前驱为第i-1个结点
	s->next=p->next;//新结点的后继为第i个结点
	p->next->prior=s;//第i个结点的前驱指向新结点
	p->next=s;//第i-1个结点的后继指向新结点
	return OK; 
  } 
 
Status ListDelete(DuLinkList L,int i,ElemType &e)
 {//删除带头结点的双链循环线性表L的第i个元素，i的合法值为1<=i<=表长
    DuLinkList p;
    if(i<1)
      return ERROR;
    p=GetElemP(L,i);//在L中确定第i个元素的位置指针p
	if(!p)
	 return ERROR;
	e=p->data;
	p->prior->next=p->next;//第i-1个结点的后继指向原第i+1个结点
	p->next->prior=p->prior;//原第i+1个结点的前驱指向第i-1个结点
	free(p);
	return OK; 
  } 
  
void ListTraverse(DuLinkList L,void(*visit)(ElemType))
{//由双链循环线性表L的头结点出发，正序对每个数据元素调用函数visit()
   DuLinkList p=L->next;
   while(p!=L)
   {
   	visit(p->data);//对p所指结点调用函数visit()
	p=p->next; 
	} 
   printf("\n");
}

void ListTraverseBack(DuLinkList L,void(*visit)(ElemType))
{//由双链循环线性表L的头结点出发，逆序对每个数据元素调用函数visit()
  DuLinkList p=L->prior;//p指向尾结点
  while(p!=L)//p未指向头结点
  {
  	visit(p->data);//对p所指结点调用函数visit()
	p=p->prior; 
   } 
   printf("\n");
}
