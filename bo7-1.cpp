int LocateVex(MGraph G,VertexType u)
{//��ʼ������ͼG���ڣ�u��G�ж�������ͬ����(����������ͬ)
//�����������G�д��ڶ���u���򷵻ظö�����ͼ��λ��(���)�����򷵻�-1
  int i;
  for(i=0;i<G.vexnum;++i)
     if(strcmp(u.name,G.vexs[i].name)==0)//�����������u�Ķ���������ͬ
	    return i;
  return -1;//ͼG�в������붥��u����ͬ���ƵĶ��� 
 } 

void CreateDG(MGraph &G)
{//��������(�ڽӾ��󣩱�ʾ������������ͼG
  int i,j,k,IncInfo;//IncInfoΪ0�򻡲��������Ϣ
  VertexType v1,v2;
  printf("����������ͼG�Ķ����������������Ƿ������Ϣ(�ǣ�1 ��0)��");
  scanf("%d,%d,%d",&G.vexnum,&G.arcnum,&IncInfo);
  printf("������%d�������ֵ(����<%d���ַ�)��\n",G.vexnum,MAX_NAME);
  for(i=0;i<G.vexnum;++i)
    Input(G.vexs[i]);
  for(i=0;i<G.vexnum;++i)
    for(j=0;j<G.vexnum;++j)
	{
		G.arcs[i][j].adj=0;//ͼ��������
		G.arcs[i][j].info=NULL; 
	 } 
  printf("������%d�����Ļ�β  ��ͷ:\n",G.arcnum);
  for(k=0;k<G.arcnum;++k)
  {
  	scanf("%s%s%*c",v1.name,v2.name);//%*c�Ե��س���
	i=LocateVex(G,v1);//��β����� 
	j=LocateVex(G,v2);//��ͷ�����
	G.arcs[i][j].adj=1;
	if(IncInfo)
	  InputArc(G.arcs[i][j].info);
	  //��̬���ɴ洢�ռ䣬���뻡�������Ϣ 
  }
  G.kind=DG;
}

void CreateDN(MGraph &G)
{//�������飨�ڽӾ��󣩱�ʾ��������������G
  int i,j,k,IncInfo;
  VRType w;
  VertexType v1,v2;
  printf("������������G�Ķ����������������Ƿ������Ϣ(�ǣ�1 ��0)��");
  scanf("%d,%d,%d",&G.vexnum,&G.arcnum,&IncInfo);
  printf("������%d�������ֵ������<%d���ַ�����\n",G.vexnum,MAX_NAME);
  for(i=0;i<G.vexnum;++i)
    Input(G.vexs[i]);//���ݶ�����Ϣ�����ͣ����붥����Ϣ
  for(i=0;i<G.vexnum;++i)
    for(j=0;j<G.vexnum;++j)
	 {
	 	G.arcs[i][j].adj=INFINITY;//����������
		G.arcs[i][j].info=NULL; 
	  } 
   printf("������%d�����Ļ�β  ��β Ȩֵ:\n",G.arcnum);
   for(k=0;k<G.arcnum;++k)
   {
   	 scanf("%s%s%d%*c",v1.name,v2.name,&w);
   	 i=LocateVex(G,v1);
   	 j=LocateVex(G,v2);
   	 G.arcs[i][j].adj=w;
   	 if(IncInfo)
   	   InputArc(G.arcs[i][j].info);
   	   //��̬���ɴ洢�ռ䣬���뻡�������Ϣ 
	} 
	G.kind=DN;
}

