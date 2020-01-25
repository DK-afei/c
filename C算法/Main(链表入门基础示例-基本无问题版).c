#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Student
{
	char name[64];
	float score;
	struct Student* next;
} NODE;

//头插法创建链表，不带头结点
NODE* CreateLink()
{
	//创建链表
	NODE* head = NULL,*p;
	for(;;)
	{
		p = (NODE*)malloc(sizeof(NODE));
		scanf("%s%f", p->name, &p->score);
		p->next = NULL;

		if(strcmp(p->name , "0") == 0)
		{
			free(p);
			break;
		}

		if(head==NULL)
			head = p;
		else
		{
			p->next = head;
			head = p;
		}
	}
	return head;
}
//头插法创建链表，带头结点
NODE* CreateLink1()
{
	//创建链表
	NODE* head = NULL,*p, *p1 = NULL;
	p = (NODE*)malloc(sizeof(NODE));
	p->next = NULL;
	head = p;
	for(;;)
	{
		p = (NODE*)malloc(sizeof(NODE));
		scanf("%s%f", p->name, &p->score);
		p->next = NULL;

		if(strcmp(p->name , "0") == 0)
		{
			free(p);
			break;
		}
		if(p1 == NULL)
		{
			head->next = p;
			p1 = p;
		}
		else
		{
			head->next = p;
			p->next = p1;
			p1 = p;
		}
	}
	return head;
}
//尾插法创建链表，不带头结点
NODE* CreateLink2()
{
	//创建链表
	NODE* head = NULL,*p, *p1;
	for(;;)
	{
		p = (NODE*)malloc(sizeof(NODE));
		scanf("%s%f", p->name, &p->score);
		p->next = NULL;

		if(strcmp(p->name , "0") == 0)
		{
			free(p);
			break;
		}

		if(head==NULL)
		{
			head = p;
			p1 = p;
		}
		else
		{
			p1->next = p;
			p1 = p;
		}
	}
	return head;
}
//尾插法创建链表，带头结点
NODE* CreateLink3()
{
	//创建链表
	NODE* head = NULL,*p, *p1 = NULL;
	p = (NODE*)malloc(sizeof(NODE));
	p->next = NULL;
	head = p;
	p1 = head;
	for(;;)
	{
		p = (NODE*)malloc(sizeof(NODE));
		scanf("%s%f", p->name, &p->score);
		p->next = NULL;

		if(strcmp(p->name , "0") == 0)
		{
			free(p);
			break;
		}
		p1->next = p;
		p1 = p;
	}
	return head;
}
//从链表中删除数据
NODE* deleteData(NODE* head, char* name)
{
	NODE *p, *p1;
	p1 = head;
	p = p1->next;
	for(; p!=NULL; )
	{
		if(strcmp(p->name, name) == 0)
		{
			p1->next = p->next;
			free(p);
			break;
		}
		p1 = p;
		p = p->next;
	}
	return head;
}
//在链表中插入数据
NODE* insertData(NODE* head, int index)
{
	NODE *p1, *p2, *p;
	int count = 0;
	p1 = head;
	p2 = p1->next;
	p = (NODE*)malloc(sizeof(NODE));
	scanf("%s%f", p->name, &p->score);
	p->next = NULL;
	for(; p2!=NULL; )
	{
		count++;
		if(count == index)
		{
			p->next = p2;
			p1->next = p;
			break;
		}
		p1 = p2;
		p2=p2->next;
	}
	return head;
}

//不带头结点链表的输出
void Output(NODE* head)
{
	NODE *p;
	//输出链表内容
	p = head;
	for(; p!=NULL; )
	{
		printf("姓名：%s，成绩：%f\n", p->name, p->score);
		p = p->next;
	}
}
//不带头结点链表的输出
void Output1(NODE* head)
{
	NODE *p;
	//输出链表内容
	p = head->next;
	for(; p!=NULL; )
	{
		printf("姓名：%s，成绩：%f\n", p->name, p->score);
		p = p->next;
	}
}
void FreeLink(NODE* head)
{
	NODE *p, *p1;
	//清空链表内容
	p = head;
	for(; p!=NULL; )
	{
		p1 = p;
		p = p->next;
		free(p1);
	}
}
int getCount(NODE* head)
{
	NODE *p;
	int count = 0;
	p = head;
	for(; p!=NULL; )
	{
		count++;
		p=p->next;
	}
	return count;
}

void SaveLinkToFile(NODE* head)
{
	FILE* fp;
	NODE *p;
	int count;
	fp = fopen("test.dat", "wb");
	if(fp == NULL)
	{
		printf("open file failed!\n");
		return;
	}
	count = getCount(head);
	fwrite(&count, sizeof(int),1, fp);
	p = head;
	for(; p!=NULL; )
	{
		fwrite(p, sizeof(NODE),1, fp);
		p = p->next;
	}
	fclose(fp);
}

NODE* ReadLinkFromFile()
{
	FILE* fp;
	NODE *head = NULL, *p;
	int count, i;
	fp = fopen("test.dat", "rb");
	if(fp == NULL)
	{
		printf("open file failed!\n");
		return NULL;
	}
	fread(&count, sizeof(int), 1, fp);
	for(i=0; i<count; i++)
	{
		p = (NODE*)malloc(sizeof(NODE));
		fread(p, sizeof(NODE), 1, fp);
		p->next = NULL;

		if(head==NULL)
			head = p;
		else
		{
			p->next = head;
			head = p;
		}
	}
	return head;
}

void main()
{
	NODE* head = NULL;
	char name[64] = "lisi";
	//创建链表
	head = CreateLink3();
	//输出链表内容
	Output1(head);
	deleteData(head, name);
	Output1(head);
	insertData(head, 2);
	Output1(head);
}
