int main()
{
	LinkList L;
	ElemType e,e0;
	Status i;
	int j,k;
	InitList(L);//��ʼ�����Ա�L
	for(j=1;j<=5;j++)
	  i=ListInsert(L,1,j);//��L�ı�ͷ����j
	printf("��L�ı�ͷ���β���1~5��L=");
	ListTraverse(L,print);//���ζ�Ԫ�ص���print����,���Ԫ�ص�ֵ
	i=ListEmpty(L);//����L�Ƿ��
	printf("L�Ƿ�գ�i=%d(1:�ǣ�0:��)����L�ĳ���=%d\n",i,ListLength(L)); 
	ClearList(L);//��ձ�L
	printf("���L��L=");
	ListTraverse(L,print);
	i=ListEmpty(L);//�ٴμ���L�Ƿ��
	printf("L�Ƿ�գ�i=%d(1:�� 0����)����L�ĳ���=%d\n",i,ListLength(L));
	for(j=1;j<=10;j++)
	  ListInsert(L,j,j);//�ڱ�β����j
	printf("��L�ı�β���β���1~10��L=");
	ListTraverse(L,print);//���������L�е�Ԫ��
	for(j=0;j<=1;j++)
	{
	#ifdef SLL//�����ھ�̬����
	   k=LocateElem(L,j);//���ұ�L����j��ȵ�Ԫ�أ�������λ�򸳸�k
	   if(k) //k��Ϊ0�������з���������Ԫ��
	    printf("ֵΪ%d��Ԫ�ص�λ��Ϊ%d\n",j,k);
	#else//����������
	   k=LocateElem(L,j,equal);//���ұ�L����j��ȵ�Ԫ�أ��������������е����򸳸�k
	   if(k)//k��Ϊ0�������з���������Ԫ��
	     printf("��%d��Ԫ�ص�ֵΪ%d\n",k,j);
    #endif
	
	   else//kΪ0��û�з���������Ԫ��
	     printf("û��ֵΪ%d��Ԫ��,",j); 
	 } 
	 for(j=1;j<=2;j++)//����ͷ2������
	 {
	 	GetElem(L,j,e0);//�ѱ�L�еĵ�j�����ݸ���e0
		i=PriorElem(L,e0,e);//��e0��ǰ������ɹ�����ֵ����e
		if(i==ERROR)
		  printf("Ԫ��%d��ǰ����",e0);
		else
		  printf("Ԫ��%d��ǰ��Ϊ%d\n",e0,e); 
	  } 
	for(j=ListLength(L)-1;j<=ListLength(L);j++)//���2������
	{
		GetElem(L,j,e0);//�ѱ�L�еĵ�j�����ݸ���e0
		i=NextElem(L,e0,e);//��e0�ĺ�̣���ɹ�����ֵ����e
		if(i==ERROR)
		  printf("Ԫ��%d�޺��\n",e0);
		else
		  printf("Ԫ��%d�ĺ��Ϊ%d��",e0,e); 
	 } 
	 k=ListLength(L);//kΪ��
	 for(j=k+1;j>=k;j--)
	 {
	 	i=ListDelete(L,j,e);//ɾ����j������
		if(i==ERROR)
		  printf("ɾ����%d��Ԫ��ʧ�ܣ������ڴ�Ԫ�أ���",j);
		else 
		  printf("ɾ����%d��Ԫ�سɹ�����ֵΪ%d\n",j,e); 
	  } 
	  printf("�������L��Ԫ��:");
	  ListTraverse(L,print);//���������L�е�Ԫ��
	  DestroyList(L);//���ٱ�L
	 #ifdef SLL
	   printf("����L��L=%u\n",L);
	 #endif 
 } 
