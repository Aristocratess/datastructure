enum ElemTag{ATOM,LIST};
//ATOM==0:ԭ�ӣ�LIST==1:�ӱ�
typedef struct GLNode
{ElemType tag;//�������֣���������ԭ�ӽ��ͱ���
   union//ԭ�ӽ��ͱ�������ϲ���
   {AtomType atom;//atom��ԭ�ӽ���ֵ��AtomType���û�����
     struct
	 {
	 	GLNode *hp,*tp;
	  } ptr;//ptr�Ǳ����ָ����ptr.hp��ptr.tp�ֱ�ָ���ͷ�ͱ�β(��ͷ֮�������Ԫ��) 
	}; 
 }*GList,GLNode;//���������     
