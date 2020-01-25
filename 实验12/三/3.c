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
void main()
{
	NODE*head;
	NODE*p1,*p2,*p3;
	p3=(NODE*)malloc(sizeof(NODE));
	p3->nextAddr=NULL;
	head=p3;
	p1=(NODE*)malloc(sizeof(NODE));
	gets(p1->name);
	gets(p1->phoneNum);
	p1->nextAddr=NULL;
	head->nextAddr=p1;
	p2=(NODE*)malloc(sizeof(NODE));
	gets(p2->name);
	gets(p2->phoneNum);
	p2->nextAddr=head->nextAddr;
	head->nextAddr=p2;
	output(head);
	printf("\n");
}