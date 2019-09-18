void R_Rotate(BSTree &p)
{//对以*p为根的二叉排序树作右旋转处理，使二叉排序树的重心右移，但不修改平衡因子
//处理之后p指向新的树根结点，即旋转处理之前的左子树的根结点
  BSTree lc;
  lc=p->lchild;
  p->lchild=lc->rchild;
  lc->rchild=p;
  p=lc; 
}

void L_Rotate(BSTree &p)
{//对以*p为根的二叉排序树作左旋处理，使二叉排序树的重心左移，但不修改平衡因子
//处理之后p指向新的树根结点，即旋转处理之前的右子树的根结点
  BSTree rc;
  rc=p->rchild;
  p->rchild=rc->lchild;
  rc->lchild=p;
  p=rc;
}

void LR_Rotate(BSTree &p)
{//对以*p为根的平衡二叉树的LR型失衡，直接进行平衡旋转处理，不修改平衡因子
    BSTree lc=p->lchild; 
    p->lchild=lc->rchild->rchild;
	lc->rchild->rchild=p;
	p=lc->rchild;
	lc->rchild=p->lchild;
	p->lchild=lc; 
}

void RL_Rotate(BSTree &p)
{//对以*p为根的平衡二叉树的RL型失衡，直接进行平衡旋转处理，不修改平衡因子
  BSTree rc=p->rchild;
  p->rchild=rc->lchild->lchild;
  rc->lchild->lchild=p;
  p=rc->lchild;
  rc->lchild=p->rchild;
  p->rchild=rc; 
}

#define LH +1
#define EH 0
#define RH -1
void LeftBalance(BSTree &T)
{//初始条件：原本平衡二叉排序树T的左子树比右子树高（T->bf=1）,又在左子树中插入了结点，并导致左子树更高，破坏了树T的平衡性
//操作结果：对不平衡的树T作左平衡旋转处理，使树T的重心右移，实现新的平衡。
  BSTree lc,rd;
  lc=T->lchild;
  switch(lc->bf)
  {
  	case LH://新结点插入在*T的左孩子的左子树上，导致左子树的平衡因子为左高，形成LL(/)型不平衡，要作单右旋处理
	        T->bf=lc->bf=EH;
			R_Rotate(T);
			break;
	case RH://新结点插入在*T的左孩子的右子树上，导致左子树的平衡因子为右高，形成LR(<)型不平衡，要作双旋处理
	        rd=lc->rchild;
			switch(rd->bf)
			{
				case LH://新结点插入在*T的左孩子的右子树的左子树上
				        T->bf=RH;
				        lc->bf=EH;
						break;
				case EH://新结点插入为*T的左孩子的右孩子(叶子)
				        T->bf=lc->bf=EH;
						break;
				case RH://新结点插入在*T的左孩子的右子树的右子树上
				        T->bf=EH;
				        lc->bf=LH; 
			 } 
			rd->bf=EH;
	#ifndef FLAG 
	       L_Rotate(T->lchild);
	       //对*T的左子树作左旋处理，使*T成为LL(/)型不平衡
		   R_Rotate(T);
    #else
	       LR_Rotate(T);
	#endif 
   } 
}

void RightBalance(BSTree &T)
{//初始条件：原本平衡二叉排序树T的右子树比左子树高(T->bf=-1),又在右子树中插入了结点，并导致右子树更高，破坏了树T的平衡性
//操作结果：对不平衡的树T作右平衡旋转处理，使树T的重心左移，实现新的平衡
   BSTree rc,ld;
   rc=T->rchild;
   switch(rc->bf)
   {
   	case RH://新结点插入在*T的右孩子的右子树上，导致右子树的平衡因子为右高，形成RR(\)型不平衡，要作单左旋处理
	       T->bf=rc->bf=EH;
		   L_Rotate(T);
		   break;
	case LH://新结点插入在*T的右孩子的左子树上，导致右子树的平衡因子为左高，形成RL(>)型不平衡，要作双旋处理
	        ld=rc->lchild;
			switch(ld->bf)
			{
				case RH://新结点插入在*T的右孩子的左子树的右子树上
				       T->bf=LH;
					   rc->bf=EH;
					   break;
				case EH://新结点插入为*T的右孩子的左孩子
				       T->bf=rc->bf=EH;
					   break;
				case LH://新结点插入在*T的右孩子的左子树上
				      T->bf=EH;
				      rc->bf=RH; 
			 } 
			 ld->bf=EH;
	#ifndef FLAG
	       R_Rotate(T->rchild);
	       L_Rotate(T);
	#else
	       RL_Rotate(T);
    #endif
	} 
}

Status InsertAVL(BSTree &T,ElemType e,Boolean &taller)
{//若在平衡的二叉排序树T中不存在和e有相同关键字的结点，则插入一个数据元素为e的新结点，并返回TRUE
//若因插入而使二叉排序树T失去平衡，则平衡旋转处理，布尔变量taller反映在调用InsertAVL()前后，T是否长高
  if(!T)
  {
  	T=(BSTree)malloc(sizeof(BSTNode));
  	T->data=e;
  	T->lchild=T->rchild=NULL;
  	T->bf=EH;
  	taller=TRUE;//以T为根结点的树长高了(深度由0变为1) ,此信息返回给T的双亲结点 
   } 
  else
  {
  	if(EQ(e.key,T->data.key))
  	{
  		return FALSE;
	  }
	if LT(e.key,T->data.key)
	{
		if(!InsertAVL(T->lchild,e,taller))
		   return FALSE;
		if(taller)
		  switch(T->bf)
		  {
		  	case LH:
		  		  LeftBalance(T);
		  		  taller=FALSE;
		  		  break;
		  	case EH:
		  		  T->bf=LH;
		  		  taller=TRUE;
		  		  break;
		  	case RH:T->bf=EH;
		  	      taller=FALSE;
		  }
	}
	else
	{
		if(!InsertAVL(T->rchild,e,taller))
		   return FALSE;
		if(taller)
		switch(T->bf)
		{
			case LH:T->bf=EH;
			        taller=FALSE;
			        break;
			case EH:T->bf=RH;
			        taller=TRUE;
			        break;
			case RH:RightBalance(T);
			        taller=FALSE;
		}
	}
   } 
   return TRUE;
}

