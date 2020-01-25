#include <stdio.h>
#include <stdlib.h>
#define Maxsize 1024
typedef int elemtype;
typedef struct
{
	elemtype v[Maxsize];
	int len;
}sqlist;
void init(sqlist *L)
{
	int i;
	int n;
	printf("请给定顺序表的长度：\n");
	scanf("%d",&n);
	printf("请初始化该顺序表：\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&L->v[i]);
		L->len++;
	}
}
int lenth(sqlist *L)
{
	int lenth;
	lenth=L->len;
	return lenth;
}
void output(sqlist *L)
{
	int i;
	for(i=0;i<lenth(L);i++)
		printf("%d:%d\n",i,L->v[i]);
}

int insert(sqlist *L, int i, elemtype x)
{
	int j;
	if(L->len==Maxsize)
	{
		printf("溢出\n");
		return 0;
	}
	else
		if((i<1)||i>L->len+1)
		{
			printf("插入位置不正确\n");
			return 0;
		}
		else
		{
			for(j=L->len-1;j>=i-1;j--)
				L->v[j+1]=L->v[j];
				L->v[i-1]=x;
				L->len=L->len+1;
				return 1;
		}
}
int search(sqlist *L, int x)
{
	int i;
	for(i=0;i<L->len;i++)
		if(x==L->v[i])
			break;
		if(i<L->len)
			return (i+1);
		else
			return 0;
}
int dele1(sqlist *L, int i, elemtype *y)
{
	int j;
	if((i<1)||(i>L->len))
	{
		printf("删除位置不正确\n");
		return 0;
	}
	else
	{
		*y=L->v[i-1];
		for(j=i;j<L->len;j++)
			L->v[j-1]=L->v[j];
		L->len=L->len-1;
		return 1;
	}
}
int dele2(sqlist *L, elemtype x, elemtype *y)
{
	int j;
	if(!search(L,x))
	{
		printf("无要删除的目标元素\n");
		return 0;
	}
	else
	{
		*y=L->v[search(L,x)-1];
		for(j=search(L,x);j<L->len;j++)
			L->v[j-1]=L->v[j];
		L->len=L->len-1;
		return 1;
	}
}

elemtype geti(sqlist *L,int i)
{
	return L->v[i];
}
int main()
{
	sqlist *L;
	elemtype y=0;
	L=(sqlist *)malloc(sizeof(sqlist));
	L->len=0;
	init(L);
	output(L);
	//printf("%d\n",geti(L,0));
	//dele1(L,1,&y);
	//dele2(L,3,&y);
	//printf("%d\n",y);
	//insert(L,1,0);
	//insert(L,lenth(L)+1,0);
	//insert(L,2,0);
	if(search(L,2))
		printf("存在,位置为%d\n",search(L,2));
	else
		printf("不存在，位置为%d\n");
	output(L);

	return 0;
}