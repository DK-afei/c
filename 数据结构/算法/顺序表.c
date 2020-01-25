#include <stdio.h>
#include <stdlib.h>
#define Maxsize 22
typedef int elemtype;
typedef struct 
{
	elemtype v[Maxsize];
	int len;
}sqlist;
//求线性表的长度
int lenth(sqlist *L)
{
	int lenth;
	lenth=L->len;
	return(lenth);
}
//插入算法
int insert(sqlist *L, int i, elemtype x) 
{
		int j;
		if (L->len == Maxsize) {        //判断线性表的存储空间是否已满
		printf("溢出\n");
	        return 0;
	    }else 
			if ((i<1)||i>L->len+1) {      //检查i值是否超出所允许的范围
				printf("插入位置不正确\n");
				return 0;
	        }else {
			for(j= L->len-1;j>=i-1;j--)
				L->v[j+1]= L->v[j];//将第i个元素和它后面的所有元素均后移一个位置					
			L->v[i-1]=x;   //将新的元素写入到空出的下标为i-1的位置上
			L->len++;     //线性表的长度增加1
			return 1;
	    }
}
//删除算法
//i为删除元素的位序号，删除元素的值返回
int dele(sqlist *L,int i,elemtype *y)
 {
		int j;
		if ((i<1)||(i>L->len)) {        // 判断i值是否超出所允许的范围
			printf("删除位置不正确\n");
		    return 0;
	    }else {
			*y= L->v[i-1];           //把第i个元素赋给*y
			for(j=i;j< L->len;j++)  //把第i个元素后的所有元素依次向前移动一个位置
				L->v[j-1]= L->v[j];
			L->len--;    //线性表长度减1
			return 1;       
		}
}
//查找算法
int search(sqlist *L, int x)
 {
		int i;
		for (i=0;i< L->len;i++)   //在线性表中顺序查找
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