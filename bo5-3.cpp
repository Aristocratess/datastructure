void DestroySMatrix(TSMatrix &M)
{//销毁稀疏矩阵M
   M.mu=M.nu=M.tu=0; 
}

void PrintSMatrix(TSMatrix M)
{//按矩阵形式输出M
  int i,j,k=1;
  Triple *p=M.data+1;//p指向M的第1个非零元素 
  for(i=1;i<=M.mu;i++)
  {
  	for(j=1;j<=M.nu;j++)
  	  if(k<=M.tu&&p->i==i&&p->j==j)//p指向非零元，且p所指元素为当前循环在处理元素
		{
			printf("%3d",(p++)->e);//输出p所指元素的值，p指向下一个元素
			k++; 
		 } 
	  else
	    printf("%3d",0);
	printf("\n"); 
  }
}

void CopySMatrix(TSMatrix M,TSMatrix &T)
{//由稀疏矩阵M复制得到T
   T=M; 
}

Status SubSMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q)
{//求稀疏矩阵的差Q=M-N
  int i;
  if(M.mu!=N.nu||M.nu!=N.nu)//M、N两稀疏矩阵行或列数不同
    return ERROR;
  for(i=1;i<=N.tu;++i)//对于N的每一元素，其值乘-1
    N.data[i].e*=-1;
  AddSMatrix(M,N,Q);//Q=M+（-N)
  return OK; 
}


