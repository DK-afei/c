#include <stdio.h>
#include <stdlib.h>
typedef struct link
{
	int info;
	struct link *next;
}L;
typedef struct
{
	L *top;
}LS;
void Init(LS *ls)
{
	ls->top=NULL;
}
void Push(LS *ls, int x)
{
	L *l=NULL;
	l=(L*)malloc(sizeof(L));
	l->info=x;
	l->next=ls->top;
	ls->top=l;
}
int Pop(LS *ls)
{
	L *p=NULL;
	int x;
	if(ls->top==NULL)
		return 0;
	else
	{
		x=(ls->top)->info;
		p=ls->top;
		ls->top=p->next;
		free(p);
		return x;
	}
}
int Top(LS *ls)
{
	if(ls->top==NULL)
		return 0;
	else
		return (ls->top)->info;
}
int Empty(LS *ls)
{
	if(ls->top==NULL)
		return 1;
	else
		return 0;
}
int main()
{
	LS *ls;
	ls=(LS*)malloc(sizeof(LS));
	Init(ls);
	printf("%d\n",Empty(ls));
	Push(ls,2);
	printf("%d\n",Empty(ls));
	printf("%d\n",Pop(ls));
	printf("%d\n",Top(ls));
	return 0;
}
