LinkList Point(LinkList L,ElemType e,Status(*equal)(ElemType,ElemType),LinkList &p)
{//���ұ�L����e����equal()�����Ľ�㡣���ҵ�������ָ��ý���ָ�룬pָ��ý���ǰ��
//�����ý������Ԫ��㣬��p=NULL�������L�������������Ľ�㣬�򷵻�NULL��p�޶���
  int j,i=LocateElem(L,e,equal);
  if(i)
  {
  	if(i==1)
  	{
  		p=NULL;
  		return L;
	  }
	  p=L;//������Ԫ��㣬��pָ���1�����
	  for(j=2;j<i;j++)//p��ָ�����ҽ���ǰ��
	    p=p->next;
	return p->next; 
   } 
   return NULL;
}
