int Partition(SqList &L,int low,int high)
{//交换顺序表L中子表L.r[low..high]的记录，使枢轴记录到位，并返回其所在位置，此时在它之前(后)的记录均不大(小)于它
  RedType t;
  KeyType pivotkey;
  pivotkey=L.r[low].key;
  while(low<high)
  {//从表的两端交替地向中间扫描 
  	while(low<high&&L.r[high].key>=pivotkey)
  	  --high;
  	t=L.r[low];//将比枢轴关键字小的记录交换到低端，枢轴到高端 
  	L.r[low]=L.r[high];
  	L.r[high]=t;
  	while(low<high&&L.r[low].key<=pivotkey)
  	  ++low;
  	t=L.r[low];//将比枢轴关键字大的记录交换到高端，枢轴到低端 
  	L.r[low]=L.r[high];
  	L.r[high]=t;
   } 
   return low;
}


