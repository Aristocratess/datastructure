typedef int VRType;
struct InfoType//最简单的弧(边)的相关信息类型(只有权值)
{
	VRType weight;//权值 
 };
 
void InputArc(InfoType *&arc)
{
	arc=(InfoType*)malloc(sizeof(InfoType));
	scanf("%d",&arc->weight);
 } 
 
void OutputArc(InfoType *arc)
{
	printf(":%d",arc->weight);
}

void InputArcFromFile(FILE* f,InfoType *&arc)
{
	arc=(InfoType*)malloc(sizeof(InfoType));
	fscanf(f,"%d",&arc->weight);
}
