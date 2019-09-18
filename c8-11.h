int hashsize[]={11,19,29,37};
struct HashTable{
	ElemType* elem;
	int count;
	int sizeindex;
};
#define SUCCESS 1
#define UNSUCCESS 0
#define DUPLICATE -1

