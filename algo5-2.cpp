#include"c1.h"
typedef int ElemType;
#include"c5-2.h"//稀疏矩阵的三元组顺序表存储结构
#include"func5-1.cpp"
#include"bo5-2.cpp"
#include"bo5-3.cpp"
void FastTransposeSMatrix(TSMatrix M,TSMatrix &T)
{//快速求稀疏矩阵M的转置矩阵T
  int p,q,col,*num,*cpot;
  num=(int*)malloc((M.nu+1)*sizeof(int));//存M每列(T每行）非零元素个数([0]不用)
  cpot=(int*)malloc((M.nu+1)*sizeof(int));//存T每行下一个非零元素的位置([0]不用）
  T.mu=M.nu;
  T.nu=M.mu;
  T.tu=M.tu;//T的非零元素个数=M的非零元素个数
  if(T.tu)
   {
   	for(col=1;col<=M.nu;++col)
   	  num[col]=0;//计数器初值设为0
    for(p=1;p<=M.tu;++p)
	  ++num[M.data[p].j];
	cpot[1]=1;
	for(col=2;col<=M.nu;++col)//从M(T)的第2列(行)到最后一列(行)
	   cpot[col]=cpot[col-1]+num[col-1];//求T的第col行第1个非零元在T.data中的序号
	for(p=1;p<=M.tu;++p)
	{
		col=M.data[p].j;//将其在M中的列数赋给col
		T.data[q].i=M.data[p].j;//将M当前的元素转秩赋给T 
		T.data[q].j=M.data[p].i;
		T.data[q].e=M.data[p].e;
		++cpot[col];//T第col行的下1个非零元在T.data中的序号比当前元素的序号大1 
	 } 
	} 
	free(num);
	free(cpot);
 } 
 
int main()
{
	TSMatrix A,B;
	printf("创建矩阵A：");
	CreateSMatrix(A);
	PrintSMatrix(A);
	FastTransposeSMatrix(A,B);//B是A的转秩矩阵
	printf("矩阵B(A的快速转置):\n");
	PrintSMatrix(B); 
}
 
