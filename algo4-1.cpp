#include"c1.h"
#include"c4-1.h"
#include"bo4-1.cpp"
void get_next(SString T,int next[])
{//��ģʽ��T��next����ֵ����������next
  int i=1,j=0;
  next[1]=0;//T�ĵ�1���ַ�������"ʧ��"ʱ����������һ�ַ���T�ĵ�1���ַ��Ƚ�
  while(i<T[0])//��T[0]>1ʱ��next[2]=1
    if(j==0||T[i]==T[j])//��̬�����ַ����
	{
		++i;//��+1�������Ƚ�
		++j; 
		next[i]=j;//������T�ڵ�i���ַ���ƥ��ʱ��ǰj-1���ַ���ƥ��ģ�ֻ�����j���ַ��Ƚ� 
	 }
	else//���ַ�����
	  j=next[j];//j��С��ǰ���ַ����֮�� 
}

void get_nextval(SString T,int nextval[])
{//��ģʽ��T��next��������ֵ����������nextval
   int i=1,j=0;
   nextval[1]=0;//T�ĵ�1���ַ�������"ʧ��"����������һ�ַ���T�ĵ�1���ַ��Ƚ�
   while(i<T[0])
     if(j==0||T[i]==T[j])
	 {
	 	++i;
	 	++j;
	 	if(T[i]!=T[j])
	 	  nextval[i]=j;
	    else
	      nextval[i]=nextval[j];
	  } 
	  else
	    j=nextval[j];//j��С��ǰ���ַ����֮�� 
 } 
 
int Index_KMP(SString S,SString T,int pos,int next[])
{//����ģʽ��T��next������T������S�е�pos���ַ�֮���λ�õ�KMP�㷨�����У�T�ǿգ�1<=pos<=StrLength(S)
  int i=pos,j=1;//��ʼλ��
  while(i<=S[0]&&j<=T[0])//i��j�ֱ�δ��������S��ģʽ��T�ķ�Χ
   if(j==0||S[i]==T[j])//�����ȽϺ���ַ�
     {
     	++i;
     	++j;
	  } 
	else//ģʽ��������
	 j=next[j];
	if(j>T[0])//ƥ��ɹ�
	  return i-T[0];
	else 
	  return 0; 
 } 
 
int main()
{
	int i,*p;
	SString s1,s2;
	StrAssign(s1,"aaabaaab");
	printf("����Ϊ");
	StrPrint(s1);
	StrAssign(s2,"aaab");
	printf("�Ӵ�Ϊ");
	StrPrint(s2);
	p=(int*)malloc((StrLength(s2)+1)*sizeof(int));//����s2��next���飬[0]����
	get_next(s2,p);
	printf("�Ӵ���next����Ϊ");
	for(i=1;i<=StrLength(s2);i++)
	  printf("%d",*(p+i));
	printf("\n");
	i=Index_KMP(s1,s2,1,p);
	if(i)
	  printf("�������Ӵ��ڵ�%d���ַ����״�ƥ��\n",i);
	else
	  printf("�������Ӵ�ƥ�䲻�ɹ�\n");
	get_nextval(s2,p);
	printf("�Ӵ���nextval����Ϊ");
	for(i=1;i<=StrLength(s2);i++)
	  printf("%d",*(p+i));
	printf("\n");
	printf("�������Ӵ��ڵ�%d���ַ����״�ƥ��\n",Index_KMP(s1,s2,1,p)); 
}
