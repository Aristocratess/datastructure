typedef int VRType;
struct InfoType//��򵥵Ļ�(��)�������Ϣ����(ֻ��Ȩֵ)
{
	VRType weight;//Ȩֵ 
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
