#define MAX_SIZE 100
#define MAX_RC 20
struct Triple{
	int i,j;//行下标，列下标
	ElemType e;//非零元素值 
};

struct RLSMatrix 
{
	Triple data[MAX_SIZE+1];//非零元三元组表，data[0]未用
	int rpos[MAX_RC+1];
	int mu,nu,tu;//矩阵的行数，列数，非零元个数 
};


