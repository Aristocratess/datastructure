int Partition(SqList &L,int low,int high)
{//����˳���L���ӱ�L.r[low..high]�ļ�¼��ʹ�����¼��λ��������������λ�ã���ʱ����֮ǰ(��)�ļ�¼������(С)����
  RedType t;
  KeyType pivotkey;
  pivotkey=L.r[low].key;
  while(low<high)
  {//�ӱ�����˽�������м�ɨ�� 
  	while(low<high&&L.r[high].key>=pivotkey)
  	  --high;
  	t=L.r[low];//��������ؼ���С�ļ�¼�������Ͷˣ����ᵽ�߶� 
  	L.r[low]=L.r[high];
  	L.r[high]=t;
  	while(low<high&&L.r[low].key<=pivotkey)
  	  ++low;
  	t=L.r[low];//��������ؼ��ִ�ļ�¼�������߶ˣ����ᵽ�Ͷ� 
  	L.r[low]=L.r[high];
  	L.r[high]=t;
   } 
   return low;
}


