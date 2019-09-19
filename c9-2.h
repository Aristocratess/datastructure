#define MAX_SIZE 20
struct SqList{
	RedType r[MAX_SIZE+1];//r[0]闲置或作哨兵单元
	int length; 
};


