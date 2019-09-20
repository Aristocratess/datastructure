void input(int i,RedType &a)
{//从第i个文件(归并段)读入记录到a
  fscanf(fp[i],"%d %d",&a.key,&a.otherinfo); 
}

void output(RedType a)
{//将a写至全局变量fp[k]所指的文件中并输出
  static int col=0;
  fprintf(fp[k],"%d %d\n",a.key,a.otherinfo);
  Print(a);
  if(++col%M==0)
    printf("\n"); 
}

void Adjust(LoserTree ls,int s)
{//沿从叶子结点全局变量b[s]到根结点全局变量ls[1]的路径调整败者树，胜者存ls[0[
  int i,t;
  t=(s+k)/2;//t是全局变量b[s]的双亲结点的序号
  while(t>0)
  {
  	if(b[s].key>b[ls[t]].key)
  	{
  		i=s;
  		s=ls[t];//s指示胜者，将和b[s]的双亲结点的双亲结点比较 
  		ls[t]=i;//b[s]的双亲结点指示败者b[s] 
	  }
	t=t/2;//t为b[s]的双亲结点的双亲结点的序号 
   } 
   ls[0]=s;//胜者存于败者树之外的[0] 
}

void CreateLoserTree(LoserTree ls)
{//已知全局变量b[0]~b[k-1]为完全二叉树全局变量ls的叶子结点，存有k个关键字，沿从序号最大的叶子到根的k条路径将ls调整成为败者树
   int i;
   b[k].key=MIN_KEY;
   for(i=1;i<k;++i)
     ls[i]=k;//设置ls中"败者"的初值为有最小关键字的序号
   for(i=k-1;i>=0;--i)//依次从序号最大的叶子结点b[k-1]~b[0]出发调整败者树
     Adjust(ls,i); 
}

void K_Merge(LoserTree ls)
{//利用全局变量败者树ls将编号从[0]~[k-1]的k个输入归并段中的记录归并到输出归并段
//全局变量b[0]~b[k-1]为败者树上的k个叶子结点，分别存放k个输入归并段中当前记录的关键字
  int i;
  for(i=0;i<k;++i)
  {
  	input(i,b[i]);//读入该段第1个记录到外结点b[i]
	if(feof(fp[i]))
	  b[i].key=MAX_KEY; 
   } 
  CreateLoserTree(ls);
  //初建败者树ls{1..k-1],树外结点ls[0]指示b[0]~b[k-1]中关键字最小者(胜者)的序号
  while(b[ls[0]].key!=MAX_KEY)
  {
  	output(b[ls[0]]);//将b[ls[0]]输出到文件
	input(ls[0],b[ls[0]]);
	if(feof(fp[ls[0]]))
	  b[ls[0]].key=MAX_KEY;
	Adjust(ls,ls[0]);
	//沿从取得新值的叶子结点b[ls[0]]到根结点ls[1]的路径调整败者树，选出新的最小关键字 
   } 
}
