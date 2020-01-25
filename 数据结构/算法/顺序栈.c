#include <stdio.h>
#include <stdlib.h>
#define maxsize 20
typedef int elemtype;
typedef struct
{
	elemtype elem[maxsize];
	int top;
}sqstacktp;
void InitStack(sqstacktp *s)
{
	s->top=0;
}
int StackEmpty(sqstacktp *s)
{
	if(s->top>0)
		return 0;
	else
		return 0;
}
void Push(sqstacktp *s, elemtype x)
{
	if(s->top==maxsize)
		printf("Overflow");
	else
		s->elem[s->top++]=x;
}
elemtype Pop(sqstacktp *s)
{
	if(s->top==0)
		return 0;
	else
	{
		s->top--;
		return s->elem[s->top];
	}
}
int Size(sqstacktp *s)
{
	return(s->top);
}
elemtype Top(sqstacktp *s)
{
	if(s->top==0)
		return 0;
	else
		return(s->elem[s->top-1]);
}

void main()
{
	sqstacktp *s;
	s=(sqstacktp*)malloc(sizeof(sqstacktp));
	InitStack(s);
}