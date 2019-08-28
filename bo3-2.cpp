void InitQueue(LinkQueue &Q)
{//����һ���ն���Q
  Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
  if(!Q.front)
    exit(OVERFLOW);
  Q.front->next=NULL;//ͷ����next��Ϊ�� 
 } 
 
void DestroyQueue(LinkQueue &Q)
{//���ٶ���Q(���ۿշ����)
  while(Q.front)
  {
  	Q.rear=Q.front->next;//Q.rearָ��Q.front����һ�����
	free(Q.front);//�ͷ�Q.front��ָ���
	Q.front=Q.rear;//Q.frontָ��Q.front����һ����� 
   } 
 } 
 
void ClearQueue(LinkQueue &Q)
{//������Q��Ϊ�ն���
  DestroyQueue(Q);
  InitQueue(Q);//���¹���ն���Q 
}

Status QueueEmpty(LinkQueue Q)
{//������QΪ�ն��У��򷵻�TRUE�����򷵻�ERROR
  if(Q.front->next==NULL)
     return TRUE;
  else
     return FALSE; 
 } 
 
 int QueueLength(LinkQueue Q)
 {//�����Q�ĳ���
   int i=0;//����������ֵΪ0
   QueuePtr p=Q.front;//pָ��ͷ���
   while(Q.rear!=p)//p��ָ����β�ڵ�
   {
   	i++;//������+1
	p=p->next;//pָ����һ����� 
	} 
 }

Status GetHead(LinkQueue Q,QElemType &e)
{//������Q���գ�����e����Q�Ķ�ͷԪ�أ�������OK�����򷵻�ERROR
  QueuePtr p;
  if(Q.front==Q.rear)//���п�
     return ERROR;
  p=Q.front->next;//pָ���ͷ���
  e=p->data;//����ͷԪ�ص�ֵ����e
  return OK; 
 } 
 
void EnQueue(LinkQueue &Q,QElemType e)
{//����Ԫ��eΪ����Q���µĶ�βԪ�ء�
   QueuePtr p;
   p=(QueuePtr)malloc(sizeof(QNode));//��̬�����½��
   if(!p)
      exit(OVERFLOW);
   p->data=e;//��ֵe�����½��
   p->next=NULL;//�½���ָ����Ϊ��
   Q.rear->next=p;//ԭ��β����ָ��ָ���½��
   Q.rear=p;//βָ��ָ���½�� 
}

Status DeQueue(LinkQueue &Q,QElemType &e)
{//������Q���գ�ɾ��Q�Ķ�ͷԪ�أ���e������ֵ��������OK�����򷵻�ERROR
   QueuePtr p;
   if(Q.front==Q.rear)//���п�
     return ERROR;
   p=Q.front->next;//pָ���ͷ���
   e=p->data;//����ͷԪ�ص�ֵ����e
   Q.front->next=p->next;//ͷ���ָ����һ�����
   if(Q.rear==p)//ɾ�����Ƕ�β���
     Q.rear=Q.front;//�޸Ķ�βָ��ָ��ͷ��㣨�ն��У�
   free(p);//�ͷŶ�ͷ���
   return OK; 
}

void QueueTraverse(LinkQueue Q,void(*visit)(QElemType))
{//�Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ�ص��ú���visit()
  QueuePtr p=Q.front->next;//pָ���ͷ���
  while(p)//pָ����
  {
  	visit(p->data);//��p��ָԪ�ص���visit()
	p=p->next;//pָ����һ����� 
   } 
   printf("\n"); 
}

