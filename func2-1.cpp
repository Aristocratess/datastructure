void Union(List &La,List Lb)
{//将所有在线性表Lb中但不在La中的数据元素插入到表La中（不改变表Lb）
   Elemtype e;
   int La_len,Lb_len;
   int i;
   La_len=ListLength(La);//计算线性表La的长度
   Lb_len=ListLength(Lb);
   for(i=1;i<=Lb_len;i++)//从表Lb的第一个元素到最后一个元素
   {
   	GetElem(Lb,i,e);//取表Lb中第i个数据元素的值赋给e
	if(!LocateElem(La,e,equal))//表La中不存在和e相同的元素
	    ListInsert(La,++La_len,e);//在表La的最后插入元素e 
	} 
}

void MergeList(List La,List Lb,List &Lc)
{//已知线性表La和Lb中的数据元素按值非递减排列
//归并La和Lb得到新的线性表Lc，Lc的数据元素也按值非递减排列（不改变表La和表Lb）
   int i=1,j=1,k=0;
   int La_len,Lb_len;
   Elemtype ai,bj;
   InitList(Lc);//创建空表Lc
   La_len=ListLength(La);//求线性表La的长度
   Lb_len=ListLength(Lb);
   while(i<=La_len&&j<=Lb_len)//i,j分别指示表La和表Lb中的元素序号
   {
   	GetElem(La,i,ai);
   	GetELem(Lb,j,bj);
   	if(ai<=bj)//表La的当前元素不大于表Lb的当前元素
	   {
	   	ListInsert(Lc,++k,ai);//在表Lc的最后插入元素ai
		   ++i;//i指示表La中的下一个元素 
		} 
	else 
	{
		ListInsert(Lc,++k,bj);
		++j;
	 } 
	} //以下两个while循环只会有一个被执行
	while(j<=Lb_len)//表Lb中还有元素未插入到表Lc
	{
	GetElem(Lb,j++,bj);//取表Lb中第j个数据元素的值赋给bj，j指示表Lb中的下一个元素
	ListInsert(Lc,++k,bj);//在表Lc的最后插入元素bj 
	} 
 } 
