int main()
{
	int i;
	QElemType d;
	LinkQueue q;
	InitQueue(q);//����ն���q,ʧ�����˳�
	printf("�ɹ��ع�����һ���ն���\n");
	printf("�Ƿ�ն���?%d(1:�� 0����)��",QueueEmpty(q));
	printf("���еĳ���Ϊ%d\n",QueueLength(q));
	EnQueue(q,-5);//�������3��Ԫ��
	EnQueue(q,5);
	EnQueue(q,10);
	printf("����3��Ԫ��(-5,5,10)�󣬶��еĳ���Ϊ%d\n",QueueLength(q));
	printf("�Ƿ�ն��У�%d(1:�� 0����)��",QueueEmpty(q));
	printf("���е�Ԫ������Ϊ");
	QueueTraverse(q,print);//�Ӷ�ͷ����β���ζԶ���q��ÿ��Ԫ�ص��ú���print()
	i=GetHead(q,d);//����ͷԪ�ظ���d
	if(i==OK)//����q����
	  printf("ɾ���˶�ͷԪ��%d,",d);
	ClearQueue(q);//��ն���Q
	printf("��ն��к�q.front=%u,q.rear=%u,q.front->next=%u\n",q.front,q.rear,q.front->next); 
	DestroyQueue(q);//���ٶ���q
	printf("���ٶ��к�q.front=%u,q.rear=%u\n",q.front,q.rear); 
}
