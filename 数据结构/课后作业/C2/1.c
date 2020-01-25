#include <stdio.h>
#include <malloc.h>
typedef int elemtype;
typedef struct node
{
	elemtype data;
	struct node *next;
}Lnode, *linklist;
Lnode *creat();
Lnode *hb(Lnode *, Lnode *);
void print(Lnode *);
int main()
{
	Lnode *h1, *h2, *h3;
	h1=creat();
	print(h1);
	h2=creat();
	print(h2);
	h3=hb(h1,h2);
	printf("合并后......\n");
	print(h3);
	return 0;
}
Lnode *creat()
{
	Lnode *h, *p, *t;
	elemtype num=0;
	h=(Lnode*)malloc(sizeof(Lnode));
	h->next=NULL;
	t=h;
	printf("请输入要输入的节点数据：（为0时截止）\n");
	scanf("%d",&num);
	while(num!=0)
	{
		p=(Lnode*)malloc(sizeof(Lnode));
		p->data=num;
		p->next=NULL;
		t->next=p;
		t=p;
		scanf("%d",&num);
	}
	return h;
}
void print(Lnode *h)
{
	Lnode *p;
	p=h->next;
	printf("此链表的所有数据为：\n");
	while(p)
	{
		if(p->data>0)
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
Lnode *hb(Lnode *pa, Lnode *pb)
{
	Lnode *p, *q, *pc;
	pb=pb;
	pa=pa;
	pc=(Lnode*)malloc(sizeof(Lnode));
	p=pc;
	while(pa&&pb)
	{
		q=(Lnode*)malloc(sizeof(Lnode));
		if(pb->data<pa->data)
		{
			q->data=pb->data;
			pb=pb->next;
		}
		else
		{
			q->data=pa->data;
			pa=pa->next;
		}
		p->next=q;
		p=q;
	}
	while(pa)
	{
		q=(Lnode*)malloc(sizeof(Lnode));
		q->data=pa->data;
		pa=pa->next;
		p->next=q;
		p=q;
	}
	while(pb)
	{
		q=(Lnode*)malloc(sizeof(Lnode));
		q->data=pb->data;
		pb=pb->next;
		p->next=q;
		p=q;
	}
	p->next=NULL;
	return (pc);
}