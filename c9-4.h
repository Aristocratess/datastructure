#define MAX_NUM_OF_KEY 8//�ؼ������������ֵ
#define RADIX 10 //�ؼ��ֻ�������ʱ��ʮ���������Ļ���
#define MAX_SPACE 100
struct SLCell{
	KeysType keys[MAX_NUM_OF_KEY];
	InfoType otheritems;
	int next;
}; 
struct SLList{
	SLCell r[MAX_SPACE];
	int keynum;//��¼�ĵ�ǰ�ؼ��ָ��� 
	int recnum;//��̬����ĵ�ǰ���� 
};
typedef int ArrType[RADIX];//ָ���������� 

