void Print(SqList L){
	int i;
	for(i=1;i<=L.length;i++)
      printf("(%d,%d)",L.r[i].key,L.r[i].otherinfo);
    printf("\n");
}

void InputFromFile(FILE* f,RedType &c)
{
	fscanf(f,"%d%d",&c.key,&c.otherinfo);
}
