typedef char KeyType;
struct ElemType{
	KeyType key;
	int weight;
};

void Visit(ElemType c)
{
	printf("(%c,%d)",c.key,c.weight);
}

void InputFromFile(FILE* f,ElemType &c)
{
	fscanf(f,"%*c%c%d",&c.key,&c.weight);
}

void InputKey(KeyType &k)
{
	scanf("%c",&k);
}
