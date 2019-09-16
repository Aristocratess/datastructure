void ShortestPath_FLOYD(MGraph G,PathMatrix P,DistancMatrix D)
{//用Floyd算法求有向网G中各对顶点v和w之间的最短路径P[v][w][]及其带权长度D[v][w]
//若P[v][w][u]为TRUE，则u是从v到w当前求得最短路径上的顶点
   int u,v,w,i;
   for(v=0;v<G.vexnum;v++)
     for(w=0;w<G.vexnum;w++)
	 {
	 	D[v][w]=G.arcs[v][w].adj;
	 	for(u=0;u<G.vexnum;u++)
	 	  P[v][w][u]=FALSE;
		if(D[v][w]<INFINITY)
		  P[v][w][v]=P[v][w][w]=TRUE; 
	  } 
	for(u=0;u<G.vexnum;u++)
	  for(v=0;v<G.vexnum;v++)
	    for(w=0;w<G.vexnum;w++)
	      if(D[v][u]<INFINITY&&D[u][w]<INFINITY&&D[v][u]+D[u][w]<D[v][w])
	      {
	      	D[v][w]=D[v][u]+D[u][w];
	      	for(i=0;i<G.vexnum;i++)
	      	  P[v][w][i]=P[v][u][i]||P[u][w][i];
			  //从v到w的路径经过从v到u和从u到w的所有路径 
		  }
}
