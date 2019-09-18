typedef struct TrieNode{
	NodeKind kind;
	union{
		struct{
			KeyType K;
			Record* infoptr;
		}lf;
		struct{
			TrieNode* ptr[LENGTH];
			int num;
		}bh; 
	};
}TrieNode,*TrieTree;

