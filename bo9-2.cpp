void QSort(SqList &L,int low,int high)
{//��˳���L�е�������L,r[low..high]����������
  int pivotloc;
  if(low<high)
  {
  	pivotloc=Partition(L,low,high);
  	//��L.r[low..high]���ؼ���һ��Ϊ����pivotloc������λ��
	QSort(L,low,pivotloc-1);//�Թؼ���С������ؼ��ֵĵ��ӱ�ݹ��������
	QSort(L,pivotloc+1,high);//�Թؼ��ִ�������ؼ��ֵĸ��ӱ�ݹ�������� 
   } 
}

void QuickSort(SqList &L)
{//��˳���L����������
  QSort(L,1,L.length); 
 } 
