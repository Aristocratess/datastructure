int Partition(SqList &L,int low,int high)
{//交换顺序表L中子表r[low..high]的记录，枢轴记录到位，并返回其所在位置，此时在它之前(后)的记录均不大(小)于它
  KeyType pivotkey;
  pivotkey=L.r[low].key;//用子表的第1个记录作初始枢轴记录 
  L.r[0]=L.r[low]; //将枢轴记录保存到[0]，改进处
  while(low<high)
  {//从表的两端交替地向中间扫描
    while(low<high&&L.r[high].key>=pivotkey)//高端记录的关键字大于枢轴关键字
	   --high;
	L.r[low]=L.r[high];//将比枢轴关键字小的记录移到低端，枢轴在[0]不动，改进处
	while(low<high&&L.r[low].key<=pivotkey)
	   ++low; 
	L.r[high]=L.r[low];
   } 
   L.r[low]=L.r[0];
   return low;
}


