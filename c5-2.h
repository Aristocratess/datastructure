#define MAX_SIZE 100
struct Triple{
	int i,j;//���±꣬���±�
	ElemType e;//����Ԫ��ֵ 
};

struct TSMatrix{
	Triple data[MAX_SIZE+1];//����Ԫ��Ԫ���data[0]δ��
	int mu,nu,tu;//���������������������Ԫ���� 
};
