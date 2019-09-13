int LocateVex(MGraph G,VertexType u)
{//初始条件：图G存在，u和G中顶点有相同特征(顶点名称相同)
//操作结果：若G中存在顶点u，则返回该顶点在图中位置(序号)；否则返回-1
  int i;
  for(i=0;i<G.vexnum;++i)
     if(strcmp(u.name,G.vexs[i].name)==0)//顶点与给定的u的顶点名称相同
	    return i;
  return -1;//图G中不存在与顶点u有相同名称的顶点 
 } 

void CreateDG(MGraph &G)
{//采用数组(邻接矩阵）表示法，构造有向图G
  int i,j,k,IncInfo;//IncInfo为0则弧不含相关信息
  VertexType v1,v2;
  printf("请输入有向图G的顶点数，弧数，弧是否含相关信息(是：1 否：0)：");
  scanf("%d,%d,%d",&G.vexnum,&G.arcnum,&IncInfo);
  printf("请输入%d个顶点的值(名称<%d个字符)：\n",G.vexnum,MAX_NAME);
  for(i=0;i<G.vexnum;++i)
    Input(G.vexs[i]);
  for(i=0;i<G.vexnum;++i)
    for(j=0;j<G.vexnum;++j)
	{
		G.arcs[i][j].adj=0;//图，不相邻
		G.arcs[i][j].info=NULL; 
	 } 
  printf("请输入%d条弧的弧尾  弧头:\n",G.arcnum);
  for(k=0;k<G.arcnum;++k)
  {
  	scanf("%s%s%*c",v1.name,v2.name);//%*c吃掉回车符
	i=LocateVex(G,v1);//弧尾的序号 
	j=LocateVex(G,v2);//弧头的序号
	G.arcs[i][j].adj=1;
	if(IncInfo)
	  InputArc(G.arcs[i][j].info);
	  //动态生成存储空间，输入弧的相关信息 
  }
  G.kind=DG;
}

void CreateDN(MGraph &G)
{//采用数组（邻接矩阵）表示法，构造有向网G
  int i,j,k,IncInfo;
  VRType w;
  VertexType v1,v2;
  printf("请输入有向网G的顶点数，弧数，弧是否含相关信息(是：1 否：0)：");
  scanf("%d,%d,%d",&G.vexnum,&G.arcnum,&IncInfo);
  printf("请输入%d个顶点的值（名称<%d个字符）：\n",G.vexnum,MAX_NAME);
  for(i=0;i<G.vexnum;++i)
    Input(G.vexs[i]);//根据顶点信息的类型，输入顶点信息
  for(i=0;i<G.vexnum;++i)
    for(j=0;j<G.vexnum;++j)
	 {
	 	G.arcs[i][j].adj=INFINITY;//网，不相邻
		G.arcs[i][j].info=NULL; 
	  } 
   printf("请输入%d条弧的弧尾  弧尾 权值:\n",G.arcnum);
   for(k=0;k<G.arcnum;++k)
   {
   	 scanf("%s%s%d%*c",v1.name,v2.name,&w);
   	 i=LocateVex(G,v1);
   	 j=LocateVex(G,v2);
   	 G.arcs[i][j].adj=w;
   	 if(IncInfo)
   	   InputArc(G.arcs[i][j].info);
   	   //动态生成存储空间，输入弧的相关信息 
	} 
	G.kind=DN;
}

void CreateUDG(MGraph &G)
{//采用数组(邻接矩阵)表示法，构造无向图G
  int i,j,k,IncInfo;
  VertexType v1,v2;
  printf("请输入无向图G的顶点数，边数，边是否含相关信息(是：1 否：0)：");
  scanf("%d,%d,%d",&G.vexnum,&G.arcnum,&IncInfo);
  printf("请输入%d个顶点的值(名称<%d个字符)：\n",G.vexnum,MAX_NAME);
  for(i=0;i<G.vexnum;++i)
    Input(G.vexs[i]);
  for(i=0;i<G.vexnum;++i)
    for(j=0;j<G.vexnum;++j)
	{
		G.arcs[i][j].adj=0;//图，不相邻
		G.arcs[i][j].info=NULL; 
	 } 
   printf("请输入%d条边的顶点1 顶点2：\n",G.arcnum);
   for(k=0;k<G.arcnum;++k)
   {
   	scanf("%s%s%*c",v1.name,v2.name);
   	i=LocateVex(G,v1);
   	j=LocateVex(G,v2);
   	G.arcs[i][j].adj=1;
   	if(IncInfo)
   	  InputArc(G.arcs[i][j].info);
   	//动态生成存储空间，输入弧的相关信息
	G.arcs[j][i]=G.arcs[i][j];//无向，两个单元的信息相同 
   }
   G.kind=UDG; 
}

