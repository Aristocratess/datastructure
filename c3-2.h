typedef struct QNode{
	QElemType data;
	QNode *next;
}*QueuePtr;
struct LinkQueue{
	QueuePtr front,rear;//队头、队尾指针 
};


