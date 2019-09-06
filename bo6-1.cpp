#define ClearBiTree InitBiTree
#define DestroyBiTree InitBiTree
void InitBiTree(SqBiTree T)
{//����ն�����T����ΪT�����������ʲ���Ҫ&
   int i;
   for(i=0;i<MAX_TREE_SIZE;i++)
     T[i]=Nil;//��ֵΪ��(Nil�������ж���) 
 } 

void CreateBiTree(SqBiTree T)
{//�����������������н���ֵ(�ַ��ͻ�����)��9����˳��洢�Ķ�����T
   int i=0;
   InitBiTree(T);
   #if CHAR//CHARֵΪ���㣬�������Ϊ�ַ�
   int n;
   char s[MAX_TREE_SIZE];
   printf("�밴�����������ֵ(�ַ�)���ո��ʾ�ս�㣬�����<=%d:\n",MAX_TREE_SIZE);
   gets(s);//�����ַ���
   n=strlen(s);
   for(;i<n;i++)
     T[i]=S[i];
   #else
     printf("�밴�����������ֵ(����)��0��ʾ�ս�㣬��999�����������<=%d:\n",MAX_TREE_SIZE);
	 while(1)
	 {
	 	scanf("%d",&T[i]);
	 	if(T[i]==999)//�������
		  {
		  	T[i]=Nil;
		  	break;
		   } 
		i++;
	  } 
	#endif
	  for(i=1;i<MAX_TREE_SIZE;i++)
	    if(T[i]!=Nil&&T[(i+1)/2-1]==Nil)//�˽�㲻�յ���˫��
		{
			printf("������˫�׵ķǸ���㡰form��\n",T[i]);
			exit(OVERFLOW);
		 } 
 } 
 
 Status BiTreeEmpty(SqBiTree T)
 {//��ʼ����:������T���ڡ� �������: ��TΪ�ն��������򷵻�TRUE�����򷵻�FALSE
   if(T[0]==Nil)
     return TRUE;
   else
     return FALSE; 
 }
 
 int BiTreeDepth(SqBiTree T)
 {//��ʼ������������T���ڡ�  �������������T�����
   int i;
   if(T[0]==Nil)
     return 0;
   for(i=MAX_TREE_SIZE-1;i>=0;i--)
     if(T[i]!=Nil)//�ҵ����һ����㣬�����Ϊi
	   break;
   return (int)(log(i+1)/log(2)+1.1);//���Ϊi�Ľ�����Ⱦ���������� 
 }
 
 Status Root(SqBiTree T,TElemType &e)
 {//��ʼ������������T����
 //�����������T���գ���e����T�ĸ�������OK�����򷵻�ERROR��e�޶���
   if(BiTreeEmpty(T))
     return ERROR;
   else
    {
    	e=T[0];
    	return OK;
	 } 
 }
 
 TElemType Value(SqBiTree T,position e)
 {//��ʼ������������T���ڣ�e��T��ĳ����㣨��λ�ã�
 //������������ش���λ��e���㣬������ţ��Ľ���ֵ
   return T[int(pow(2,e.level-1)+e.order-2)]; 
 }
 
 Status Assign(SqBiTree T,position e,TElemType value)
 {//��ʼ������������T���ڣ�e��T��ĳ�����(��λ�ã�
 //���������������λ��e(�㣬�������)�Ľ�㸳��ֵvalue
   int i=int(pow(2,e.level-1)+e.order-2);//���㡢�������תΪ��������
   if(i!=0&&value!=Nil&&T[(i+1)/2-1]==Nil)//���Ǹ���㣬ֵ�ǿգ���˫��Ϊ��
     return ERROR;
   else if(value==Nil&&(T[i*2+1]!=Nil||T[i*2+2]!=Nil))
     return ERROR;
   T[i]=value;
   return OK; 
  } 

TElemType Parent(SqBiTree T,TElemType e)
{//��ʼ������������T���ڣ�e��T��ĳ�����
//�����������e��T�ķǸ���㣬�򷵻�����˫��; ���򷵻ء��ա�
  int i;
  if(T[0]==Nil)
    return Nil;
  for(i=1;i<=MAX_TREE_SIZE-1;i++)
    if(T[i]==e)
	  return T[(i+1)/2-1];//������˫�׽���ֵ
  return Nil; 
}

