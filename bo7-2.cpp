#include"bo2-3.cpp"
#include"func2-4.cpp"
int LocateVex(ALGraph G,VertexType u)
{//初始条件：图G存在，u和G中顶点有相同特征（顶点名称相同）
//操作结果：若G中存在顶点u，则返回该顶点在图中位置(序号)，否则返回-1
  int i;
  for(i=0;i<G.vexnum;++i)
    if(strcmp(u.name,G.vertices[i].data.name)==0)//顶点与给定的u的顶点名称相同
	  return i;
  return -1; 
}

void CreateGraph(ALGraph &G)
{//采用邻接表存储结构，构造图或网G
  int i,j,k;
  VertexType v1,v2;
  ElemType e;
  char s[3]="边";
  printf("请输入图的类型(有向图：0  有向网：1  无向图：2  无向网：3):");
  scanf("%d",&G.kind);
  if(G.kind<2)
    strcpy(s,"弧");
  printf("请输入%d个顶点的值(名称<%d个字符):\n",G.vexnum,MAX_NAME);
  for(i=0;i<G.vexnum;++i)
  {
  	Input(G.vertices[i].data);
  	G.vertices[i].firstarc=NULL;//初始化与该顶点有关的出弧链表 
   } 
  printf("请输入%d个顶点的值(名称<%d个字符):\n",G.vexnum,MAX_NAME);
  for(i=0;i<G.vexnum;++i)
  {
  	Input(G.vertices[i].data);
	  G.vertices[i].firstarc=NULL; 
   } 
   printf("请输入%d条%s的",G.arcnum,s);
   switch(G.kind)
   {
   	case DG:printf("弧尾 弧头：\n");
	        break;
	case DN:printf("弧尾 弧头 弧的信息：\n");
	        break;
	case UDG:printf("顶点1 顶点2:\n");
	        break;
	case UDN:printf("顶点1 顶点2 边的信息：\n"); 
   }
   for(k=0;k<G.arcnum;++k)
   {
   	scanf("%s %s",v1.name,v2.name);
	i=LocateVex(G,v1);
	j=LocateVex(G,v2);
	e.info=NULL;
	if(G.kind%2)
	   InputArc(e.info);
	e.adjvex=j;
	ListInsert(G.vertices[i].firstarc,1,e);
	//将e插在第i个元素(出弧)的表头
	if(G.kind>=2)
	{
		e.adjvex=i;
		ListInsert(G.vertices[j].firstarc,1,e);
	 } 
   }
}

void CreateFromFile(ALGraph &G,char *filename)
{//采用邻接表存储结构，由文件构造图或网G
   int i,j,k;
   VertexType v1,v2;
   ElemType e;
   FILE *f;
   f=fopen(filename,"r");
   fscanf(f,"%d",&G.kind);
   fscanf(f,"%d",&G.vexnum);
   for(i=0;i<G.vexnum;++i)
   {
   	InputFromFile(f,G.vertices[i].data);
   	G.vertices[i].firstarc=NULL;
	} 
   fscanf(f,"%d",&G.arcnum);
   for(k=0;k<G.arcnum;++k)
   {
   	fscanf(f,"%s%s",v1.name,v2.name);
   	i=LocateVex(G,v1);
   	j=LocateVex(G,v2);
   	e.info=NULL;
   	if(G.kind%2)
   	   InputArcFromFile(f,e.info);
   	e.adjvex=j;
   	ListInsert(G.vertices[i].firstarc,1,e);
   	if(G.kind>=2)
   	{
   		e.adjvex=i;
   		ListInsert(G.vertices[j].firstarc,1,e);
	   }
   }
   fclose(f);
}

VertexType GetVex(ALGraph G,int v)
{//初始条件：图G存在，v是G中某个顶点的序号。  操作结果：返回v的值
  if(v>=G.vexnum||v<0)
    exit(OVERFLOW);
  return G.vertices[v].data; 
}

Status PutVex(ALGraph &G,VertexType v,VertexType value)
{//初始条件：图G存在，v是G中某个顶点。  操作结果：对v赋新值value
  int k=LocateVex(G,v);
  if(k!=-1)
  {
  	G.vertices[k].data=value;
  	return OK;
   } 
   return ERROR;
}

int FirstAdjVex(ALGraph G,int v)
{//初始条件：图G存在，v是G中某个顶点的序号
//操作结果：返回v的第1个邻接顶点的序号。若顶点在G中没有邻接顶点，则返回-1
   ArcNode *p=G.vertices[v].firstarc;//p指向顶点v的第1个邻接顶点
   if(p)
     return p->data.adjvex;
   else
     return -1; 
}

Status equalvex(ElemType a,ElemType b)
{
	if(a.adjvex==b.adjvex)
	   return OK;
	else
	   return ERROR;
}

