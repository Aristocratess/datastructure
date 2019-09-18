void R_Rotate(BSTree &p)
{//����*pΪ���Ķ���������������ת����ʹ�������������������ƣ������޸�ƽ������
//����֮��pָ���µ�������㣬����ת����֮ǰ���������ĸ����
  BSTree lc;
  lc=p->lchild;
  p->lchild=lc->rchild;
  lc->rchild=p;
  p=lc; 
}

void L_Rotate(BSTree &p)
{//����*pΪ���Ķ�������������������ʹ�������������������ƣ������޸�ƽ������
//����֮��pָ���µ�������㣬����ת����֮ǰ���������ĸ����
  BSTree rc;
  rc=p->rchild;
  p->rchild=rc->lchild;
  rc->lchild=p;
  p=rc;
}

void LR_Rotate(BSTree &p)
{//����*pΪ����ƽ���������LR��ʧ�⣬ֱ�ӽ���ƽ����ת�������޸�ƽ������
    BSTree lc=p->lchild; 
    p->lchild=lc->rchild->rchild;
	lc->rchild->rchild=p;
	p=lc->rchild;
	lc->rchild=p->lchild;
	p->lchild=lc; 
}

void RL_Rotate(BSTree &p)
{//����*pΪ����ƽ���������RL��ʧ�⣬ֱ�ӽ���ƽ����ת�������޸�ƽ������
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
{//��ʼ������ԭ��ƽ�����������T�����������������ߣ�T->bf=1��,�����������в����˽�㣬���������������ߣ��ƻ�����T��ƽ����
//����������Բ�ƽ�����T����ƽ����ת����ʹ��T���������ƣ�ʵ���µ�ƽ�⡣
  BSTree lc,rd;
  lc=T->lchild;
  switch(lc->bf)
  {
  	case LH://�½�������*T�����ӵ��������ϣ�������������ƽ������Ϊ��ߣ��γ�LL(/)�Ͳ�ƽ�⣬Ҫ������������
	        T->bf=lc->bf=EH;
			R_Rotate(T);
			break;
	case RH://�½�������*T�����ӵ��������ϣ�������������ƽ������Ϊ�Ҹߣ��γ�LR(<)�Ͳ�ƽ�⣬Ҫ��˫������
	        rd=lc->rchild;
			switch(rd->bf)
			{
				case LH://�½�������*T�����ӵ�����������������
				        T->bf=RH;
				        lc->bf=EH;
						break;
				case EH://�½�����Ϊ*T�����ӵ��Һ���(Ҷ��)
				        T->bf=lc->bf=EH;
						break;
				case RH://�½�������*T�����ӵ�����������������
				        T->bf=EH;
				        lc->bf=LH; 
			 } 
			rd->bf=EH;
	#ifndef FLAG 
	       L_Rotate(T->lchild);
	       //��*T������������������ʹ*T��ΪLL(/)�Ͳ�ƽ��
		   R_Rotate(T);
    #else
	       LR_Rotate(T);
	#endif 
   } 
}

void RightBalance(BSTree &T)
{//��ʼ������ԭ��ƽ�����������T������������������(T->bf=-1),�����������в����˽�㣬���������������ߣ��ƻ�����T��ƽ����
//����������Բ�ƽ�����T����ƽ����ת����ʹ��T���������ƣ�ʵ���µ�ƽ��
   BSTree rc,ld;
   rc=T->rchild;
   switch(rc->bf)
   {
   	case RH://�½�������*T���Һ��ӵ��������ϣ�������������ƽ������Ϊ�Ҹߣ��γ�RR(\)�Ͳ�ƽ�⣬Ҫ������������
	       T->bf=rc->bf=EH;
		   L_Rotate(T);
		   break;
	case LH://�½�������*T���Һ��ӵ��������ϣ�������������ƽ������Ϊ��ߣ��γ�RL(>)�Ͳ�ƽ�⣬Ҫ��˫������
	        ld=rc->lchild;
			switch(ld->bf)
			{
				case RH://�½�������*T���Һ��ӵ�����������������
				       T->bf=LH;
					   rc->bf=EH;
					   break;
				case EH://�½�����Ϊ*T���Һ��ӵ�����
				       T->bf=rc->bf=EH;
					   break;
				case LH://�½�������*T���Һ��ӵ���������
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
{//����ƽ��Ķ���������T�в����ں�e����ͬ�ؼ��ֵĽ�㣬�����һ������Ԫ��Ϊe���½�㣬������TRUE
//��������ʹ����������Tʧȥƽ�⣬��ƽ����ת������������taller��ӳ�ڵ���InsertAVL()ǰ��T�Ƿ񳤸�
  if(!T)
  {
  	T=(BSTree)malloc(sizeof(BSTNode));
  	T->data=e;
  	T->lchild=T->rchild=NULL;
  	T->bf=EH;
  	taller=TRUE;//��TΪ��������������(�����0��Ϊ1) ,����Ϣ���ظ�T��˫�׽�� 
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

