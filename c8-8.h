typedef struct DLTNode{
	char symbol;
	DLTNode *next;
	NodeKind kind;
	union{
		Record* infoptr;
		DLTNode* first; 
	};
}DLTNode,*DLTree;
