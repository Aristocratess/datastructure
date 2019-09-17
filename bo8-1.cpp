void Creat_SeqFromFile(SSTable &ST,char* filename)
{//����������������ļ����쾲̬˳����ұ�ST
  int i;
  FILE* f;
  f=fopen(filename,"r");
  fscanf(f,"%d",&ST.length);
  ST.elem=(ElemType*)calloc(ST.length+1,sizeof(ElemType));
  //��̬����ST.length+1������Ԫ�ؿռ�(0�ŵ�Ԫ���ã�
  if(!ST.elem)
    exit(OVERFLOW);
  for(i=1;i<=ST.length;i++)
    InputFromFile(f,ST.elem[i]); 
    //���ļ��������뾲̬˳����ұ�ST������Ԫ��
  fclose(f); 
}

void Ascend(SSTable &ST)
{//�ؽ���̬���ұ�Ϊ���ؼ��ַǽ�������
  int i,j,k;
  for(i=1;i<ST.length;i++)
  {
  	k=i;
  	ST.elem[0]=ST.elem[i];
  	for(j=i+1;j<=ST.length;j++)
  	  if LT(ST.elem[j].key,ST.elem[0].key)
		{
			k=j;//����ǰԪ�ص���Ŵ���k 
			ST.elem[0]=ST.elem[j];//����ǰԪ�ص�ֵ��[0]��Ԫ 
		 } 
	  if(k!=i)
	  {
	  	ST.elem[k]=ST.elem[i];
		ST.elem[i]=ST.elem[0]; 
	   } 
   } 
}

void Creat_OrdFromFile(SSTable &ST,char* filename)
{//����������ɺ�n������Ԫ�ص�����r���찴�ؼ��ַǽ�����ұ�ST
  Creat_SeqFromFile(ST,filename);
  Ascend(ST); 
}

Status Destroy(SSTable &ST)
{//��ʼ��������̬���ұ�ST���ڡ�  ������������ٱ�ST
  free(ST.elem);
  ST.elem=NULL;
  ST.length=0;
  return OK; 
}

int Search_Seq(SSTable ST,KeyType key)
{//��˳���ST��˳����������ؼ��ֵ���key������Ԫ�ء����ҵ������ظ�Ԫ���ڱ��е�λ�ã����򷵻�0��
   int i;
   ST.elem[0].key=key;//�ڱ����ؼ��ִ�[0]��Ԫ
   for(i=ST.length;!EQ(ST.elem[i].key,key);--i)
   return i; 
}

int Search_Bin(SSTable ST,KeyType key)
{//�������ST���۰���������ؼ��ֵ���key������Ԫ��
//���ҵ����򷵻ظ�Ԫ���ڱ��е�λ�ã����򷵻�0
  int mid,low=1,high=ST.length;
  while(low<=high)
  {
  	mid=(low+high)/2;
  	if EQ(key,ST.elem[mid].key)//��ֵ�Ǵ�����Ԫ��
	   return mid;
	else if LT(key,ST.elem[mid].key)
	   high=mid-1;
	else
	   low=mid+1; 
   } 
   return 0;
}

void Traverse(SSTable ST,void(*Visit)(ElemType))
{//��ʼ��������̬���ұ�ST���ڣ�Visit()�Ƕ�Ԫ�ز�����Ӧ�ú���
//�����������˳���ST��ÿ��Ԫ�ص��ú���Visit()1���ҽ�1��
  int i;
  ElemType *p=++ST.elem;
  for(i=1;i<=ST.length;i++)
     Visit(*p++); 
}
