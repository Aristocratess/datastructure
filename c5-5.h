enum ElemTag{ATOM,LIST
};
typedef struct GLNodel{
	ElemTag tag;//�������֣���������ԭ�ӽ��ͱ���
	union//ԭ�ӽ��ͱ�������ϲ���
	{
		AtomType atom;//ԭ�ӽ���ֵ��
		GLNodel *hp;//����ı�ͷָ�� 
	 };
	 GLNodel *tp;//�൱�����������next��ָ����һ��Ԫ�ؽ�� 
}*GList,GLNode1;//���������GListl��һ����չ���������� 
