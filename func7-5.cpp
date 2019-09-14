void FindInDegree(ALGraph G,int indegree[])
{//求顶点的入度
  int i;
  ArcNode *p;
  for(i=0;i<G.vexnum;i++)
    indegree[i]=0;
  for(i=0;i<G.vexnum;i++)
  {
  	p=G.vertices[i].firstarc;
  	while(p)
	 {
	 	indegree[p->data.adjvex]++;//将p所指邻顶点的入度+1
		p=p->nextarc; 
	  } 
   } 
}


