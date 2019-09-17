void Creat_SeqFromFile(SSTable &ST,char* filename)
{//操作结果：由数据文件构造静态顺序查找表ST
  int i;
  FILE* f;
  f=fopen(filename,"r");
  fscanf(f,"%d",&ST.length);
  ST.elem=(ElemType*)calloc(ST.length+1,sizeof(ElemType));
  //动态生成ST.length+1个数据元素空间(0号单元不用）
  if(!ST.elem)
    exit(OVERFLOW);
  for(i=1;i<=ST.length;i++)
    InputFromFile(f,ST.elem[i]); 
    //由文件依次输入静态顺序查找表ST的数据元素
  fclose(f); 
}

void Ascend(SSTable &ST)
{//重建静态查找表为按关键字非降序排序
  int i,j,k;
  for(i=1;i<ST.length;i++)
  {
  	k=i;
  	ST.elem[0]=ST.elem[i];
  	for(j=i+1;j<=ST.length;j++)
  	  if LT(ST.elem[j].key,ST.elem[0].key)
		{
			k=j;//将当前元素的序号存于k 
			ST.elem[0]=ST.elem[j];//将当前元素的值存[0]单元 
		 } 
	  if(k!=i)
	  {
	  	ST.elem[k]=ST.elem[i];
		ST.elem[i]=ST.elem[0]; 
	   } 
   } 
}

void Creat_OrdFromFile(SSTable &ST,char* filename)
{//操作结果：由含n个数据元素的数组r构造按关键字非降序查找表ST
  Creat_SeqFromFile(ST,filename);
  Ascend(ST); 
}

Status Destroy(SSTable &ST)
{//初始条件：静态查找表ST存在。  操作结果：销毁表ST
  free(ST.elem);
  ST.elem=NULL;
  ST.length=0;
  return OK; 
}

int Search_Seq(SSTable ST,KeyType key)
{//在顺序表ST中顺序查找其主关键字等于key的数据元素。若找到，返回该元素在表中的位置，否则返回0。
   int i;
   ST.elem[0].key=key;//哨兵，关键字存[0]单元
   for(i=ST.length;!EQ(ST.elem[i].key,key);--i)
   return i; 
}

int Search_Bin(SSTable ST,KeyType key)
{//在有序表ST中折半查找其主关键字等于key的数据元素
//若找到，则返回该元素在表中的位置，否则返回0
  int mid,low=1,high=ST.length;
  while(low<=high)
  {
  	mid=(low+high)/2;
  	if EQ(key,ST.elem[mid].key)//中值是待查找元素
	   return mid;
	else if LT(key,ST.elem[mid].key)
	   high=mid-1;
	else
	   low=mid+1; 
   } 
   return 0;
}

void Traverse(SSTable ST,void(*Visit)(ElemType))
{//初始条件：静态查找表ST存在，Visit()是对元素操作的应用函数
//操作结果：按顺序对ST的每个元素调用函数Visit()1次且仅1次
  int i;
  ElemType *p=++ST.elem;
  for(i=1;i<=ST.length;i++)
     Visit(*p++); 
}
