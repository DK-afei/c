#include <stdio.h>
#include <stdlib.h>
struct node 
{
	char name[20];
	char adress[20];
	char phone[20];
	struct node * link;
};
typedef struct node NODE;
//output nodes
void output(NODE*head)
{
	NODE*p;
	p=head->link;
	while(p!=NULL)
	{
		puts(p->name);
		puts(p->adress);
		puts(p->phone);
		p=p->link;
	}
}
	//insert node
void insert_node(NODE*head,NODE*p,int i)
{
	NODE*q;
	int n=0;
	for(q=head;n<i&&q->link!=NULL;++n)
	{
		q=q->link;
		p->link=q->link;
		q->link=p;
	}
}
	//delete node1
void delete_node(NODE*head,int j) 
{
	NODE*q,*p;
	int i;
	for(i=0,q=head,p=head->link;;++i)
	{
		q=q->link;
		p=q->link;
		if(i==(j-1))
		{
			q->link=p->link;
			free(p);
			break;
		}
	}
}

	//calculate the length of nodes
int length(NODE*head)
{
	int len;
	NODE*p;
	for(len=0,p=head->link;p!=NULL;++len)
	{
		p=p->link;
	}
	return len;
}
	//free nodes1
void free_nodes(NODE*head,int n)
{
	NODE*p;
	NODE*q;
	int i;
	for(i=0,q=head,p=q->link;i<n-1;i++)
	{	
		q=p->link;
		free(p);
		p=q->link;
	}
	free(head);
}

void main()
{

	//create nodes
	NODE*head;
	NODE*p;
	int n,i;

	//input the node number of nodes
	scanf("%d",&n);
	fflush(stdin);

	//create the head of nodes(it's a blank nodes,and the length of nodes is 0.)
	p=(NODE*)malloc(sizeof(NODE));
	p->link=NULL;
	head=p;

	//create the 1th nodes 尾插法
	p=(NODE*)malloc(sizeof(NODE));
	gets(p->name);
	gets(p->adress);
	gets(p->phone);
	p->link=NULL;
	head->link=p;

	//cyclicly create lefted (n-1) nodes 头插法
	for(i=0;i<n-1;i++)
	{
	p=(NODE*)malloc(sizeof(NODE));
	gets(p->name);
	gets(p->adress);
	gets(p->phone);
	p->link=head->link;
	head->link=p;
	}
	output(head);
	printf("\n");

	//insert node
	p=(NODE*)malloc(sizeof(NODE));
	gets(p->name);
	gets(p->adress);
	gets(p->phone);
	insert_node(head,p,1);
	output(head);
	printf("\n");

	//delete node
	delete_node(head,1);
	output(head);
	printf("\n");

	//calculate the the length of nodes
	printf("链表长度：%d\n",length(head));

	//free nodes
	free_nodes(head,n);
}



