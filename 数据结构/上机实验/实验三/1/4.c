#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int d;
	struct node *next;
}N;
typedef struct
{
	N *f;
	N *r;
}LQ;
void Init(LQ *lq)
{
	lq->f=(N*)malloc(sizeof(N));
	lq->f->next=NULL;
	lq->r=lq->f;
}
int Empty(LQ *lq)
{
	if(lq->f==lq->r)
		return 1;
	return 0;
}
int Size(LQ *lq)
{
	int i=0;
	N *p=lq->f->next;
	while(p)
	{
		i++;
		p=p->next;
	}
	return i;
}
int Head(LQ *lq)
{
	if(lq->f==lq->r)
		return 0;
	else
		return (lq->f->next->d);
}
void EQ(LQ *lq, int x)
{
	N *s;
	s=(N*)malloc(sizeof(N));
	s->d=x;
	s->next=NULL;
	lq->r->next=s;
	lq->r=s;
}
int DQ(LQ *lq)
{
	int x;
	N *p;
	if(lq->f==lq->r)
		return 0;
	else
	{
		p=lq->f->next;
		lq->f->next=p->next;
		if(p->next==NULL)
			lq->r=lq->f;
		x=p->d;
		free(p);
		return x;
	}
}
int main()
{
	LQ *lq;
	lq=(LQ*)malloc(sizeof(N));
	Init(lq);
	printf("%d\n",Empty(lq));
	EQ(lq,6);
	printf("%d\n",Empty(lq));
	printf("%d\n",Head(lq));
	DQ(lq);
	printf("%d\n",Empty(lq));
	return 0;
}
