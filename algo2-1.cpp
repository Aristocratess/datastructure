#include"c1.h"
typedef int ElemType;
#include"c2-1.h"
#include"bo2-1.cpp"
#include"func2-2.cpp"
void MergeList(SqList La,SqList Lb,SqList &Lc)
{//��֪˳�����Ա�La��Lb��Ԫ�ذ�ֵ�ǵݼ�����
//�鲢La��Lb�õ��µ�˳�����Ա�Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ����У����ı��La�ͱ�Lb)
  ElemType *pa,*pa_last,*pb,*pb_last,*pc;
  pa=la.elem;//paָ���La�ĵ�1��Ԫ��
  pb=Lb.elem;//pbָ���Lb�ĵ�1��Ԫ��
  Lc.listsize=Lc.length=La.length+Lb.length;//����InitList()�����ձ�Lc
  pc=Lc.elem=(ElemType*)malloc(Lc.listsize*sizeof(ElemType));//��������ռ�
  if(!Lc.elem)
     exit(OVERFLOW);
  pa_last=La.elem+La.length-1;//pa_lastָ���La�����1��Ԫ��
  pb_last=Lb.elem+Lb.length-1;//pb_lastָ���Lb�����1��Ԫ��
  while(pa<=pa_last&&pb<=pb_last)//��La�ͱ�Lb����Ԫ��û�й鲢
  {//�鲢
   if(*pa<=*pb)//��La�ĵ�ǰԪ�ز����ڱ�Lb�ĵ�ǰԪ��
      *pc++=*pa++;//��pa��ָ��Ԫ��ֵ����pc��ָ��Ԫ��pa��pc�ֱ�+1
   else
     *pc++=*pb++; 
   } 
   while(pa<=pa_last)//��Lb�е�Ԫ��ȫ���鲢
      *pc++=*pa++;//����La��ʣ��Ԫ��
   while(pb<=pb_last)//��La�е�Ԫ��ȫ���鲢
      *pc++=*pb++;//����Lb��ʣ��Ԫ�� 
}

void main()
{
	SqList La,Lb,Lc;
	int j;
	InitList(La);//�����ձ�La
	for(j=1;j<=5;j++)//�ڱ�La�в���5��Ԫ�أ�����Ϊ1��2��3��4��5
	  ListInsert(La,i,j);
	printf("La=");//�����La������
	ListTraverse(La,print1);
	InitList(Lb);//�����ձ�Lb
	for(j=1;j<=5;j++)//�ڱ�Lb�в���5��Ԫ�أ�����Ϊ2��4��6��8��10
	 ListInsert(Lb,j,2*j);
	printf("Lb=");//�����Lb������
	ListTraverse(Lb,print1);
	MergeList(La,Lb,Lc);//�ɰ��ǵݼ����еı�La��Lb�õ����ǵݼ����еı�Lc
	printf("Lc=");//�����Lc������
	ListTraverse(Lc,printf1); 
 } 
