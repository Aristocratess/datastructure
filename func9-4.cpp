int Partition(SqList &L,int low,int high)
{//����˳���L���ӱ�r[low..high]�ļ�¼�������¼��λ��������������λ�ã���ʱ����֮ǰ(��)�ļ�¼������(С)����
  KeyType pivotkey;
  pivotkey=L.r[low].key;//���ӱ�ĵ�1����¼����ʼ�����¼ 
  L.r[0]=L.r[low]; //�������¼���浽[0]���Ľ���
  while(low<high)
  {//�ӱ�����˽�������м�ɨ��
    while(low<high&&L.r[high].key>=pivotkey)//�߶˼�¼�Ĺؼ��ִ�������ؼ���
	   --high;
	L.r[low]=L.r[high];//��������ؼ���С�ļ�¼�Ƶ��Ͷˣ�������[0]�������Ľ���
	while(low<high&&L.r[low].key<=pivotkey)
	   ++low; 
	L.r[high]=L.r[low];
   } 
   L.r[low]=L.r[0];
   return low;
}


