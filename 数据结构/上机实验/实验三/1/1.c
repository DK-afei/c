#include <stdio.h>
#include <stdlib.h>
#define M 1024
typedef struct stack
{
	int d[M];
	int top;
}S;
void Init(S *s)
{
	s->top=0;
}
int Empty(S *s)
{
	if(s->top>0)
		return 0;
	else
		return 1;
}
int Full(S *s)
{
	if(s->top!=M)
		return 0;
	else
		return 1;
}
void Push(S *s, int x)
{
	if(s->top==M)
		printf("Overflow\n");
	else
		s->d[s->top++]=x;
}
int Pop(S *s)
{
	if(s->top==0)
		return 0;
	else
	{
		s->top--;
		return s->d[s->top];
	}
}
int Size(S *s)
{
	return (s->top);
}
int Top(S *s)
{
	if(s->top==0)
		return 0;
	else
		return (s->d[s->top-1]);
}
int main()
{
	S *s;
	s=(S*)malloc(sizeof(S));
	Init(s);
	printf("%d\n",Empty(s));
	Push(s,1);
	printf("%d\n",Empty(s));
	Pop(s);
	printf("%d\n",Top(s));
	printf("%d\n",Full(s));
	return 0;
}