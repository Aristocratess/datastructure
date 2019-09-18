void InitHashTable(HashTable &H)
{//�������������һ���յĹ�ϣ��
  int i;
  H.count=0;
  H.sizeindex=0;
  m=hashsize[0];
  H.elem=(ElemType*)malloc(m*sizeof(ElemType));
  if(!H.elem)
    exit(OVERFLOW);
  for(i=0;i<m;i++)
    H.elem[i].key=NULL_KEY; 
}

void DestroyHashTable(HashTable &H)
{//��ʼ��������ϣ��H���ڡ�  ������������ٹ�ϣ��H
  free(H.elem);
  H.elem=NULL;
  H.count=0;
  H.sizeindex=0; 
}

unsigned Hash(KeyType K)
{//һ���򵥵Ĺ�ϣ����
   return K%m; 
}

int d(int i)
{
	return i;
}

void collision(KeyType K,int &p,int i)
{
	p=(Hash(K)+d(i))%m;
}

Status SearchHash(HashTable H,KeyType K,int &p,int &c)
{//�ڿ��Ŷ�ַ��ϣ��H�в��ҹؼ���ΪK��Ԫ�أ������ҳɹ�����pָʾ��������
//Ԫ���ڱ���λ�ã�������SUCCESS��������pָʾ����λ�ã�������UNSUCCESS
//c���ԼƳ�ͻ���������ֵ���㣬���������ʱ�ο�
  p=Hash(K);
  while(H.elem[p].key!=NULL_KEY&&!EQ(K,H.elem[p].key))
  {//��λ�������м�¼������������ҵĹؼ��ֲ����
    c++;
	if(c<m)
	  collision(K,p,c);
	else
	  break;  
   } 
   if EQ(K,H.elem[p].key)
     return SUCCESS;
   else
     return UNSUCCESS;
}

void RecreateHashTable(HashTable&);
Status InsertHash(HashTable &H,ElemType e)
{//���Ҳ��ɹ�ʱ��������Ԫ��e�����Ŷ�ַ��ϣ��H�У�������OK
//����ͻ��������3�����ؽ���ϣ��
  int p,c=0;
  if(SearchHash(H,e.key,p,c))
     return DUPLICATE;
  else if(c<hashsize[H.sizeindex]/2)
  {
  	H.elem[p]=e;
  	++H.count;
  	return OK;
   } 
  else
  {
  	RecreateHashTable(H);
  	return UNSUCCESS;
  }
}

void RecreateHashTable(HashTable &H)
{//�ؽ���ϣ��H
  int i,count=H.count; 
  ElemType *p,*elem=(ElemType*)malloc(count*sizeof(ElemType));
  //��̬���ɴ�Ź�ϣ��Hԭ�����ݵĿռ�
  p=elem;
  for(i=0;i<m;i++)
    if((H.elem+i)->key!=NULL_KEY)
	  *p++=*(H.elem+i);
  H.count=0;
  H.sizeindex++;
  m=hashsize[H.sizeindex];
  H.elem=(ElemType*)realloc(H.elem,m*sizeof(ElemType));
  for(i=0;i<m;i++)
    H.elem[i].key=NULL_KEY;
  for(p=elem;p<elem+count;p++)
    InsertHash(H,*p);
  free(elem);
}
  
void TraverseHash(HashTable H,void(*Visit)(int,ElemType))
{//����ϣ��ַ��˳�������ϣ��H
   int i;
   printf("��ϣ��ַ0~%d\n",m-1);
   for(i=0;i<m;i++)
     if(H.elem[i].key!=NULL_KEY)
	   Visit(i,H.elem[i]); 
 } 
