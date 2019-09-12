void PreOrderTraverse(CSTree T,void(*Visit)(TElemType))
{//先根遍历孩子-兄弟二叉链表结构的树T
  if(T)
  {
  	Visit(T->data);
  	PreOrderTraverse(T->firstchild,Visit);
  	PreOrderTraverse(T->nextsibling,Visit);
   } 
}
