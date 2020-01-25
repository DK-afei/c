#include <stdio.h>
#include <stdlib.h>
#define m 1024
typedef struct
{
	int d[m];
	int f,r;
}Q;
void Init(Q *q)
{
	q->f=0;
	q->r=0;
}
int Empty(Q *q)
{
	if(q->r==q->f)
		return 1;
	return 0;
}
int Full(Q *q)
{
	if((q->r+1)%m==q->f)
		return 1;
	else
		return 0;
}
int Size(Q *q)
{
	return ((m+q->r-q->f)%m);
}
int Head(Q *q)
{
	if(q->f==q->r)
		return 0;
	else
		return (q->d[(q->f+1)%m]);
}
void EQ(Q *q, int x)
{
	if((q->r+1)%m==q->f)
		printf("Overflow\n");
	else
	{
		q->r=(q->r+1)%m;
		q->d[q->r]=x;
	}
}
int DQ(Q *q)
{
	if(q->f==q->r)
		return 0;
	else
	{
		q->f=(q->f+1)%m;
		return (q->d[q->f]);
	}
}
int main()
{
	Q *q;
	q=(Q*)malloc(sizeof(Q));
	Init(q);
	printf("%d\n",Full(q));
	printf("%d\n",Empty(q));
	EQ(q,1);
	printf("%d\n",Empty(q));
	printf("%d\n",Head(q));
	DQ(q);
	printf("%d\n",Head(q));
	return 0;
}