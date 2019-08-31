Status CreateSMatrix(RLSMatrix &M)
{
	int i,j;
	Triple T;
	Status k;
	printf("��������������������������Ԫ�ظ���:");
	scanf("%d,%d,%d",&M.mu,&M.nu,&M.tu);
	if(M.tu>MAX_SIZE||M.mu>MAX_RC)
	  return ERROR;
	M.data[0].i=0;
	for(i=1;i<=M.tu;i++)
	{do
	{
		printf("�밴����˳�������%d������Ԫ�����ڵ���(1~%d),��(1~%d)��Ԫ��ֵ��",i,M.mu,M.nu);
		scanf("%d,%d,%d",&T.i,&T.j,&T.e);
		k=0;
		if(T.i<1||T.i>M.mu||T.j<1||T.j>M.nu)
		  k=1;
	    if(T.i<M.data[i-1].i||T.i==M.data[i-1].i&&T.j<=M.data[i-1].j)
	      k=1;
	}while(k);
	M.data[i]=T;//��������ȷ��ֵ����M����Ӧ�洢��Ԫ 
	}
    for(i=1;i<=M.mu;i++)//��rpos[]����ֵ1(ÿ�е�1������Ԫ�صĳ�ʼλ��)
	   M.rpos[i]=1;
	for(i=1;i<=M.tu;i++)//����ÿ������Ԫ�أ�����ͳ�ƣ�������rpos[]
	  for(j=M.data[i].i+1;j<=M.mu;j++)
	     M.rpos[j]++;
    return OK; 
}

Status AddSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix &Q)
{//��ϡ�����ĺ�Q=M+N
  int k,p,q,up,uq;
  if(M.mu!=M.mu||M.nu!=N.nu)
    return ERROR;
  Q.mu=M.mu;
  Q.nu=M.nu;
  Q.tu=0;
  for(k=1;k<=M.mu;++k)
  {Q.rpos[k];//pָʾ����M��k�е�ǰԪ�ص����
   p=M.rpos[k];//pָʾ����M��k�е�ǰԪ�ص����
   q=N.rpos[k];//qָʾ����N��k�е�ǰԪ�ص����
   if(k<M.mu)
   {
   	up=M.rpos[k+1];
   	uq=N.rpos[k+1];
	} 
   else
   {
   	up=M.tu+1;
   	uq=N.tu+1;
   }
   while(p<up&&q<uq)
     switch(comp(M.data[p].j,N.data[q].j))//�Ƚ�����ǰԪ�ص���ֵ��ϵ
	  {//����M��ǰԪ�ص���<����N��ǰ���У���M�ĵ�ǰԪ��ֵ��������Q,p�����
	    case -1:Q.data[++Q.tu]=M.data[p++];
		        break;
		case 0:if(M.data[p].e+N.data[q].e!=0)
	           {//����M��ǰԪ�ص���=����N��ǰԪ�ص��У�����Ͳ�Ϊ0
			    Q.data[++Q.tu]=M.data[p];//��M�ĵ�ǰԪ��ֵ��������Q
				Q.data[Q.tu].e+=N.data[q].e;//��N�ĵ�ǰԪ��ֵ�г�Աe��ֵ�������� 
				} 
				p++;//p��q������ƣ����ۺ��Ƿ�Ϊ0
				q++;
				break;
		//����M��ǰԪ�ص���>����N��ǰԪ�ص��У���N�ĵ�ǰԪ��ֵ��������Q��q�����
		case 1:Q.data[++Q.tu]=N.data[q++]; 
		 } //����2��ѭ�����ִ��1�� 
	  	while(p<M.rpos[k+1]&&p<=M.tu)//N�ĵ�k��Ԫ����ȫ������M���е�k�е�Ԫ��δ����
		   Q.data[++Q.tu]=M.data[p++];//��M�ĵ�ǰֵ����Q,p�����
		while(q<N.rpos[k+1]&&q<=N.tu)//M�ĵ�k��Ԫ����ȫ������N���е�k�е�Ԫ��δ����
		   Q.data[++Q.tu]=N.data[q++];//��N�ĵ�ǰֵ����Q,q����� 
	   } 
	 if(Q.tu>MAX_SIZE)
	    return ERROR;
	 else
	    return OK; 
   } 
   
void TransposeSMatrix(RLSMatrix M,RLSMatrix &T)
{//��ϡ�����M��ת�þ���T
  int i,j,k,num[MAX_RC+1];//[0]����
  T.mu=M.nu;
  T.nu=M.mu;
  T.tu=M.tu;//����T�ķ���Ԫ�ظ���=����M�ķ���Ԫ�ظ���
  if(T.tu)
  {
  	for(i=1;i<T.mu;++i)
  	  num[i]=0;
    for(i=1;i<=M.tu;++i)
      ++num[M.data[i].j];//num[]=T��ÿ��(M��ÿ��)����Ԫ�ظ�����
	T.rpos[1]=1;//����T�е�1�еĵ�1������Ԫ�ص������1
	for(i=2;i<=T.mu;++i)
	   T.rpos[i]=T.rpos[i-1]+num[i-1];//��T�е�i�еĵ�1������Ԫ�ص����
	for(i=1;i<=T.mu;++i)
	   num[i]=T.rpos[i];//num[]=M�ĵ�ǰ����Ԫ����T��Ӧ��ŵ�λ��
	for(i=1;i<=M.tu;++i)//����M�е�ÿһ������Ԫ��
	{
		j=M.data[i].j;//�ھ���T�е�����
		k=num[j]++;//�ھ���T�е���ţ�num[j]+1
		T.data[k].i=M.data[i].i;
		T.data[k].e=M.data[i].e;
		T.data[k].e=M.data[i].e;
	 } 
   } 
}

