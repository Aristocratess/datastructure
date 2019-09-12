#define Order
int min(HuffmanTree t,int i)
{//���غշ�����t��ǰi�������Ȩֵ��С�����ĸ������ţ�����select()����
  int j,m;
  unsigned int k=UINT_MAX;//k����СȨֵ����ֵȡΪ��С�ڿ��ܵ�ֵ
  for(j=1;j<=i;j++)
    if(t[j].weight<k&&t[j].parent==0)
	{
		k=t[j].weight;//t[j]��Ȩֵ����k
		m=j;//��Ÿ���m 
	 } 
	t[m].parent=1;
	return m; 
}

void select(HuffmanTree t,int i,int &s1,int &s2)
{//�ںշ���������ǰi�������ѡ��2��Ȩֵ��С�����ĸ������ţ�s1Ϊ�������(Ȩֵ)��С��
 #ifdef Order
   int j;
 #endif
   s1=min(t,i);//Ȩֵ��С�ĸ������� 
   s2=min(t,i); //Ȩֵ��2С�ĸ�������
 #ifdef Order
   if(s1>s2)
   {
   	j=s1;
   	s1=s2;
   	s2=j;
	} 
 #endif
}
