#define MAX_SIZE 100
#define MAX_RC 20
struct Triple{
	int i,j;//���±꣬���±�
	ElemType e;//����Ԫ��ֵ 
};

struct RLSMatrix 
{
	Triple data[MAX_SIZE+1];//����Ԫ��Ԫ���data[0]δ��
	int rpos[MAX_RC+1];
	int mu,nu,tu;//���������������������Ԫ���� 
};