int NextAdjVex(ALGraph G,int v,int w)
{//初始条件：图G存在，v是G中某个顶点的序号，w是v的邻接顶点的序号
//操作结果：返回v的(相对于w的)下一个邻接顶点的序号。若w是v的最后一个邻接顶点，则返回-1
  LinkList p,p1;
  ElemType e;
  e.adjvex=w;
  p=Point(G.vertices[v].firstarc,e,equalvex,p1);
  //p指向顶点v的链表中邻接顶点为w的结点
  if(!p||!p->next)
     return -1;
  else
    return p->nextarc->data.adjvex; 
}

void InsertVex(ALGraph &G,VertexType v)
{//初始条件：图G存在，v和图中顶点有相同特征
//操作结果：在图G中增添新顶点v
  G.vertices[G.vexnum].data=v;
  G.vertices[G.vexnum].firstarc=NULL;
  G.vexnum++; 
}

Status InsertArc(ALGraph &G,VertexType v,VertexType w)
{//初始条件：图G存在，v和w是G中两个顶点
//操作结果：在G中增添弧<v,w>，若G是无向的，则还增添对称弧<w,v>
  ElemType e;
  int i,j;
  char s1[3]="边",s2[3]="-";
  if(G.kind<2)
  {
  	strcpy(s1,"弧");
  	strcpy(s2,"->");
   } 
  i=LocateVex(G,v);
  j=LocateVex(G,w);
  if(i<0||j<0)
    return ERROR;
  G.arcnum++;
  e.adjvex=j;
  e.info=NULL;
  if(G.kind%2)
  {
  	printf("请输入%s%s%s%s的信息：",s1,v.name,s2,w.name);
  	InputArc(e.info);
   } 
  ListInsert(G.vertices[i].firstarc,1,e);
  if(G.kind>=2)
  {
  	e.adjvex=i;//弧尾表结点的值，e.info不变
	ListInsert(G.vertices[j].firstarc,1,e); 
  }
  return OK;
}

Status DeleteArc(ALGraph &G,VertexType v,VertexType w)
{//初始条件：图G存在，v和w是G中两个顶点
//操作结果：在G中删除弧<v,w>,若G是无向的，则还删除对称弧<w,v> 
  int i,j,n;
  ElemType e;
  i=LocateVex(G,v);
  j=LocateVex(G,w);
  if(i<0||j<0||i==j)
    return ERROR;
  e.adjvex=j;
  n=LocateElem(G.vertices[i].firstarc,e,equalvex);
  //在弧尾链表中找到弧头表结点，将其在链表中的位序赋给n
  if(n)
  {
  	ListDelete(G.vertices[i].firstarc,n,e);
  	G.arcnum--;
  	if(G.kind%2)
  	  free(e.info);
  	if(G.kind>=2)
  	{
  		e.adjvex=i;
  		n=LocateElem(G.vertices[j].firstarc,e,equalvex);
  		ListDelete(G.vertices[j].firstarc,n,e);
	  }
	return OK;
   } 
   else
     return ERROR;
}

Status DeleteVex(ALGraph &G,VertexType v)
{//初始条件：图G存在，v是G中某个顶点。  操作结果：删除G中顶点v及其相关的弧(边)
  int i,k;
  LinkList p;
  k=LocateVex(G,v);
  if(k<0)
     return ERROR;
  for(i=0;i<G.vexnum;i++)
    DeleteArc(G,v,G.vertices[i].data);
  if(G.kind<2)
    for(i=0;i<G.vexnum;i++)
	{
		p=G.vertices[i].firstarc;
		while(p)
		{
			if(p->data.adjvex>k)
			   p->data.adjvex--;
			p=p->next;
		}
	 } 
	 for(i=k+1;i<G.vexnum;i++)
	   G.vertices[i-1]=G.vertices[i];
	G.vexnum--;
	return OK;
}

void DestroyGraph(ALGraph &G)
{//初始条件：图G存在。  操作结果：销毁图G
  int i;
  for(i=G.vexnum-1;i>=0;i--)
     DeleteVex(G,G.vertices[i].data); 
}

void Display(ALGraph G)
{//输出图的邻接矩阵G
  int i;
  ArcNode *p;
  char s1[3]="边",s2[3]="--";
  if(G.kind<2)
  {
  	strcpy(s1,"弧");
  	strcpy(s2,"->");
   } 
  switch(G.kind)
  {
  	case DG:printf("有向图\n");
  	        break;
  	case DN:printf("有向图\n");
  	        break;
  	case UDG:printf("无向图\n");
  	        break;
  	case UDN:printf("无向图\n");
  }
  printf("%d个顶点，依次是：",G.vexnum);
  for(i=0;i<G.vexnum;++i)
    Visit(GetVex(G,i));
  printf("\n%d条%s:\n",G.arcnum,s1);
  for(i=0;i<G.vexnum;i++)
  {
  	p=G.vertices[i].firstarc;
  	while(p)
  	{
  		if(G.kind<=1||i<p->data.adjvex)
  		{
  			printf("%s %s %s",G.vertices[i].data.name,s2);
  			G.vertices[p->data.adjvex].data.name;
  			if(G.kind%2)
  			  OutputArc(p->data.info);
		  }
		p=p->nextarc;
	  }
	  printf("\n");
   } 
}
