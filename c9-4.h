#define MAX_NUM_OF_KEY 8//关键字项数的最大值
#define RADIX 10 //关键字基数，此时是十进制整数的基数
#define MAX_SPACE 100
struct SLCell{
	KeysType keys[MAX_NUM_OF_KEY];
	InfoType otheritems;
	int next;
}; 
struct SLList{
	SLCell r[MAX_SPACE];
	int keynum;//记录的当前关键字个数 
	int recnum;//静态链表的当前长度 
};
typedef int ArrType[RADIX];//指针数组类型 

