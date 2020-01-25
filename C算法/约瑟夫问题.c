#include <stdio.h>
#include <stdlib.h>
struct node 
{
	int no;
	struct node *next;
};
typedef struct node NODE;
void main()
{
	int i,j;
	NODE*head,*p,*q;
	head=(NODE*)malloc(sizeof(NODE));
	head->no=-1;
	head->next=head;
	for(i=32;i>0;i--)
	{
		p=(NODE*)malloc(sizeof(NODE));
		p->no=i;
		p->next=head->next;
		head->next=p;
	}
	while(p->next!=head)
	{
		p=p->next;
	}
	p->next=head->next;
	printf("此约瑟夫序列为：\n");
	for(i=0;i<16;i++)
	{
		for(j=0;j<8;j++)
			p=p->next;
			q=p->next;
			p->next=q->next;
			printf("%3d",q->no);
			free(q);
	}
	printf("\n");
}
