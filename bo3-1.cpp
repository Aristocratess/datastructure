void InitStack(SqStack &S)
{//����һ����ջS
  S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
  if(!S.base) 
    exit(OVERFLOW);
  S.top=S.base;//ջ��ָ��ջ��(��ջ��
  S.stacksize=STACK_INIT_SIZE;//�洢�ռ�Ϊ��ʼ������ 
}

void DestroyStack(SqStack &S)
{//����ջS��S���ٴ���
   free(S.base);
   S.top=S.base=NULL;//ջ����ջ��ָ���Ϊ��
   S.stacksize=0;//��ǰ�ѷ���Ĵ洢�ռ�Ϊ0 
 } 
 
void ClearStack(SqStack &S)
{//��ջS��Ϊ��ջ
  S.top=S.base;//ջ��ָ��ָ��ջ�� 
 } 
 
Status StackEmpty(SqStack S)
{//��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE
  if(S.top==S.base)
    return TRUE;
  else
    return FALSE; 
 } 
 
int StackLength(SqStack S)
{//����ջS��Ԫ�ظ�������ջ�ĳ���
  return S.top-S.base; 
}

Status GetTop(SqStack S,SElemType &e)
{//��ջS���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR
  if(S.top>S.base)
  {e=*(S.top-1);//��ջ��Ԫ�ظ���e
  return OK; 
   } 
  else
    return ERROR;
}

void Push(SqStack &S,SElemType e)
{//����Ԫ��eΪջS�µ�ջ��Ԫ��
  if(S.top-S.base==S.stacksize)
  {S.base=(SElemType*)realloc(S.base,(S.stacksize+STACK_INCREMENT)*sizeof(SElemType)); 
    if(!S.base)
      exit(OVERFLOW);
    S.top=S.base+S.stacksize;//�޸�ջ��ָ�룬ָ���µ�ջ��
	S.stacksize+=STACK_INCREMENT;//���µ�ǰ�ѷ���Ĵ洢�ռ� 
   } 
   *(S.top)++=e;//��e��ջ����Ϊ�µ�ջ��Ԫ�أ�ջ��ָ������1���洢��Ԫ 
}

Status Pop(SqStack &S,SElemType &e)
{//��ջS���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR
  if(S.top==S.base)
    return ERROR;
  e=*--S.top;//��ջ��Ԫ�ظ���e��ջ��ָ������1���洢��Ԫ
  return OK; 
 } 
 
void StackTraverse(SqStack S,void(*visit)(SElemType))
{//��ջ�׵�ջ�����ζ�ջS�е�ÿ��Ԫ�ص��ú���visit() 
  while(S.top>S.base)//S.baseָ��ջԪ��
    visit(*S.base++);//�Ը�ջԪ�ص���visit()
  printf("\n");//ջ��ָ������1���洢��Ԫ 
}


