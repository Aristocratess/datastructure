#include"c1.h"
#if CHAR//CHAR值为非零，结点类型为字符
  typedef char TElemType;
  TElemType Nil=' ';//设字符型以空格符为空
  #define form "%c"
#else
  typedef int TElemType;//定义树元素为整型
  TElemType Nil=0; 
  #define form"%d"
#endif 

void visit(TElemType e)
{
	printf(form" ",e);//定义CHAR为1时，以字符格式输出；CHAR为0时，以整型格式输出 
}

    
