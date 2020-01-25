#include <stdio.h>
#include <stdlib.h>
struct TeleType
{
	char name[30];
	char phoneNum[15];
	struct TeleType *nextAddr;
};
typedef struct TeleType NODE;
output(NODE*head)
{
	NODE*p;
	p=head->nextAddr;
	while(p!=NULL)
	{
		puts(p->name);
	puts(p->phoneNum);
		p=p->nextAddr;
	}
}
free_nodes(NODE*head,int n)
{
	NODE*p;
	NODE*q;
	int i;
	for(i=0;i<n;i++)
	{
		q=head->nextAddr;	
		p=q->nextAddr;
		q->nextAddr=p->nextAddr;
		free(p);
	}
}
void main()
{
	NODE*head;
	NODE*p;
	int i,n;
	printf("please input the number of the nodes:\n");
	scanf("%d",&n);
	p=(NODE*)malloc(sizeof(NODE));
	p->nextAddr=NULL;
	head=p;
	p=(NODE*)malloc(sizeof(NODE));
	gets(p->name);
	gets(p->phoneNum);
	p->nextAddr=NULL;
	head->nextAddr=p;
	for(i=0;i<n-1;i++)
	{
	p=(NODE*)malloc(sizeof(NODE));
	gets(p->name);
	gets(p->phoneNum);
	p->nextAddr=head->nextAddr;
	head->nextAddr=p;
	}
	output(head);
	printf("\n");
	free_nodes(head,n);
}