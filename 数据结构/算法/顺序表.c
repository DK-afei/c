#include <stdio.h>
#include <stdlib.h>
#define Maxsize 22
typedef int elemtype;
typedef struct 
{
	elemtype v[Maxsize];
	int len;
}sqlist;
//�����Ա�ĳ���
int lenth(sqlist *L)
{
	int lenth;
	lenth=L->len;
	return(lenth);
}
//�����㷨
int insert(sqlist *L, int i, elemtype x) 
{
		int j;
		if (L->len == Maxsize) {        //�ж����Ա�Ĵ洢�ռ��Ƿ�����
		printf("���\n");
	        return 0;
	    }else 
			if ((i<1)||i>L->len+1) {      //���iֵ�Ƿ񳬳�������ķ�Χ
				printf("����λ�ò���ȷ\n");
				return 0;
	        }else {
			for(j= L->len-1;j>=i-1;j--)
				L->v[j+1]= L->v[j];//����i��Ԫ�غ������������Ԫ�ؾ�����һ��λ��					
			L->v[i-1]=x;   //���µ�Ԫ��д�뵽�ճ����±�Ϊi-1��λ����
			L->len++;     //���Ա�ĳ�������1
			return 1;
	    }
}
//ɾ���㷨
//iΪɾ��Ԫ�ص�λ��ţ�ɾ��Ԫ�ص�ֵ����
int dele(sqlist *L,int i,elemtype *y)
 {
		int j;
		if ((i<1)||(i>L->len)) {        // �ж�iֵ�Ƿ񳬳�������ķ�Χ
			printf("ɾ��λ�ò���ȷ\n");
		    return 0;
	    }else {
			*y= L->v[i-1];           //�ѵ�i��Ԫ�ظ���*y
			for(j=i;j< L->len;j++)  //�ѵ�i��Ԫ�غ������Ԫ��������ǰ�ƶ�һ��λ��
				L->v[j-1]= L->v[j];
			L->len--;    //���Ա��ȼ�1
			return 1;       
		}
}
//�����㷨
int search(sqlist *L, int x)
 {
		int i;
		for (i=0;i< L->len;i++)   //�����Ա���˳�����
			if (x==L->v[i]) 
				break;
		if (i< L->len) 
			return (i+1);
		else return 0;
}
void main()
{
	sqlist *L;
	L=(sqlist*)malloc(sizeof(sqlist));
	L->len=0;
	printf("%d\n",lenth(L));
}