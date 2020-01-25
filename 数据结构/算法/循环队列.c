#include <stdio.h>
#include <stdlib.h>
#define maxsize 22
typedef int elemtype;
typedef struct
{
	elemtype elem[maxsize];
	int front,rear;
}cqueuetp;
void InitQueue(cqueuetp *sq)
{
	sq->front=0;
	sq->rear=0;
}
int QueueEmpty(cqueuetp *sq)
{
	if(sq->rear==sq->front)
		return 1;
	return 0;
}
int Size(cqueuetp *sq)
{
	return((maxsize+sq->rear-sq->front)%maxsize);
}
elemtype Head(cqueuetp *sq)
{
	if(sq->front==sq->rear)
		return 0;
	else
		return(sq->elem[(sq->front+1)%maxsize]);
}
void EnQueue(cqueuetp *sq, elemtype x)
{
	if((sq->rear+1)%maxsize==sq->front)
		printf("Overflow\n");
	else
	{
		sq->rear=(sq->rear+1)%maxsize;
		sq->elem[sq->rear]=x;
	}
}
elemtype DelQueue(cqueuetp *sq)
{
	if(sq->front==sq->rear)
	return 0;
	else
	{
		sq->front=(sq->front+1)%maxsize;
		return(sq->elem[sq->front]);
	}
}

void main()
{
	cqueuetp *sq;
	sq=(cqueuetp*)malloc(sizeof(cqueuetp));
	InitQueue(sq);
}