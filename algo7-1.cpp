#define MG
#include"c1.h"
#include"func7-1.cpp"
#ifdef MG
  #include"func7-2.cpp"
  #include"c7-1.h"
  #include"bo7-1.cpp"
  typedef MGraph Graph;
#else
  #include"func7-4.cpp"
  #include"c7-2'.h"
  #include"bo7-2.cpp"
  typedef ALGraph Graph;
#endif
#include"bo7-3.cpp"
int main()
{
	Graph g;
	char filename[13];
	printf("请输入数据文件名:");
	scanf("%s",filename);
   #ifdef MG
    CreateFromFile(g,filename,0);
   #else
    CreateFromFile(g,filename);
   #endif
    printf("深度优先搜索遍历的结果：\n");
    DFSTraverse(g,Visit);
    printf("广度优先搜索遍历的结果：\n");
    BFSTraverse(g,Visit);
}
