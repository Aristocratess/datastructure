#include"bo6-2.cpp"
#define InitDSTable InitBiTree
#define DestroyDSTable DestroyBiTree
#define TraverseDSTable InOrderTraverse
//���ؼ���˳�����������������ƽ�����������������������Ĳ���ͬ
BiTree SearchBST(BiTree T,KeyType key)
{//�ڸ�ָ��T��ָ������������ƽ��������еݹ�ز���ĳ�ؼ��ֵ���key������Ԫ��
//�����ҳɹ����򷵻�ָ�������Ԫ�ؽ���ָ�룬���򷵻ؿ�ָ�� 
	if(!T||EQ(key,T->data.key))
	   return T;
	else if LT(key,T->data.key)
	   return SearchBST(T->lchild,key);
	else
	   return SearchBST(T->rchild,key);
}
