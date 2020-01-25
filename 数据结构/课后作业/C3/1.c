#include <stdio.h>
#include <malloc.h>
#define MaxLen 100
typedef struct node
{
	char data;
	struct node *next;
}cnode;
cnode *create(char s[])
{
	int I=0;
	cnode *h,*p,*r;
	while(s[I]!='\0')
	{
		p=(cnode*)malloc(sizeof(cnode));
		p->data=s[I];
		p->next=NULL;
		if(I==0)
		{
			h=p;
			r=p;
		}
		else
		{
			r->next=p;
			r=p;
		}
		I++;
	}
	return h;
}
int judge(cnode*h)
{
	char st[MaxLen];
	int top=0;
	cnode *p=h;
	while(p!=NULL)
	{
		st[top]=p->data;
		top++;
		p=p->next;
	}
	p=h;
	while(p!=NULL)
	{
		top--;
		if(p->data==st[top])
			p=p->next;
		else
			break;
	}
	if(p==NULL)
		return 1;
	else
		return 0;

}
void main()
{
	char str[MaxLen];
	cnode *h;
	printf("input a string:");
	scanf("%s",str);
	h=create(str);
	if(judge(h)==1)
		printf("%s is a right string\n",str);
	else 
		printf("%s is a false string\n",str);
}