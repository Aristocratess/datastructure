#define DestroyString ClearString
void InitString(HString &S)
{//初始化（产生空串）字符串
  S.length=0;
  S.ch=NULL; 
}

void ClearString(HString &S)
{//将Ｓ清为空串
  free(S.ch);
  InitString(S); 
}

void StrAssign(HString &T,char *chars)
{//生成一个其值等于串常量chars的串T
  int i,j;
  if(T.ch)//T指向某存储单元 
    free(T.ch);
  i=strlen(chars);
  if(!i)//chars的长度为0 
    InitString(T);
  else
  {
  	T.ch=(char*)malloc(i*sizeof(char));
  	if(!T.ch)
  	  exit(OVERFLOW);
    for(j=0;j<i;j++)//分配串存储空间成功后，复制串chars[]到串T
	  T.ch[j]=chars[j];
	T.length=i; 
  } 
}

void StrCopy(HString &T,HString S)
{//初始条件：串S存在。 操作结果：由串S复制得串T
  int i;
  if(T.ch)
    free(T.ch);
  T.ch=(char*)malloc(S.length*sizeof(char));
  if(!T.ch)
    exit(OVERFLOW);
  for(i=0;i<S.length;i++)
    T.ch[i]=S.ch[i];
  T.length=S.length; 
 } 

Status StrEmpty(HString S)
{//初始条件:串S存在。 操作结果:若串S为空，则返回TRUE，否则返回FALSE
  if(S.length==0&S.ch==NULL)//空串标志
    return TRUE;
  else
    return FALSE; 
}

int StrCompare(HString S,HString T)
{//若串S>串T，则返回值>0;若S=T，则返回值=0；若S<T，则返回值<0。
  int i;
  for(i=0;i<S.length&&i<T.length;++i)
     if(S.ch[i]!=T.ch[i])
       return S.ch[i]-T.ch[i];//不相等，则返回2字符ASCII码之差
  return S.length-T.length;//在有效范围内，字符相等，但长度不等，返回长度之差 
}

int StrLength(HString S)
{//返回串S的元素个数，称为串的长度
   return S.length; 
 } 
 
void Concat(HString &T,HString S1,HString S2)
{//用串T返回由串S1和串S2连接而成的新串
  int i;
  if(T.ch)
    free(T.ch);
  T.length=S1.length+S2.length;//串T的长度=串S1的长度+串S2的长度
  T.ch=(char*)malloc(T.length*sizeof(char));//分配串T的存储空间
  if(!T.ch)
     exit(OVERFLOW);
  for(i=0;i<S1.length;i++)//将串S1的字符逐一复制给串T
    T.ch[i]=S1.ch[i];
  for(i=0;i<S2.length;i++)//将串S2的字符逐一复制给串T (接在串S1的字符之后)
    T.ch[S1.length+i]=S2.ch[i];
} 

Status SubString(HString &Sub,HString S,int pos,int len)
{//用Sub返回串S的第pos个字符起长度为len的子串，其中，1<=pos<=StrLength(S)且0<=len<=StrLength(S)-pos+1
  int i;
  if(pos<1||pos>S.length||len<0||len>S.length-pos+1)
    return ERROR;
  if(Sub.ch)
    free(Sub.ch);
  if(!len)
    InitString(Sub);
  else
   {
   	Sub.ch=(char*)malloc(len*sizeof(char));
   	if(!Sub.ch)
   	  exit(OVERFLOW);
   	for(i=0;i<=len-1;i++)//将串S第pos个字符起长度为len的子串的字符逐一复制给串Sub
	   Sub.ch[i]=S.ch[pos-1+i];
	Sub.length=len;//串Sub的长度 
	} 
	return OK; 
}

Status StrInsert(HString &S,int pos,HString T)
{//1<=pos<=StrLength(S)+1。在串S的第pos个字符之前插入串T
  int i;
  if(pos<1||pos>S.length+1)
    return ERROR;
  if(T.length)
  {
  	S.ch=(char*)realloc(S.ch,(S.length+T.length)*sizeof(char));//重分S存储空间
	if(!S.ch)
	  exit(OVERFLOW);
	for(i=S.length-1;i>=pos-1;--i) 
	   S.ch[i+T.length]=S.ch[i];
    for(i=0;i<T.length;i++)
       S.ch[pos-1+i]=T.ch[i];
    S.length+=T.length;//更新串S的长度 
   } 
 return OK;
}

Status StrDelete(HString &S,int pos,int len)
{//从串S中删除第pos个字符起长度为len的子串
  int i;
  if(S.length<pos+len-1)
    return ERROR;
  for(i=pos-1;i<=S.length-len;i++)//将待删除子串之后的字符逐一前移
   S.ch[i]=S.ch[i+len];
  S.length-=len;
  S.ch=(char*)realloc(S.ch,S.length*sizeof(char));//重新分配串S的存储空间（减少） 
  return OK;
}

void StrPrint(HString S)
{//输出字符串S
  int i;
  for(i=0;i<S.length;i++)
    printf("%c",S.ch[i]);
  printf("\n"); 
}
