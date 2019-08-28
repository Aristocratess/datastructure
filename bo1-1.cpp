Status InitTriplet(Triplet &T,ElemType v1,Elemtype v2,Elemtype v3)
{
	T=(ElemType*)malloc(3*sizeof(Elemtype));//分配3个元素的存储空间 
	if(!T)
	   exit(OVERFLOW);//分配失败则退出
	T[0]=v1,T[1]=v2,T[2]=v3;
	return OK;   
}

Status DestroyTriplet(Triplet &T)
{
	free(T);//释放T所指的三元组存储空间 
	T=NULL;//T不再指向任何存储单元
	return OK; 
}

Status Get(Triplet T,int i,ElemType &e)
{
	if(i<1||i>3)
	 return ERROR;
	e=T[i-1];//将三元组T的第i个元素的值赋给e 
	return OK;
}

Status Put(Triplet T,int i,ElemType e)
{
	if(i<1||i>3)
	  return ERROR;
	T[i-1]=e;//将e的值赋给三元组T的第i个元素
	return OK; 
 } 
 
 Status IsAscending(Triplet T)
 {
 	return(T[0]<=T[1]<=T[2]);//只在T[0]不大于T[1]且T[1]不大于T[2]时返回真 
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
