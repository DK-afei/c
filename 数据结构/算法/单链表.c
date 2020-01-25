#include <stdio.h>
#include <stdlib.h>
typedef char elemtype;
typedef struct node
{
	elemtype data;
	struct node *next;
}Lnode, *linklist;
//ͷ�巨����������
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
//β�巨����������
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
//������ĳ���
int size(Lnode *h) //h���������ͷָ�룬�䳤��ͨ����������
{  
		Lnode *p;
		int i=0;
		p=h->next;          //pָ���һ�����
		while(p!=NULL) {     //ѭ�����ʵ������ÿ����㣬p=NULLʱ����
			i++;
			p=p->next;     //pָ�����
		}
		return i;
}

//�ڵ�������ĳ���֮�����ֵ�½���㷨��
void insert1(Lnode *p,elemtype x) //��ֵΪx�Ľ�����p֮��
{   
		Lnode *s;
		s=(Lnode*)malloc(sizeof(Lnode));   //����һ���½��s
		s->data=x;
		s->next=p->next;      //�½�����뵥������
		p->next=s;
}

//�ڵ������е�i��Ԫ��֮ǰ����һ��Ԫ�ص��㷨
int insert2(Lnode *h, int i,elemtype x) {
		Lnode *p, *s;
	    int j;
	    p=h;
	    j=0;
	    while(p!=NULL&&j<i-1) {    //Ѱ�ҵ�i-1�Ž��
			p=p->next;
			j++;
	    }
	    if(p!=NULL) {
			s=(Lnode*)malloc(sizeof(Lnode));
	        s->data = x;
	        s->next = p->next;     //�ı�ָ��״̬����s�������
	        p->next = s;
	        return 1;        //����1��ʾ��������
	    }else 
	        return 0;       //����0��ʾ����ʧ��
	}

//ɾ����������ĳ���ĺ�̽��
void dele(Lnode *p) { //ɾ��p�ĺ�̽��
		Lnode *q;                          
		if (p->next!=NULL) {
			q=p->next;          //qΪp��ֱ�Ӻ��
			p->next=q->next;   //ɾ��q
			q = NULL;        //�ͷ�q���ռ�
	    }             
	}

//������İ�ֵ�����㷨��
Lnode *search(Lnode *h, elemtype x) {
		Lnode *p;
		p=h->next;          //pΪ������ĵ�һ�����
		while(p!=NULL&&p->data!=x)   //ɨ����������������ֵΪx�Ľ��
			p=p->next;      //δ�ҵ���ָ���������ɨ��
		return p;
	}

//��ȡ�������еĵ�i��Ԫ�أ�
Lnode *get(Lnode *h, int i) {
		int j;
		Lnode *p;
		p=h->next;
		j=1;
		while (p!=NULL&&j<i) {     //�ƶ�ָ��p��ֱ��pΪ�ջ�pָ���i��Ԫ��
			p=p->next;
			j++;
		}
		if (i==j)                        
			return p;        //���ص�i��Ԫ�صĴ洢��ַ
		else
			return NULL;
	}


void main()
{
	Lnode *h;
	h=hcreat();
}
