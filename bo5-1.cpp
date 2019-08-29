Status InitArray(Array &A,int dim,...)
{//��ά��dim�͸�ά�����ȺϷ���������Ӧ������A��������Ok
  int elemtotal=1,i;//elemtotal������Ԫ����������ֵΪ1(�۳���)
  va_list ap;//�䳤���������ͣ���stdrag.h��
  if(dim<1||dim>MAX_ARRAY_DIM)
     return ERROR;
  A.dim=dim;//����ά��
  A.bounds=(int*)malloc(dim*sizeof(int));//��̬��������ά���ַ
  if(!A.bounds)
    exit(OVERFLOW);
  va_start(ap,dim);//��ɲ���"..."�����β�dim֮��ʼ
  for(i=0;i<dim;++i)
  {
  	A.bounds[i]=va_arg(ap,int);//��һ���䳤��������A.bounds[i]
	if(A.bounds[i]<0)
	  return UNDERFLOW;
	elemtotal*=A.bounds[i];//����Ԫ������=��ά����֮�˻� 
   } 
   va_end(ap);//������ȡ�䳤����
   A.base=(ElemType*)malloc(elemtotal*sizeof(ElemType));
   if(!A.base)
     exit(OVERFLOW);
   A.constants=(int*)malloc(dim*sizeof(int));
   if(!A.constants)
     exit(OVERFLOW);
   A.constants[dim-1]=1;//���һά��ƫ����Ϊ1
   for(i=dim-2;i>=0;--i)
      A.constants[i]=A.bounds[i+1]*A.constants[i+1];//ÿһγ��ƫ����
   return OK; 
}

void DestroyArray(Array &A)
{//��������A
  if(A.base)//A.baseָ��洢��Ԫ
    free(A.base);
  if(A.bounds)
    free(A.bounds);
  if(A.constants)
    free(A.constants);
  A.base=A.bounds=A.constants=NULL;
  A.dim=0; 
}

Status Locate(Array A,va_list ap,int &off)//Vaule()��Assign()���ô˺���
{//��apָʾ�ĸ��±�ֵ�Ϸ����������Ԫ����A�е���Ե�ַoff
  int i,ind;
  off=0;
  for(i=0;i<A.dim;i++)
  {
  	ind=va_arg(ap,int);//��һ��ȡ��ά���±�ֵ
	if(ind<0||ind>=A.bounds[i])
	   return OVERFLOW;
	off+=A.constants[i]*ind;//��Ե�ַ=��ά���±�ֵ*��ά��ƫ����֮�� 
   } 
  return OK; 
 } 
 
Status Value(ElemType &e,Array A,...)
{//"..."����Ϊ��ά���±�ֵ�������±�Ϸ�����e����ֵΪA����Ӧ��Ԫ��ֵ
  va_list ap;//�䳤���������ͣ���stdarg.h��
  int off;
  va_start(ap,A);//�䳤������...�� ���β�A֮��ʼ
  if(Locate(A,ap,off)==OVERFLOW)//����Locate����,��ñ䳤������ָ��Ԫ����Ե�ַoff
    return ERROR;
  e=*(A.base+off);
  return OK; 
}

Status Assign(Array A,ElemType e,...)//����A��ֵ���䣬�ʲ���Ҫ��
{//"..."����Ϊ��ά���±�ֵ�������±�Ϸ�����e��ֵ����A��ָ����Ԫ��
  va_list ap;//�䳤���������ͣ���stdarg.h��
  int off;
  va_start(ap,e);//�䳤����"..."���β�e֮��ʼ
  if(Locate(A,ap,off)==OVERFLOW)//����Locate()����ñ䳤������ָ��Ԫ����Ե�ַoff
    return ERROR;
  *(A.base+off)=e;//��e��ֵ�����䳤������ָ��Ԫ
  return OK; 
 } 



