enum ElemTag{ATOM,LIST
};
typedef struct GLNodel{
	ElemTag tag;//公共部分，用于区分原子结点和表结点
	union//原子结点和表结点的联合部分
	{
		AtomType atom;//原子结点的值域
		GLNodel *hp;//表结点的表头指针 
	 };
	 GLNodel *tp;//相当于线性链表的next，指向下一个元素结点 
}*GList,GLNode1;//广义表类型GListl是一种扩展的线性链表 