void CreateUDG(MGraph &G)
{//��������(�ڽӾ���)��ʾ������������ͼG
  int i,j,k,IncInfo;
  VertexType v1,v2;
  printf("����������ͼG�Ķ����������������Ƿ������Ϣ(�ǣ�1 ��0)��");
  scanf("%d,%d,%d",&G.vexnum,&G.arcnum,&IncInfo);
  printf("������%d�������ֵ(����<%d���ַ�)��\n",G.vexnum,MAX_NAME);
  for(i=0;i<G.vexnum;++i)
    Input(G.vexs[i]);
  for(i=0;i<G.vexnum;++i)
    for(j=0;j<G.vexnum;++j)
	{
		G.arcs[i][j].adj=0;//ͼ��������
		G.arcs[i][j].info=NULL; 
	 } 
   printf("������%d���ߵĶ���1 ����2��\n",G.arcnum);
   for(k=0;k<G.arcnum;++k)
   {
   	scanf("%s%s%*c",v1.name,v2.name);
   	i=LocateVex(G,v1);
   	j=LocateVex(G,v2);
   	G.arcs[i][j].adj=1;
   	if(IncInfo)
   	  InputArc(G.arcs[i][j].info);
   	//��̬���ɴ洢�ռ䣬���뻡�������Ϣ
	G.arcs[j][i]=G.arcs[i][j];//����������Ԫ����Ϣ��ͬ 
   }
   G.kind=UDG; 
}

void CreateUDN(MGraph &G)
{//��������(�ڽӾ���)��ʾ��������������G
  int i,j,k,IncInfo;
  VRType w;
  VertexType v1,v2;
  printf("������������G�Ķ����������������Ƿ������Ϣ(�ǣ�1  ��0)��");
  scanf("%d,%d,%d",&G.vexnum,&G.arcnum,&IncInfo);
  printf("������%d�������ֵ(����<%d���ַ�):\n",G.vexnum,MAX_NAME);
  for(i=0;i<G.vexnum;++i)
    Input(G.vexs[i]);//���ݶ�����Ϣ�����ͣ����붥����Ϣ
  for(i=0;i<G.vexnum;++i)
    for(j=0;j<G.vexnum;++j)
	{
		G.arcs[i][j].adj=INFINITY;
		G.arcs[i][j].info=NULL;
	 } 
  printf("������%d���ߵĶ���1  ����2Ȩֵ��\n",G.arcnum);
  for(k=0;k<G.arcnum;++k)
  {
  	scanf("%s %s %d %*c",v1.name,v2.name,&w);
  	i=LocateVex(G,v1);
  	j=LocateVex(G,v2);
  	G.arcs[i][j].adj=w;
  	if(IncInfo)
  	  InputArc(G.arcs[i][j].info);
  	  //��̬���ɴ洢�ռ䣬���뻡�������Ϣ
	G.arcs[j][i]=G.arcs[i][j];
  }
  G.kind=UDN;
}

void CreateGraph(MGraph &G)
{//��������(�ڽӾ���)��ʾ��������ͼG
  printf("������ͼG������(����ͼ:0 ��������1 ����ͼ��2  ��������3):");
  scanf("%d",&G.kind);
  switch(G.kind)
  {
  	case DG:CreateDG(G);
  	        break;
  	case DN:CreateDN(G);
  	        break;
  	case UDG:CreateUDG(G);
  	        break;
    case UDN:CreateUDN(G);
  }
}

VertexType GetVex(MGraph G,int v)
{//��ʼ������ͼG���ڣ�v��G��ĳ���������š�  �������������v��ֵ
  if(v>=G.vexnum||v<0)
     exit(OVERFLOW);
  return G.vexs[v]; 
}

Status PutVex(MGraph &G,VertexType v,VertexType value)
{//��ʼ������ͼG���ڣ�v��G��ĳ�����㡣  �����������v����ֵvalue
  int k=LocateVex(G,v);
  if(k<0)
    return ERROR;
  G.vexs[k]=value;
  return OK; 
}

int FirstAdjVex(MGraph G,int v)
{//��ʼ������ͼG���ڣ�v��G��ĳ����������
//�������������v�ĵ�1���ڽӶ������š���������G��û���ڽӶ��㣬�򷵻�-1
  int i;
  VRType j=0;
  if(G.kind%2)
    j=INFINITY;
  for(i=0;i<G.vexnum;i++)
    if(G.arcs[v][j].adj!=j)
	  return i;
  return -1; 
}

