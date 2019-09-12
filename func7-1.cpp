#define MAX_NAME 9
struct VertexType
{
	char name[MAX_NAME];
};
void Visit(VertexType ver)
{
	printf("%s",ver.name);
}
void Input(VertexType &ver)
{
	scanf("%s",ver.name);
}
void InputFromFile(FILE *f,VertexType &ver)
{
	fscanf(f,"%s",ver.name);
}
