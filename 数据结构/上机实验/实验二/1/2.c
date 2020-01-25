#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define m 20
typedef struct node
{
	int k;
	char v[m];
	struct node * next;
}Lnode, *linklist;
Lnode *creat()
{
	Lnode *h, *p;
	h=(Lnode*)malloc(sizeof(Lnode));
	h->next=NULL;
	while(1)
	{
		p=(Lnode*)malloc(sizeof(Lnode));
		scanf("%d%s",&p->k,p->v);
		if(p->k==0)
		{
			free(p);
			break;
		}
		p->next=h->next;
		h->next=p;
	}
	return h;
}
void untwist(Lnode *h)
{
	Lnode *p;
	p=h->next;
	while(p)
	{
		if(p->k==5&&!strcmp(p->v,"cs."))
		printf("cat\n");
		if(p->k==101&&!strcmp(p->v,"thqqxw.lui.qswer"))
		printf("this_is_a_secret\n");
		if(p->k==3&&!strcmp(p->v,"b_ylxmhzjsys.virpbkr"))
		printf("beware._dogs_barking\n");
		p=p->next;
	}
}
int main()
{
	Lnode *h;
	h=creat();
	untwist(h);
}