int NextAdjVex(MGraph G,int v,int w)
{//��ʼ������ͼG���ڣ�v��G��ĳ���������ţ�w��v���ڽӶ�������
//�������������v�ģ������w�ģ���һ���ڽӶ������ţ���w��v�����һ���ڽӶ��㣬�򷵻�-1
  int i;
  VRType j=0;
  if(G.kind%2)
    j=INFINITY;
  for(i=w+1;i<G.vexnum;i++)
    if(G.arcs[v][i].adj!=j)//�Ǵ�w+1��ʼ�ĵ�1���ڽӶ���
	  return i;//���ظ��ڽӶ�������
  return -1;//û����һ���ڽӶ��� 
}

void InsertVex(MGraph &G,VertexType v)
{//��ʼ������ͼG���ڣ�v��ͼG�ж�������ͬ����
//�����������ͼG�������¶���v
  int i;
  VRType j=0;
  if(G.kind%2)
    j=INFINITY;
  G.vexs[G.vexnum]=v;
  for(i=0;i<=G.vexnum;i++)
  {
  	G.arcs[G.vexnum][i].adj=G.arcs[i][G.vexnum].adj=j;
  	G.arcs[G.vexnum][i].info=G.arcs[i][G.vexnum].info=NULL;
   } 
  G.vexnum++;
}

Status InsertArc(MGraph &G,VertexType v,VertexType w)
{//��ʼ������ͼG���ڣ�v��w��G����������
//�����������G������<v��w>����G������ģ�������Գƻ�<w,v>
  int i,v1,w1;
  v1=LocateVex(G,v);
  w1=LocateVex(G,w);
  if(v1<0||w1<0)
    return ERROR;
  G.arcnum++;//���������1
  if(G.kind%2)
  {
  	printf("������˻���ߵ�Ȩֵ:");
  	scanf("%d",&G.arcs[v1][w1].adj);
   } 
  else
    G.arcs[v1][w1].adj=1;
  printf("�Ƿ��иû���ߵ������Ϣ(0:�� 1����)��");
  scanf("%d%*c",&i);
  if(i)
    InputArc(G.arcs[v1][w1].info);
  if(G.kind>1)
    G.arcs[w1][v1]=G.arcs[v1][w1];//��ͬ�����ڽ�ֵ��ָ��ͬһ�������Ϣ
  return OK; 
  }  

Status DeleteArc(MGraph &G,VertexType v,VertexType w)
{//��ʼ������ͼG���ڣ�v��w��G����������
//�����������G��ɾ����<v,w>,��G������ģ���ɾ���Գƻ�<w,v>
   int v1,w1;
   VRType j=0;
   if(G.kind%2)
     j=INFINITY;
   v1=LocateVex(G,v);
   w1=LocateVex(G,w);
   if(v1<0||w1<0)
      return ERROR;
   if(G.arcs[v1][w1].adj!=j)
   {
   	G.arcs[v1][w1].adj=j;
   	if(G.arcs[v1][w1].info)
   	{
   		free(G.arcs[v1][w1].info);
   		G.arcs[v1][w1].info=NULL;
	   }
    if(G.kind>=2)//����ɾ���Գƻ�<w,v>
	   G.arcs[w1][v1]=G.arcs[v1][w1];//ɾ�������������Ϣָ��Ϊ��
	G.arcnum--; 
	} 
	return OK;
}

