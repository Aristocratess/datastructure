#include"c1.h"
typedef int ElemType;
#include"c5-2.h"//ϡ��������Ԫ��˳���洢�ṹ
#include"func5-1.cpp"
#include"bo5-2.cpp"
#include"bo5-3.cpp"
void FastTransposeSMatrix(TSMatrix M,TSMatrix &T)
{//������ϡ�����M��ת�þ���T
  int p,q,col,*num,*cpot;
  num=(int*)malloc((M.nu+1)*sizeof(int));//��Mÿ��(Tÿ�У�����Ԫ�ظ���([0]����)
  cpot=(int*)malloc((M.nu+1)*sizeof(int));//��Tÿ����һ������Ԫ�ص�λ��([0]���ã�
  T.mu=M.nu;
  T.nu=M.mu;
  T.tu=M.tu;//T�ķ���Ԫ�ظ���=M�ķ���Ԫ�ظ���
  if(T.tu)
   {
   	for(col=1;col<=M.nu;++col)
   	  num[col]=0;//��������ֵ��Ϊ0
    for(p=1;p<=M.tu;++p)
	  ++num[M.data[p].j];
	cpot[1]=1;
	for(col=2;col<=M.nu;++col)//��M(T)�ĵ�2��(��)�����һ��(��)
	   cpot[col]=cpot[col-1]+num[col-1];//��T�ĵ�col�е�1������Ԫ��T.data�е����
	for(p=1;p<=M.tu;++p)
	{
		col=M.data[p].j;//������M�е���������col
		T.data[q].i=M.data[p].j;//��M��ǰ��Ԫ��ת�ȸ���T 
		T.data[q].j=M.data[p].i;
		T.data[q].e=M.data[p].e;
		++cpot[col];//T��col�е���1������Ԫ��T.data�е���űȵ�ǰԪ�ص���Ŵ�1 
	 } 
	} 
	free(num);
	free(cpot);
 } 
 
int main()
{
	TSMatrix A,B;
	printf("��������A��");
	CreateSMatrix(A);
	PrintSMatrix(A);
	FastTransposeSMatrix(A,B);//B��A��ת�Ⱦ���
	printf("����B(A�Ŀ���ת��):\n");
	PrintSMatrix(B); 
}
 