Status MultSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix &Q)
{//��ϡ�����˻�Q=M��N
  int arow,brow,p,q,ccol,ctemp[MAX_RC+1],t,tp;
  if(M.nu!=N.mu)//����M��N�޷����
    return ERROR;
  Q.mu=M.mu;
  Q.nu=N.nu;
  Q.tu=0;//Q�ķ���Ԫ�ظ���
  if(M.tu*N.tu!=0)
  for(arow=1;arow<=M.mu;++arow)
  {
  	for(ccol=1;ccol<=Q.nu;++ccol)//��Q�ĵ�1�е����һ��
	   ctemp[ccol]=0;//Q�ĵ�ǰ�еĸ���Ԫ���ۼ�������
	Q.rpos[arow]=Q.tu+1;
	if(arow<M.mu)
	   tp=M.rpos[arow+1];//��һ�еĵ�1��Ԫ�ص�λ���Ǳ���Ԫ�ص��Ͻ�
	else
	   tp=M.tu+1;//�����һ�����Ͻ�
	for(p=M.rpos[arow];p<tp;++p)//��M��ǰ����ÿһ������Ԫ
	{
		brow=M.data[p].j;//�ҵ���ӦԪ��N�е��к�(M��ǰԪ���к�)
		if(brow<N.mu)
		  t=N.rpos[brow+1];//��һ�еĵ�1��Ԫ�ص�λ���Ǳ���Ԫ�ص��Ͻ�
		else
		  t=N.tu+1;
		for(q=N.rpos[brow];q<t;++q)//��N��ǰ����ÿһ������Ԫ
		{
			ccol=N.data[q].j;//�˻�Ԫ����Q�е��к�
			ctemp[ccol]+=M.data[p].e*N.data[q].e;//���˻��ۼӵ�Q��arow��ccol���� 
		 } 
	 } //���Q�е�arow�е������е�Ԫ��ֵ������ctemp[]��
	 for(ccol=1;ccol<=Q.nu;++ccol)
	  if(ctemp[ccol])
	  {
	  	if(++Q.tu>MAX_SIZE)
	  	  return ERROR;
	  	Q.data[Q.tu].i=arow;
	  	Q.data[Q.tu].j=ccol;
	  	Q.data[Q.tu].e=ctemp[ccol];
	   }     
   } 
   return OK;
 } 
 
 Status MultSMatrix1(RLSMatrix M,RLSMatrix N,RLSMatrix &Q)
 {//��һ����ϡ�����˻�Q=M��N�ķ���(��ʹ����ʱ���飬����N��ת�Ⱦ���T)
   int i,j,q,p,up,uq;
   ElemType Qs;//����ԪQ[i][j]����ʱ��Ŵ�
   RLSMatrix T;//N��ת�Ⱦ���
   if(M.nu!=N.mu)
     return ERROR;
   Q.mu=M.mu;
   Q.nu=N.nu;
   Q.tu=0;
   TransposeSMatrix(N,T);
   for(i=1;i<=Q.mu;i++)
     for(j=1;j<=Q.nu;j++)
	 {
	 	Qs=0;
	 	p=M.rpos[i];
	 	q=T.rpos[j];
	 	if(i<M.mu)
	 	 up=M.rpos[i+1];
	 	else
	 	 up=M.tu+1;
	 	if(j<T.mu)
	 	 uq=T.rpos[j+1];
	 	else
	 	 uq=T.tu+1;
	 	while(p<up&&q<uq)//p��q�ֱ�ָʾ����M��T�е�i��j��Ԫ��
		  switch(comp(M.data[p].j,T.data[q].j))
		  {//�Ƚ�M����ǰԪ�ص���ֵ��T����ǰԪ�ص���ֵ(��N����ǰԪ�ص���ֵ)
		    case -1:p++;//M����ǰԪ�ص���ֵ<T(N)����ǰԪ�ص���(��)ֵ��p�����
			        break;
		    case 0:Qs+=M.data[p++].e*T.data[q++].e;
		            break;
		    case 1:q++;//M����ǰԪ�ص���ֵ>T(N)����ǰԪ�ص���(��)ֵ��q����� 
		   } 
		if(Qs)//Q[i][j]��Ϊ0
		{
			if(++Q.tu>MAX_SIZE)
			  return ERROR;
			Q.data[Q.tu].i=i;//��Q[i][j]��˳�����ϡ�����
			Q.data[Q.tu].j=j;
			Q.data[Q.tu].e=Qs; 
		 } 
	  } 
	return OK;
 }
 
 
