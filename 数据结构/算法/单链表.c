#include <stdio.h>
#include <stdlib.h>
typedef char elemtype;
typedef struct node
{
	elemtype data;
	struct node *next;
}Lnode, *linklist;
//头插法创建单链表
Lnode *hcreat()
{
	elemtype ch;
	Lnode *h, *p;
	h=(Lnode*)malloc(sizeof(Lnode));
	h->next=NULL;
	while((ch=getchar())!='\n')
	{
		p=(Lnode*)malloc(sizeof(Lnode));
		p->data=ch;
		p->next=h->next;
		h->next=p;
	}
	return h;
}
//尾插法创建单链表
Lnode *tcreat()
{
	Lnode *h, *p, *t;
	elemtype ch;
	h=(Lnode*)malloc(sizeof(Lnode));
	h->next=NULL;
	t=h;
	while((ch=getchar())!='\n')
	{
		p=(Lnode*)malloc(sizeof(Lnode));
		p->data=ch;
		p->next=NULL;
		t->next=p;
		t=p;
	}
	return h;
}
//求单链表的长度
int size(Lnode *h) //h代表单链表的头指针，其长度通过函数返回
{  
		Lnode *p;
		int i=0;
		p=h->next;          //p指向第一个结点
		while(p!=NULL) {     //循环访问单链表的每个结点，p=NULL时结束
			i++;
			p=p->next;     //p指针后移
		}
		return i;
}

//在单链表中某结点之后插入值新结点算法：
void insert1(Lnode *p,elemtype x) //将值为x的结点插在p之后
{   
		Lnode *s;
		s=(Lnode*)malloc(sizeof(Lnode));   //生成一个新结点s
		s->data=x;
		s->next=p->next;      //新结点链入单链表中
		p->next=s;
}

//在单链表中第i个元素之前插入一个元素的算法
int insert2(Lnode *h, int i,elemtype x) {
		Lnode *p, *s;
	    int j;
	    p=h;
	    j=0;
	    while(p!=NULL&&j<i-1) {    //寻找第i-1号结点
			p=p->next;
			j++;
	    }
	    if(p!=NULL) {
			s=(Lnode*)malloc(sizeof(Lnode));
	        s->data = x;
	        s->next = p->next;     //改变指针状态，将s插入表中
	        p->next = s;
	        return 1;        //返回1表示正常结束
	    }else 
	        return 0;       //返回0表示插入失败
	}

//删除单链表中某结点的后继结点
void dele(Lnode *p) { //删除p的后继结点
		Lnode *q;                          
		if (p->next!=NULL) {
			q=p->next;          //q为p的直接后继
			p->next=q->next;   //删除q
			q = NULL;        //释放q结点空间
	    }             
	}

//单链表的按值查找算法：
Lnode *search(Lnode *h, elemtype x) {
		Lnode *p;
		p=h->next;          //p为单链表的第一个结点
		while(p!=NULL&&p->data!=x)   //扫描整个单链表，查找值为x的结点
			p=p->next;      //未找到，指针继续后移扫描
		return p;
	}

//读取单链表中的第i个元素：
Lnode *get(Lnode *h, int i) {
		int j;
		Lnode *p;
		p=h->next;
		j=1;
		while (p!=NULL&&j<i) {     //移动指针p，直到p为空或p指向第i个元素
			p=p->next;
			j++;
		}
		if (i==j)                        
			return p;        //返回第i个元素的存储地址
		else
			return NULL;
	}


void main()
{
	Lnode *h;
	h=hcreat();
}