void CreateUDN(MGraph &G)
{//采用数组(邻接矩阵)表示法，构造无向网G
  int i,j,k,IncInfo;
  VRType w;
  VertexType v1,v2;
  printf("请输入无向网G的顶点数，边数，边是否含相关信息(是：1  否：0)：");
  scanf("%d,%d,%d",&G.vexnum,&G.arcnum,&IncInfo);
  printf("请输入%d个顶点的值(名称<%d个字符):\n",G.vexnum,MAX_NAME);
  for(i=0;i<G.vexnum;++i)
    Input(G.vexs[i]);//根据顶点信息的类型，输入顶点信息
  for(i=0;i<G.vexnum;++i)
    for(j=0;j<G.vexnum;++j)
	{
		G.arcs[i][j].adj=INFINITY;
		G.arcs[i][j].info=NULL;
	 } 
  printf("请输入%d条边的顶点1  顶点2权值：\n",G.arcnum);
  for(k=0;k<G.arcnum;++k)
  {
  	scanf("%s %s %d %*c",v1.name,v2.name,&w);
  	i=LocateVex(G,v1);
  	j=LocateVex(G,v2);
  	G.arcs[i][j].adj=w;
  	if(IncInfo)
  	  InputArc(G.arcs[i][j].info);
  	  //动态生成存储空间，输入弧的相关信息
	G.arcs[j][i]=G.arcs[i][j];
  }
  G.kind=UDN;
}

void CreateGraph(MGraph &G)
{//采用数组(邻接矩阵)表示法，构造图G
  printf("请输入图G的类型(有向图:0 有向网：1 无向图：2  无向网：3):");
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
{//初始条件：图G存在，v是G中某个顶点的序号。  操作结果：返回v的值
  if(v>=G.vexnum||v<0)
     exit(OVERFLOW);
  return G.vexs[v]; 
}

Status PutVex(MGraph &G,VertexType v,VertexType value)
{//初始条件：图G存在，v是G中某个顶点。  操作结果：对v赋新值value
  int k=LocateVex(G,v);
  if(k<0)
    return ERROR;
  G.vexs[k]=value;
  return OK; 
}

int FirstAdjVex(MGraph G,int v)
{//初始条件：图G存在，v是G中某个顶点的序号
//操作结果：返回v的第1个邻接顶点的序号。若顶点在G中没有邻接顶点，则返回-1
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
{//初始条件：图G存在，v是G中某个顶点的序号，w是v的邻接顶点的序号
//操作结果：返回v的（相对于w的）下一个邻接顶点的序号，若w是v的最后一个邻接顶点，则返回-1
  int i;
  VRType j=0;
  if(G.kind%2)
    j=INFINITY;
  for(i=w+1;i<G.vexnum;i++)
    if(G.arcs[v][i].adj!=j)//是从w+1开始的第1个邻接顶点
	  return i;//返回该邻接顶点的序号
  return -1;//没有下一个邻接顶点 
}

void InsertVex(MGraph &G,VertexType v)
{//初始条件：图G存在，v和图G中顶点有相同特征
//操作结果：在图G中增添新顶点v
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
{//初始条件：图G存在，v和w是G中两个顶点
//操作结果：在G中增添弧<v，w>，若G是无向的，则还增添对称弧<w,v>
  int i,v1,w1;
  v1=LocateVex(G,v);
  w1=LocateVex(G,w);
  if(v1<0||w1<0)
    return ERROR;
  G.arcnum++;//弧或边数加1
  if(G.kind%2)
  {
  	printf("请输入此弧或边的权值:");
  	scanf("%d",&G.arcs[v1][w1].adj);
   } 
  else
    G.arcs[v1][w1].adj=1;
  printf("是否有该弧或边的相关信息(0:无 1：有)：");
  scanf("%d%*c",&i);
  if(i)
    InputArc(G.arcs[v1][w1].info);
  if(G.kind>1)
    G.arcs[w1][v1]=G.arcs[v1][w1];//有同样的邻接值，指向同一个相关信息
  return OK; 
  }  

Status DeleteArc(MGraph &G,VertexType v,VertexType w)
{//初始条件：图G存在，v和w是G中两个顶点
//操作结果：在G中删除弧<v,w>,若G是无向的，则还删除对称弧<w,v>
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
    if(G.kind>=2)//无向，删除对称弧<w,v>
	   G.arcs[w1][v1]=G.arcs[v1][w1];//删除弧，置相关信息指针为空
	G.arcnum--; 
	} 
	return OK;
}

Status DeleteVex(MGraph &G,VertexType v)
{//初始条件：图G存在，v是G中某个顶点。  操作结果：删除G中顶点v及其相关的弧
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
{//初始条件：图G存在。  操作结果：销毁图G
    int i;
	for(i=G.vexnum-1;i>=0;i--)
	  DeleteVex(G,G.vexs[i]); 
}

void Display(MGraph G)
{//输出邻接矩阵存储结构的图G
  int i,j;
  char s[7]="无向网",s1[3]="边";
  switch(G.kind)
  {
  	case DG:strcpy(s,"有向图");
  	        strcpy(s1,"弧");
  	        break;
    case DN:strcpy(s,"有向图");
            strcpy(s1,"弧");
			break;
	case UDG:strcpy(s,"无向图");
	case UDN:; 
   } 
   printf("%d个顶点%d条%s的%s。顶点依次是：",G.vexnum,G.arcnum,s1,s);
   for(i=0;i<G.vexnum;++i)
      Visit(GetVex(G,i));//根据顶点信息的类型，访问第i个顶点
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
{//采用数组(邻接矩阵)表示法，由文件构造图或网G。IncInfo=0或1，表示弧(边)无或有相关信息
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
