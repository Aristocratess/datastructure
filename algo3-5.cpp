typedef char SElemType;//����ջԪ��Ϊ�ַ���
#include"c1.h"
#include"c3-1.h"//ջ��˳��洢�ṹ
#include"bo3-1.cpp"//˳��ջ�洢�ṹ�Ļ�������(9����
#include"func3-1.cpp"//����Precede()��In()��Operate()����
SElemType EvaluateExpression()
{//�������ʽ��ֵ����������㷨����OPTR��OPND�ֱ�Ϊ�����ջ��������ջ
   SqStack OPTR,OPND;
   SElemType a,b,c,x;
   InitStack(OPTR);//��ʼ�������ջOPTR��������ջOPND
   InitStack(OPND);
   Push(OPTR,'\n');//�����з�ջOPTR��ջ��Ԫ�ظ���x
   while(c!='\n'||x!='\n')//c��x�����ǻ��з�
   {
   	if(In(c))//c��7�������֮һ
	   switch(Precede(x,c))//�ж�x��c������Ȩ
	    {
	    	case'<':Push(OPTR,c);//�����ջOPTR��ջ��Ԫ��x������Ȩ�ͣ���ջc
			        c=getchar();//�ɼ��̶�����һ���ַ���c
					break;
		    case'=':Pop(OPTR,x);//x='('��c=')'���������'('��x�����ӵ�
			        c=getchar();//�ɼ��̶�����һ���ַ���c(�ӵ�cԭ�е�')')
					break;
		    case'>':Pop(OPTR,x);//ջ��Ԫ��x������Ȩ�ߣ����������ջOPTR��ջ��Ԫ�ظ�x���޸�
			        Pop(OPND,b);//���ε���������ջOPND��ջ��Ԫ�ظ�b,a
					Pop(OPND,a);
					Push(OPND,Operate(a,x,b));//������a*b��������������������ջ 
		 } 
	else if(c>='0'&&c<='9')//c�ǲ�����
	{
		Push(OPND,c-48);//���ò�������ֵ������ASCII�룩ѹ��������ջOPND
		c=getchar();//�ɼ��̶�����һ���ַ���c 
	 } 
	else//c�ǷǷ��ַ�
	{
		printf("���ַǷ��ַ�\n");
		exit(OVERFLOW); 
	 } 
	GetTop(OPTR,x);//�������ջOPTR��ջ��Ԫ�ظ���x 
	} 
	Pop(OPND,x);//����������ջOPND��ջ��Ԫ�أ�����������x(�޸Ĵ˴�)
	if(!StackEmpty(OPND)) //������ջOPND����(�����ջOPTR��ʣ'\n') 
	{
		printf("���ʽ����ȷ\n");
		exit(OVERFLOW);
	 } 
	return x;
 } 

int main()
{
	printf("�������������ʽ(�����ֵҪ��0~9֮�䡢)");
	printf("�м�����ֵ����������-128~127֮��\n");
	printf("%d\n",EvaluateExpression());//����ֵ(8λ�����ƣ�1���ֽ�)�����͸�ʽ��� 
}
