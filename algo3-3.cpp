typedef char SElemType;//����ջԪ������Ϊ�ַ���
#include"c1.h"
#include"c3-1.h"//ջ��˳��洢�ṹ
#include"bo3-1.cpp"
FILE *fp;
void copy(SElemType c)
{//���ַ�c����fp��ָ���ļ���
   fputc(c,fp); 
 } 

void LineEdit()
{//�����ַ�ջs,���ն˽���һ�в��������ù��̵�������
  SqStack s;
  char ch;
  InitStack(s);
  printf("������һ���ı��ļ���^z�������룺\n");
  ch=getchar();//�����ַ���ch
  while(ch!=EOF)//��ȫ��δ����
  {
  	while(ch!=EOF&&ch!='\n')//��ȫ��δ������δ����ĩ
	  {switch(ch)//�Ե�ǰ�ַ�ch�����������
	  {
	  	case '#':if(!StackEmpty(s))
		          Pop(s,ch);//����ջ�ǿ�ʱ����ջ��Ԫ�أ�c����ch���
				break;
	    case '@':ClearStack(s);//����sΪ��ջ
		        break;
	    default:Push(s,ch);//�����ַ���ջ 
	   } 
	   ch=getchar();//���ն˽�����һ���ַ���ch 
	   } //����ĩ��ȫ�Ľ������Ƴ��˲�ѭ�� 
	   StackTraverse(s,copy);//����ջ�׵�ջ����ջ���ַ����δ������ļ�������copy()������
	   fputc('\n',fp);//���ļ�����һ�����з�
	   ClearStack(s);//����sΪ��ջ
	   if(ch!=EOF)
	      ch=getchar();//���ն˽�����һ���ַ���ch 
   } 
   DestroyStack(s); 
}

int main()
{
	fp=fopen("ed.txt","w");
	//�ڵ�ǰĿ¼�½���ed.txt�ļ�������д���ݣ�������ͬ���ļ�����ɾ��ԭ�ļ�
	if(fp)//�����ļ��ɹ�
	{LineEdit();//�б༭
	fclose(fp);//�ر�fp��ָ���ļ� 
	 } 
	else
	  printf("�����ļ�ʧ�ܣ�\n"); 
}
