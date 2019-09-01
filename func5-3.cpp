#include"c4-1.h"
#include"bo4-1.cpp"
void sever(SString str,SString hstr)
{//将脱去外层括号的非空串str分割成两部分:hstr为第一个','之前的子串，str为之后的子串
  int n,k=0,i=0;//k记尚未配对的左括号个数
  SString ch,c1,c2,c3;
  StrAssign(c1,",");
  StrAssign(c2,"(");
  StrAssign(c3,")");
  n=StrLength(str);
  do//搜索最外层(k=0时)的第1个逗号
  {
  	++i;
  	SubString(ch,str,i,1);
	if(!StrCompare(ch,c2))
	    ++k;
	else if(!StrCompare(ch,c3))
	    --k;//尚未配对的左括号数-1 
   } while(i<n&&StrCompare(ch,c1)||k!=0);//i小于串长且ch不是最外层的‘，’
   if(i<n)//串str中存在最外层的','，它是第i个字符
   {
   	SubString(hstr,str,1,i-1);//hstr返回串str','前的字符
	SubString(str,str,i+1,n-i); 
	} 
   else//串str中不存在','
   {
   	StrCopy(hstr,str);
   	ClearString(str);//','后面是空串 
	} 
   
}
