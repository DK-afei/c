#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
	int data;
	struct node*next;
}NODE;
void main()
{
	int i=0;
	NODE*head,*p,*q;
	int max=10;
	int data[]={1,2,3,4,5,6,7,8,9,10};
	head=(NODE*)malloc(sizeof(NODE));
	head->next=NULL;
	q=head;
	while(i<max)
	{
		p=(NODE*)malloc(sizeof(NODE));
		p->data=data[i];
		p->next=NULL;
		q->next=p;
		q=p;
		printf("%d	",p->data);
		i++;
	}
	printf("\n");	
	p=head->next;
	while(p->next!=NULL)
	{
		printf("%d	",p->data);	
			p=p->next;
	}
	printf("\n");

}