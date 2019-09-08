#define ClearBiTree DestroyBiTree
void InitBiTree(BiTree &T)
{//�������������ն�����T
  T=NULL; 
}

void DestroyBiTree(BiTree &T)
{//��ʼ������������T���ڡ�  ������������ٶ�����T
  if(T)
  {
  	DestroyBiTree(T->lchild);
    DestroyBiTree(T->rchild);
	free(T);
	T=NULL; 
   } 
}

void PreOrderTraverse(BiTree T,void(*Visit)(TElemType))
{//��ʼ������������T���ڣ�Visit�ǶԽ�������Ӧ�ú�����
//�������������ݹ����T����ÿ�������ú���Visitһ���ҽ�һ��
if(T)
  {
  	Visit(T->data);
  	PreOrderTraverse(T->lchild,Visit);
  	PreOrderTraverse(T->rchild,Visit);
   } 
}

void InOrderTraverse(BiTree T,void(*Visit)(TElemType))
{//��ʼ������������T���ڣ�Visit�ǶԽڵ������Ӧ�ú���
//�������������ݹ����T����ÿ�������ú���Visitһ���ҽ�һ��
  if(T)
  {
  	InOrderTraverse(T->lchild,Visit);
  	Visit(T->data);
  	InOrderTraverse(T->rchild,Visit);
   } 
}