TElemType LeftChild(SqBiTree T,TElemType e)
{//��ʼ������������T���ڣ�e��T��ĳ�����
//�������������e�����ӡ���e�����ӣ��򷵻�Ϊ"��"
  int i;
  for(i=0;i<=(MAX_TREE_SIZE-2)/2;i++)
     if(T[i]==e)
	   return T[i*2+1];
  return Nil; 
}

TElemType RightChild(SqBiTree T,TElemType e)
{//��ʼ������������T���ڣ�e��T��ĳ�����
//�������������e���Һ��ӡ���e���Һ��ӣ��򷵻ء��ա�
  int i;
  if(T[0]==Nil)
    return Nil;
  for(i=1;i<=MAX_TREE_SIZE-1;i++)
    if(T[i]==e&&i%2==0)
	  return T[i-1];//����e�����ֵܵ�ֵ
  return Nil; 
 } 
 
TElemType LeftSibling(SqBiTree T,TElemType e)
{//��ʼ������������T���ڣ�e��T��ĳ�����
//�������������e�����ֵܡ���e��T�����ӻ������ֵܣ��򷵻�"��"
  int i;
  if(T[0]==Nil)
    return Nil;
  for(i=1;i<=MAX_TREE_SIZE-1;i++)
    if(T[i]==e&&i%2==0)//�ҵ�e�������Ϊż��(���Һ���) 
	  return T[i-1];//����e�����ֵܵ�ֵ 
  return Nil; 
 } 
 
TElemType RightSibling(SqBiTree T,TElemType e)
{//��ʼ������������T���ڣ�e��T��ĳ�����
//�������������e�����ֵܡ���e��T���Һ��ӻ������ֵܣ��򷵻�"��"
  int i;
  if(T[0]==Nil)
    return Nil;
  for(i=1;i<=MAX_TREE_SIZE-2;i++)
    if(T[i]==e&&i%2)//�ҵ�e�������Ϊ����
	  return T[i+1];
  return Nil; 
 } 
 
void Move(SqBiTree q,int j,SqBiTree T,int i)
{//�Ѵ�q��j��㿪ʼ��������Ϊ��T��i��㿪ʼ������
  if(i>=MAX_TREE_SIZE)
    exit(OVERFLOW);
  if(q[2*j+1]!=Nil)
    Move(q,(2*j+1),T,(2*i+1));//��q��j������������ΪT��i����������
  if(q[2*j+2]!=Nil)
    Move(q,(2*j+2),T,(2*i+2));//��q��j������������ΪT��i����������
  T[i]=q[j];//��q��j�����ΪT��i���
  q[j]=Nil;//��q��j����ÿ� 
}

void InsertChild(SqBiTree T,TElemType p,int LR,SqBiTree c)
{//��ʼ������������T���ڣ�p��T��ĳ������ֵ��LRΪ0��1���ǿն�����c��T���ཻ��������Ϊ��
 //�������������LRΪ0��1������cΪT��p���������������p����ԭ��������������Ϊc��������
   int j,k;
   for(j=0;j<int(pow(2,BiTreeDepth(T)))-1;j++) 
     if(T[j]==p)
       break;
   k=2*j+1+LR;//kΪp������Һ��ӵ����
   if(T[k]!=Nil)
     Move(T,k,c,2);//�Ѵ�T��k��㿪ʼ��������Ϊc��������
   Move(c,0,T,k);//����c��Ϊ��T��k��㿪ʼ������ 
 } 
 
typedef int QElemType;
#include"c3-2.h"
#include"bo3-2.cpp"
Status DeleteChild(SqBiTree T,position p,int LR)
{//��ʼ������������T���ڣ���ָ��T��ĳ����㣬LRΪ����
//�������������LRΪ0��1��ɾ��T��p��ָ�����������
  int i;
  Status k=OK;
  LinkQueue q;
  InitQueue(q);//��ʼ�����У����ڴ�Ŵ�ɾ���Ľ��
  i=(int)pow(2,p.level-1)+p.order-2;//���㡢�������תΪ��������
  if(T[i]==Nil)
    return ERROR;
  i=i*2+1+LR;//��ɾ�������ĸ�����������е����
  while(k)
  {
  	if(T[2*i+1]!=Nil)//���㲻��
	  EnQueue(q,2*i+1);
	if(T[2*i+2]!=Nil)
	  EnQueue(q,2*i+2);
	T[i]=Nil;
	k=DeQueue(q,i);//���ӽ�����ţ���ֵ����i���ɹ������в��գ�����OK�����򷵻�ERROR 
   } 
  return OK; 
 } 
 
