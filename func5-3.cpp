#include"c4-1.h"
#include"bo4-1.cpp"
void sever(SString str,SString hstr)
{//����ȥ������ŵķǿմ�str�ָ��������:hstrΪ��һ��','֮ǰ���Ӵ���strΪ֮����Ӵ�
  int n,k=0,i=0;//k����δ��Ե������Ÿ���
  SString ch,c1,c2,c3;
  StrAssign(c1,",");
  StrAssign(c2,"(");
  StrAssign(c3,")");
  n=StrLength(str);
  do//���������(k=0ʱ)�ĵ�1������
  {
  	++i;
  	SubString(ch,str,i,1);
	if(!StrCompare(ch,c2))
	    ++k;
	else if(!StrCompare(ch,c3))
	    --k;//��δ��Ե���������-1 
   } while(i<n&&StrCompare(ch,c1)||k!=0);//iС�ڴ�����ch���������ġ�����
   if(i<n)//��str�д���������','�����ǵ�i���ַ�
   {
   	SubString(hstr,str,1,i-1);//hstr���ش�str','ǰ���ַ�
	SubString(str,str,i+1,n-i); 
	} 
   else//��str�в�����','
   {
   	StrCopy(hstr,str);
   	ClearString(str);//','�����ǿմ� 
	} 
   
}
