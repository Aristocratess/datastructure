#define CHAR 1
#include"func6-1.cpp"
#include"c6-2.h"
#include"bo6-2.cpp"
#include"bo6-3.cpp"
int main()
{
	int i;
	BiTree T,p,c;
	TElemType e1,e2;
	InitBiTree(T);
	printf("����ն����������շ�?%d(1:�� 0����)���������=%d��\n",BiTreeEmpty(T),BiTreeDepth(T));
	e1=Root(T);//e1Ϊ������T�ĸ�����ֵ
	if(e1!=Nil)
	  printf("�������ĸ�Ϊ"form".\n",e1);
	else
	  printf("���գ��޸���\n");
	#if CHAR
	  printf("�밴�������������(�磺ab�����ո��ʾaΪ����㣬bΪ�������Ķ�����)"); 
	#else
	  printf("�밴����������������磺1 2 0 0 0��ʾ1Ϊ����㣬2Ϊ�������Ķ�������:\n");
	#endif
	  CreateBiTree(T);
	  printf("���������������շ�?%d(1:�� 0����)���������=%d��\n",BiTreeEmpty(T),BiTreeDepth(T));
	  e1=Root(T);
	  if(e1!=Nil)
	    printf("�������ĸ�Ϊ"form".\n",e1);
	  else
	  printf("����ݹ����������:\n");
	  InOrderTraverse(T,visit);
	  printf("\n����ݹ����������:\n");
	  PostOrderTraverse(T,visit);
	  printf("\n������һ������ֵ��");
	  scanf("%*c"form,&e1);
	  p=Point(T,e1);
	  printf("����ֵΪ"form".\n",Value(p));
	  printf("���ı�˽���ֵ����������ֵ��");
	  scanf("%*c"form"%*c",&e2);//��һ��%*c�Ե��س�����Ϊ����CreateBiTree()��׼��
	  Assign(p,e2);
	  printf("�������������:\n");
	  LevelOrderTraverse(T,visit);
	  e1=Parent(T,e2);
	  if(e1!=Nil)
	    printf(form"��˫����"form",",e2,e1);
	  e1=LeftChild(T,e2);
	  if(e1!=Nil)
	    printf("������"form",",e1);
	  else
	    printf("û������");
	  e1=RightChild(T,e2);
	  if(e1!=Nil)
	    printf("û���Һ��ӣ�");
	  e1=LeftSibling(T,e2);
	  if(e1!=Nil)
	    printf("���ֵ���"form",",e1);
	  else
	    printf("û���Һ���,"); 
	  e1=RightSibling(T,e2);
	  if(e1!=Nil)
	    printf("���ֵ���"form".\n",e1);
	  else
	    printf("û�����ֵܡ�\n");
	  InitBiTree(c);
	  printf("�빹��һ��������Ϊ�յĶ�����c:\n");
	#if CHAR
	  printf("�밴�������������(�磺ab�����ո��ʾaΪ����㣬bΪ�������Ķ�����):\n");
	#else
	  printf("�밴�������������(�磺1 2 0 0 0��ʾ1Ϊ����㣬2Ϊ�������Ķ�����):\n");
	#endif
	  CreateBiTree(c);
	  printf("����ݹ����������c:\n");
	  InOrderTraverse(c,visit);
	  printf("\n��c�嵽��T�У���������T����c��˫�׽��cΪ��(0)����(1)������");
	  scanf("%*c"form"%d",&e1,&i);
	  p=Point(T,e1);//pָ�������T�н���Ϊ�������ӵ�˫�׽���e1
	  InsertChild(p,i,c);//����c���뵽������T����Ϊ���e1(p��ָ)����(i=0)����(i=1)����
	  printf("����ݹ����������:\n");
	  PreOrderTraverse(T,visit);
	  printf("\nɾ���������������ɾ��������˫�׽�� ��(0) ��(1)����:");
	  scanf("%*c"form"%d",&e1,&i);
	  p=Point(T,e1);
	  DeleteChild(p,i);
	  printf("����ݹ����������:\n");
	  PreOrderTraverse(T,visit);
	  printf("����ǵݹ����������:\n");
	  InOrderTraverse1(T,visit);
	  printf("����ǵݹ����������(��һ�ַ���):\n");
	  InOrderTraverse2(T,visit); 
	  DestroyBiTree(T);
}
