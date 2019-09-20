void input(int i,RedType &a)
{//�ӵ�i���ļ�(�鲢��)�����¼��a
  fscanf(fp[i],"%d %d",&a.key,&a.otherinfo); 
}

void output(RedType a)
{//��aд��ȫ�ֱ���fp[k]��ָ���ļ��в����
  static int col=0;
  fprintf(fp[k],"%d %d\n",a.key,a.otherinfo);
  Print(a);
  if(++col%M==0)
    printf("\n"); 
}

void Adjust(LoserTree ls,int s)
{//�ش�Ҷ�ӽ��ȫ�ֱ���b[s]�������ȫ�ֱ���ls[1]��·��������������ʤ�ߴ�ls[0[
  int i,t;
  t=(s+k)/2;//t��ȫ�ֱ���b[s]��˫�׽������
  while(t>0)
  {
  	if(b[s].key>b[ls[t]].key)
  	{
  		i=s;
  		s=ls[t];//sָʾʤ�ߣ�����b[s]��˫�׽���˫�׽��Ƚ� 
  		ls[t]=i;//b[s]��˫�׽��ָʾ����b[s] 
	  }
	t=t/2;//tΪb[s]��˫�׽���˫�׽������ 
   } 
   ls[0]=s;//ʤ�ߴ��ڰ�����֮���[0] 
}

void CreateLoserTree(LoserTree ls)
{//��֪ȫ�ֱ���b[0]~b[k-1]Ϊ��ȫ������ȫ�ֱ���ls��Ҷ�ӽ�㣬����k���ؼ��֣��ش��������Ҷ�ӵ�����k��·����ls������Ϊ������
   int i;
   b[k].key=MIN_KEY;
   for(i=1;i<k;++i)
     ls[i]=k;//����ls��"����"�ĳ�ֵΪ����С�ؼ��ֵ����
   for(i=k-1;i>=0;--i)//���δ��������Ҷ�ӽ��b[k-1]~b[0]��������������
     Adjust(ls,i); 
}

void K_Merge(LoserTree ls)
{//����ȫ�ֱ���������ls����Ŵ�[0]~[k-1]��k������鲢���еļ�¼�鲢������鲢��
//ȫ�ֱ���b[0]~b[k-1]Ϊ�������ϵ�k��Ҷ�ӽ�㣬�ֱ���k������鲢���е�ǰ��¼�Ĺؼ���
  int i;
  for(i=0;i<k;++i)
  {
  	input(i,b[i]);//����öε�1����¼������b[i]
	if(feof(fp[i]))
	  b[i].key=MAX_KEY; 
   } 
  CreateLoserTree(ls);
  //����������ls{1..k-1],������ls[0]ָʾb[0]~b[k-1]�йؼ�����С��(ʤ��)�����
  while(b[ls[0]].key!=MAX_KEY)
  {
  	output(b[ls[0]]);//��b[ls[0]]������ļ�
	input(ls[0],b[ls[0]]);
	if(feof(fp[ls[0]]))
	  b[ls[0]].key=MAX_KEY;
	Adjust(ls,ls[0]);
	//�ش�ȡ����ֵ��Ҷ�ӽ��b[ls[0]]�������ls[1]��·��������������ѡ���µ���С�ؼ��� 
   } 
}
