void PreOrderTraverse(CSTree T,void(*Visit)(TElemType))
{//�ȸ���������-�ֵܶ�������ṹ����T
  if(T)
  {
  	Visit(T->data);
  	PreOrderTraverse(T->firstchild,Visit);
  	PreOrderTraverse(T->nextsibling,Visit);
   } 
}
