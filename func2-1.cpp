void Union(List &La,List Lb)
{//�����������Ա�Lb�е�����La�е�����Ԫ�ز��뵽��La�У����ı��Lb��
   Elemtype e;
   int La_len,Lb_len;
   int i;
   La_len=ListLength(La);//�������Ա�La�ĳ���
   Lb_len=ListLength(Lb);
   for(i=1;i<=Lb_len;i++)//�ӱ�Lb�ĵ�һ��Ԫ�ص����һ��Ԫ��
   {
   	GetElem(Lb,i,e);//ȡ��Lb�е�i������Ԫ�ص�ֵ����e
	if(!LocateElem(La,e,equal))//��La�в����ں�e��ͬ��Ԫ��
	    ListInsert(La,++La_len,e);//�ڱ�La��������Ԫ��e 
	} 
}

void MergeList(List La,List Lb,List &Lc)
{//��֪���Ա�La��Lb�е�����Ԫ�ذ�ֵ�ǵݼ�����
//�鲢La��Lb�õ��µ����Ա�Lc��Lc������Ԫ��Ҳ��ֵ�ǵݼ����У����ı��La�ͱ�Lb��
   int i=1,j=1,k=0;
   int La_len,Lb_len;
   Elemtype ai,bj;
   InitList(Lc);//�����ձ�Lc
   La_len=ListLength(La);//�����Ա�La�ĳ���
   Lb_len=ListLength(Lb);
   while(i<=La_len&&j<=Lb_len)//i,j�ֱ�ָʾ��La�ͱ�Lb�е�Ԫ�����
   {
   	GetElem(La,i,ai);
   	GetELem(Lb,j,bj);
   	if(ai<=bj)//��La�ĵ�ǰԪ�ز����ڱ�Lb�ĵ�ǰԪ��
	   {
	   	ListInsert(Lc,++k,ai);//�ڱ�Lc��������Ԫ��ai
		   ++i;//iָʾ��La�е���һ��Ԫ�� 
		} 
	else 
	{
		ListInsert(Lc,++k,bj);
		++j;
	 } 
	} //��������whileѭ��ֻ����һ����ִ��
	while(j<=Lb_len)//��Lb�л���Ԫ��δ���뵽��Lc
	{
	GetElem(Lb,j++,bj);//ȡ��Lb�е�j������Ԫ�ص�ֵ����bj��jָʾ��Lb�е���һ��Ԫ��
	ListInsert(Lc,++k,bj);//�ڱ�Lc��������Ԫ��bj 
	} 
 } 
