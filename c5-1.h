#define MAX_ARRAY_DIM 8//��������ά�������ֵΪ8
struct Array{
	ElemType *base;//����Ԫ�ػ�ַ����InitArray����
	int dim;//����ά��
	int *bounds;//����ά���ַ
	int *constants;//����ӳ����������ַ����InitArray���� 
}; 