Status DeleteVex(MGraph &G,VertexType v)
{//��ʼ������ͼG���ڣ�v��G��ĳ�����㡣  ���������ɾ��G�ж���v������صĻ�
  int i,j,k;
  k=LocateVex(G,v);
  if(k<0)
    return ERROR;
  for(i=0;i<G.vexnum;i++)
    DeleteArc(G,v,G.vexs[i]);
  if(G.kind<2)
    for(i=0;i<G.vexnum;i++)
	  DeleteArc(G,G.vexs[i],v);
	for(j=k+1;j<G.vexnum;j++)
	  G.vexs[j-1]=G.vexs[j];
	for(i=0;i<G.vexnum;i++)
	  for(j=k+1;j<G.vexnum;j++)
	     G.arcs[i][j-1]=G.arcs[i][j];
    for(i=0;i<G.vexnum;i++)
	  for(j=k+1;j<G.vexnum;j++)
	     G.arcs[j-1][i]=G.arcs[j][i];
	G.vexnum--;
	return OK; 
}

void DestroyGraph(MGraph &G)
{//��ʼ������ͼG���ڡ�  �������������ͼG
    int i;
	for(i=G.vexnum-1;i>=0;i--)
	  DeleteVex(G,G.vexs[i]); 
}

void Display(MGraph G)
{//����ڽӾ���洢�ṹ��ͼG
  int i,j;
  char s[7]="������",s1[3]="��";
  switch(G.kind)
  {
  	case DG:strcpy(s,"����ͼ");
  	        strcpy(s1,"��");
  	        break;
    case DN:strcpy(s,"����ͼ");
            strcpy(s1,"��");
			break;
	case UDG:strcpy(s,"����ͼ");
	case UDN:; 
   } 
   printf("%d������%d��%s��%s�����������ǣ�",G.vexnum,G.arcnum,s1,s);
   for(i=0;i<G.vexnum;++i)
      Visit(GetVex(G,i));//���ݶ�����Ϣ�����ͣ����ʵ�i������
   printf("\nG.arcs.adj:\n");
   for(i=0;i<G.vexnum;i++) 
   if(G.kind<2)
   {
	 for(j=0;j<G.vexnum;j++)
	  if(G.arcs[i][j].info)
	  {
	  	printf("%5s %5s",G.vexs[i].name,G.vexs[j].name);
	  	OutputArc(G.arcs[i][j].info);
	  }
   }
   else
     for(j=i+1;j<G.vexnum;j++)
	    if(G.arcs[i][j].info)
		{
			printf("%5s%5s",G.vexs[i].name,G.vexs[j].name);
			OutputArc(G.arcs[i][j].info);
			}    
}

void CreateFromFile(MGraph &G,char* filename,int IncInfo)
{//��������(�ڽӾ���)��ʾ�������ļ�����ͼ����G��IncInfo=0��1����ʾ��(��)�޻��������Ϣ
  int i,j,k;
  VRType w=0;
  VertexType v1,v2;
  FILE *f;
  f=fopen(filename,"r");
  fscanf(f,"%d",&G.kind);
  if(G.kind%2)
    w=INFINITY;
  fscanf(f,"%d",&G.vexnum);
  for(i=0;i<G.vexnum;++i)
    InputFromFile(f,G.vexs[i]);
  fscanf(f,"%d",&G.arcnum);
  for(i=0;i<G.vexnum;++i)
    for(j=0;j<G.vexnum;++j)
	 {
	 	G.arcs[i][j].adj=w;
	 	G.arcs[i][j].info=NULL;
	  } 
   if(!(G.kind%2))
      w=1;
   for(k=0;k<G.arcnum;++k)
   {
   	fscanf(f,"%s%s",v1.name,v2.name);
   	if(G.kind%2)
   	  fscanf(f,"%d",&w);
   	i=LocateVex(G,v1);
   	j=LocateVex(G,v2);
   	G.arcs[i][j].adj=w;
   	if(IncInfo)
   	   InputArcFromFile(f,G.arcs[i][j].info);
   	if(G.kind>1)
   	   G.arcs[j][i]=G.arcs[i][j];
   }
   fclose(f);
 } 
