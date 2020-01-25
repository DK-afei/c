#include <stdio.h>
#include <stdlib.h>
typedef int elemtype;
typedef struct NODETYPE
{
	elemtype data;
	struct NODETYPE *next;
}nodetype;
typedef struct
{
	nodetype *front;
	nodetype *rear;
}lqueuetp;
void InitQueue(lqueuetp *lq)
{
	lq->front=(nodetype*)malloc(sizeof(nodetype));
	lq->front->next=NULL;
	lq->rear=lq->front;
}
int QueueEmpty(lqueuetp *lq)
{
	if(lq->front==lq->rear)
		return 1;
	return 0;
}
int Size(lqueuetp *lq)
{
	int i=0;
	nodetype *p=lq->front->next;
	while(p)
	{
		i++;
		p=p->next;
	}
	return i;
}
elemtype Head(lqueuetp *lq)
{
	if(lq->front==lq->rear)
		return 0;
	else
		return (lq->front->next->data);
}
void EnQueue(lqueuetp *lq, elemtype x)
{
	nodetype *s;
	s=(nodetype*)malloc(sizeof(nodetype));
	s->data=x;
	s->next=NULL;
	lq->rear->next=s;
	lq->rear=s;
}
elemtype DelQueue(lqueuetp *lq)
{
	elemtype x;
	nodetype *p;
	if(lq->front==lq->rear)
		return 0;
	else
	{
		p=lq->front->next;
		lq->front->next=p->next;
		if(p->next=NULL)
			lq->rear=lq->front;
		x=p->data;
		free(p);
		return x;
	}
}
void main()
{
	lqueuetp *lq;
	lq=(lqueuetp*)malloc(sizeof(lqueuetp));
	InitQueue(lq);
}

