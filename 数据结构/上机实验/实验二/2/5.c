#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int exp;
	float coef;
	struct node *next;
}polynode;
polynode *creat()
{
	polynode *h, *p, *t;
	h=(polynode*)malloc(sizeof(polynode));
	h->next=NULL;
	t=h;
	while(1)
	{
		p=(polynode*)malloc(sizeof(polynode));
		scanf("%f%d",&p->coef,&p->exp);
		if(p->exp==0&&p->coef==0)
		{
			free(p);
			break;
		}
		p->next=NULL;
		t->next=p;
		t=p;
	}
	return h;
}
void dxsxj(polynode *ha, polynode *hb)
{
	polynode *p, *q, *r, *pre;
	float x;
	p=ha->next;
	q=hb->next;
	pre=ha;
	while(p&&q)
	{
		if(p->exp==q->exp)
		{
			x=p->coef+q->coef;
			if(x!=0)
			{
				p->coef=x;
				pre=p;
			}
			else
			{
				pre->next=p->next;
				free(p);
			}
			p=pre->next;
			r=q;
			q=q->next;
			free(r);
		}
		else if(p->exp>q->exp)
		{
			r=q->next;
			q->next=p;
			pre->next=q;
			pre=q;
			q=r;
		}
	}
	if(q)
		pre->next=q;
	free(hb);
}
void output(polynode *h)
{
	polynode *p;
	p=h->next;
	while(p)
	{
		printf("%fx^%d+",p->coef,p->exp);
		p=p->next;
	}
	printf("\n");
}
int main()
{
	polynode *h1, *h2;
	h1=creat();
	output(h1);
	h2=creat();
	output(h2);
	dxsxj(h1,h2);
	output(h1);
	return 0;
}
