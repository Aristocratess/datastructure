Status PriorElem(LinkList L,ElemType cur_e,ElemType &pre_e)
{//��ʼ���������Ա�L�Ѵ���
//�����������cur_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ��������OK���������ʧ�ܣ�pre_e�޶��壬����ERROR
 LinkList q,p=L;
 while(p->next)
 {
 	q=p->next;
 	if(q->data==cur_e)
 	{
 		pre_e=p->data;//��p��ָԪ�ص�ֵ����pre_e
		 return OK; 
	 }
	p=q;//p�ĺ�̲�Ϊcur_e,p����� 
  } 
  return ERROR; 
}

Status NextElem(LinkList L,ElemType cur_e,ElemType &next_e)
{//��ʼ���������Ա�L�Ѵ���
//�����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�����OK���������ʧ�ܣ�next_e�޶��壬����ERROR
 LinkList p=L;
 while(p->next)
 {
 	if(p->data==cur_e)
 	{
 		next_e=p->next->data;//��p��ָ���ĺ�̽���ֵ����next_e 
 		return OK; 
	 }
	p=p->next;
  } 
  return ERROR;
}


