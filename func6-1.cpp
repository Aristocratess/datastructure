#include"c1.h"
#if CHAR//CHARֵΪ���㣬�������Ϊ�ַ�
  typedef char TElemType;
  TElemType Nil=' ';//���ַ����Կո��Ϊ��
  #define form "%c"
#else
  typedef int TElemType;//������Ԫ��Ϊ����
  TElemType Nil=0; 
  #define form"%d"
#endif 

void visit(TElemType e)
{
	printf(form" ",e);//����CHARΪ1ʱ�����ַ���ʽ�����CHARΪ0ʱ�������͸�ʽ��� 
}

    