void(*VisitFunc)(TElemType);
void PreTraverse(SqBiTree T,int e)
{//�ݹ��������������T�����Ϊe������
  VisitFunc(T[e]);
  if(T[2*e+1]!=Nil)//���Ϊe�Ľ�������������
    PreTraverse(T,2*e+1);//�ݹ����������T�����Ϊe�Ľ���������
  if(T[2*e+2]!=Nil)
    PreTraverse(T,2*e+2); 
}

void PreOrderTraverse(SqBiTree T,void(*Visit)(TElemType))
{//��ʼ���������������ڣ�visit�ǶԽ�������Ӧ�ú���
//����������������T����ÿ�������ú���Visitһ���ҽ�һ��
  VisitFunc=Visit;
  if(!BiTreeEmpty(T))
    PreTraverse(T,0);//�ݹ����������T�����Ϊ0���� 
  printf("\n"); 
}

void InTraverse(SqBiTree T,int e)
{//�ݹ��������������T�����Ϊe������
  if(T[2*e+1]!=Nil)//���Ϊe�Ľ�������������
    InTraverse(T,2*e+1);//�ݹ����������T�����Ϊe�Ľ���������
  VisitFunc(T[e]);
  if(T[2*e+2]!=Nil)//���Ϊe�Ľ�������������
    InTraverse(T,2*e+2); 
 } 
 
void InOrderTraverse(SqBiTree T,void(*Visit)(TElemType))
{//��ʼ���������������ڣ�Visit�ǶԽ�������Ӧ�ú���
//����������������T����ÿ�������ú���Visitһ���ҽ�һ��
  VisitFunc=Visit;
  if(!BiTreeEmpty(T))
    InTraverse(T,0);//�ݹ���������������Ϊ0����
  printf("\n"); 
}

void PostTraverse(SqBiTree T,int e)
{//�ݹ�������������T�����Ϊe������
  if(T[2*e+1]!=Nil)//���Ϊe�Ľ�������������
    PostTraverse(T,2*e+1);//�ݹ���������T�����Ϊe�Ľ���������
  if(T[2*e+2]!=Nil)
    PostTraverse(T,2*e+2);
  VisitFunc(T[e]);	 
}

void PostOrderTraverse(SqBiTree T,void(*Visit)(TElemType))
{//��ʼ������������T���ڣ�Visit�ǶԽ�������Ӧ�ú���
//����������������T����ÿ�������ú���Visitһ�ν�һ��
  VisitFunc=Visit;
  if(!BiTreeEmpty(T))
    PostTraverse(T,0);//�ݹ���������T�����Ϊ0����
  printf("\n"); 
 } 
 
void LevelOrderTraverse(SqBiTree T,void(*Visit)(TElemType))
{//�������������
  int i=MAX_TREE_SIZE-1,j;
  while(T[i]==Nil)
    i--;//�ҵ����һ���ǿսڵ����� 
  for(j=0;j<=i;j++)//�Ӹ�����𣬰��������������
    if(T[j]!=Nil)
	  Visit(T[j]);//ֻ�����ǿյĽ��  
  printf("\n"); 
}

void Print(SqBiTree T)
{//��㡢������������������T
   int j,k;
   position p;
   TElemType e;
   for(j=1;j<=BiTreeDepth(T);j++)//jΪ��ǰ��
   {
   	printf("��%d��:",j);
   	p.level=j;//��ǰ������ڲ�
    for(k=1;k<=pow(2,j-1);k++)
	{
		p.order=k;//��ǰ����ڱ����˳��
		e=Value(T,p);//�ý���ֵ����e
		if(e!=Nil)
		  printf("%d:"form"",k,e); 
	 } 
	 printf("\n");
	} 
}
