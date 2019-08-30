void DestroySMatrix(TSMatrix &M)
{//����ϡ�����M
   M.mu=M.nu=M.tu=0; 
}

void PrintSMatrix(TSMatrix M)
{//��������ʽ���M
  int i,j,k=1;
  Triple *p=M.data+1;//pָ��M�ĵ�1������Ԫ�� 
  for(i=1;i<=M.mu;i++)
  {
  	for(j=1;j<=M.nu;j++)
  	  if(k<=M.tu&&p->i==i&&p->j==j)//pָ�����Ԫ����p��ָԪ��Ϊ��ǰѭ���ڴ���Ԫ��
		{
			printf("%3d",(p++)->e);//���p��ָԪ�ص�ֵ��pָ����һ��Ԫ��
			k++; 
		 } 
	  else
	    printf("%3d",0);
	printf("\n"); 
  }
}

void CopySMatrix(TSMatrix M,TSMatrix &T)
{//��ϡ�����M���Ƶõ�T
   T=M; 
}

Status SubSMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q)
{//��ϡ�����Ĳ�Q=M-N
  int i;
  if(M.mu!=N.nu||M.nu!=N.nu)//M��N��ϡ������л�������ͬ
    return ERROR;
  for(i=1;i<=N.tu;++i)//����N��ÿһԪ�أ���ֵ��-1
    N.data[i].e*=-1;
  AddSMatrix(M,N,Q);//Q=M+��-N)
  return OK; 
}


