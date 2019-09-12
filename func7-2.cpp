#define MAX_INFO 20
typedef char InfoType;
void InputArc(InfoType *&arc)
{
	char s[MAX_INFO];//临时存储空间
	int m;
	printf("请输入该弧(边)的相关信息(<%d个字符)：",MAX_INFO);
	gets(s);
	m=strlen(s);
	if(m)
	{
		arc=(char*)malloc((m+1)*sizeof(char));
		strcpy(arc,s);
	}
}

void InputArcFromFile(FILE *f,InfoType *&arc)
{
	char s[MAX_INFO];
	fgets(s,MAX_INFO,f);//由文件输入字符串(可包括空格)
	arc=(char*)malloc((strlen(s)+1)*sizeof(char)); 
	strcpy(arc,s);
}

void OutputArc(InfoType *arc)
{
	printf("%s\n",arc);
}
