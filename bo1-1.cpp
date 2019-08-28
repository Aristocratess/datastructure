Status InitTriplet(Triplet &T,ElemType v1,Elemtype v2,Elemtype v3)
{
	T=(ElemType*)malloc(3*sizeof(Elemtype));//����3��Ԫ�صĴ洢�ռ� 
	if(!T)
	   exit(OVERFLOW);//����ʧ�����˳�
	T[0]=v1,T[1]=v2,T[2]=v3;
	return OK;   
}

Status DestroyTriplet(Triplet &T)
{
	free(T);//�ͷ�T��ָ����Ԫ��洢�ռ� 
	T=NULL;//T����ָ���κδ洢��Ԫ
	return OK; 
}

Status Get(Triplet T,int i,ElemType &e)
{
	if(i<1||i>3)
	 return ERROR;
	e=T[i-1];//����Ԫ��T�ĵ�i��Ԫ�ص�ֵ����e 
	return OK;
}

Status Put(Triplet T,int i,ElemType e)
{
	if(i<1||i>3)
	  return ERROR;
	T[i-1]=e;//��e��ֵ������Ԫ��T�ĵ�i��Ԫ��
	return OK; 
 } 
 
 Status IsAscending(Triplet T)
 {
 	return(T[0]<=T[1]<=T[2]);//ֻ��T[0]������T[1]��T[1]������T[2]ʱ������ 
 }
 
 Status IsDescending(Triplet T)
 {
 	return(T[0]>=T[1]&&T[1]>=T[2]);
  } 
  
Status Max(Triplet T,ElemType &e)
{
	e=(T[0]>=T[1])?(T[0]>=T[2]?T[0]:T[2]):(T[1]>=T[2]?T[1]:T[2]);
	return OK;
}

Status Min(Triplet T,ElemType &e)
{
	e=(T[0]<=T[1])?(T[0]<=T[2]?T[0]:T[2]):(T[1]<=T[2]?T[1]:T[2]);
	return OK;
}
