#include <stdio.h>
#include <stdlib.h>
typedef int elemtype;
typedef struct stacknode
{
	elemtype data;
	struct stacknode *next;
}stacknode;
typedef struct
{
	stacknode *top;
}LinkStack;
void InitStack(LinkStack *ls)
{
	ls->top=NULL;
}
void Push(LinkStack *ls, elemtype x)
{
	stacknode *s=NULL;
	s=(stacknode*)malloc(sizeof(stacknode));
	s->data=x;
	s->next=ls->top;
	ls->top=s;
}
elemtype Pop(LinkStack *ls)
{
	stacknode *p=NULL;
	elemtype x;
	if(ls->top==NULL)
		return 0;
	else
	{
		x=(ls->top)->data;
		p=ls->top;
		ls->top=p->next;
		free(p);
		return x;
	}
}
void main()
{
	LinkStack *ls;
	ls=(LinkStack*)malloc(sizeof(LinkStack));
	InitStack(ls);
}