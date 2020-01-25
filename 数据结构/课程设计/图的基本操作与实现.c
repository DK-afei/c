#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef char elemtype;//��������
typedef int elemtype0;//����Ԫ������
#define maxsize 10//ͼ����������Ŀ
#define queuesize 100//���е��������
#define Max INT_MAX//�����
//�߽������Ͷ���
typedef struct edgenode
{
	int adjvex;//����ڽӵĵ��ڶ������±꣬�ڽӵ�
	struct edgenode *next;//ָ��Vi��һ���ڽӵ�ı߽��
	int weight;/*Ȩֵ*/
}edgenode;
//���������Ͷ���
typedef struct vexnode
{
	elemtype data; //�洢��������ƻ��������Ϣ 
	edgenode *firstedge;//�߱�ͷָ��
}vexnode;
//ͼ���ڽӱ���������
typedef struct{
	vexnode vexlist[maxsize];//��������
	int n,e;
}graph;
int a[maxsize][maxsize];//����ͼ���ڽӾ��� 
int b[maxsize][maxsize];//����ͼ���ڽӾ���
//��ͼg�в��Ҷ���v
int locatevex(graph g,elemtype v)
{
	int i;
	for(i=0;i<g.n;i++)
		if(g.vexlist[i].data==v)return i;
		return -1;
}
//���ͼ���ڽӱ���Ϣ
void print(graph g)
{
	int i;
	edgenode *p;
	printf("ͼ���ڽӱ��ʾ��");
	for(i=0;i<g.n;i++){
		printf("\n%4c",g.vexlist[i].data);
		p=g.vexlist[i].firstedge;
		while(p!=NULL){
			printf("-->%c",g.vexlist[p->adjvex].data);p=p->next;
		}
	}
	printf("\n");
}
//����ͼ���ڽӱ�
void creategraph(graph *g){
	int i,j,k;
	int w;
	elemtype v1,v2;
	edgenode *s;
	printf("������ͼ�Ķ�����������\n");
	printf("������ n=");scanf("%d",&g->n);
	printf("��  �� e=");scanf("%d",&g->e);
	printf("������ͼ�Ķ�����Ϣ��\n");getchar();
	for(i=0;i<=g->n;i++){
		scanf("%c",&g->vexlist[i].data); //���춥����Ϣ
		g->vexlist[i].firstedge=NULL;
	}
	printf("������ͼ�ıߵ���Ϣ��\n");
	for(k=0;k<g->e;k++)
	{
		printf("�������%d���ߵ������˵��±꼰��Ȩֵ��",k+1);
		scanf("%c%c %d",&v1,&v2,&w);getchar();//����һ���ߵ���������
		i=locatevex(*g,v1);
		j=locatevex(*g,v2);
		if(i>=0&&j>=0){
			//��������ͼ���ڽӱ�
			/*s=(edgenode *)malloc(sizeof(edgenode));
			s->adjvex=j;
			s->next=g->vexlist[i].firstedge;
			g->vexlist[i].firstedge=s;
			
			  s=(edgenode *)malloc(sizeof(edgenode));
			  s->adjvex=i;
			  s->next=g->vexlist[j].firstedge;
			g->vexlist[j].firstedge=s;*/
			//��������ͼ���ڽӱ�
			s=(edgenode *)malloc(sizeof(edgenode));
			s->adjvex=j;
			s->weight=w;
			s->next=g->vexlist[i].firstedge;
			g->vexlist[i].firstedge=s;
		}
	}
}
int visited[maxsize]={0};/* ���ʱ�־����1*/
int v[maxsize]={0};/* ���ʱ�־����2*/
int count=0;//��¼����������
//�ӵ�i����������ݹ��������ȱ���ͼG
void DFS(graph g,int i)
{
	edgenode *p;
	printf("%3c",g.vexlist[i].data);/*���ʵ�i�����*/
	visited[i]=1;
	p=g.vexlist[i].firstedge;
	while(p!=NULL)    {
		if(visited[p->adjvex]==0)
			DFS(g,p->adjvex);/*��i����δ���ʵ��ڽӶ���j�ݹ����DFS*/
		p=p->next;
	}
}
//��ͼG����������ȱ���
void DFStraverse(graph  g) 
{
	int v;
	for (v=0; v<g.n;v++)visited[v]=0; /*��ʼ����־����*/
	for  (v=0; v<g.n;v++) /*��֤����ͨͼ�ı���*/
		/*�ӵ�v����������ݹ��������ȱ���ͼG*/
		if (!visited[v])DFS(g,v);        
}
//ѭ�����д洢�ṹ����
typedef struct  cirqueue
{
	elemtype0  *data;  //���д洢�ռ���׵�ַ
	int front;         
	int rear;   
}cirqueue; // ѭ������
//����ն�
int initqueue(cirqueue *q)
{
	q->data=(elemtype0 *)malloc(queuesize*sizeof(cirqueue));
	if (q->data==NULL)return 0; // �洢����ʧ�� 
	q->front=q->rear=0;    
	return 1;
}
// ����Ԫ��e
int enqueue (cirqueue *q,elemtype0 e)
{ 
	if ((q->rear+1) % queuesize == q->front) 
		return 0;
	q->data[q->rear] = e;
	q->rear = (q->rear+1) % queuesize; 
	return 1;
}
//�����в��գ�ɾ��Q�Ķ�ͷԪ��
int dequeue (cirqueue *q,int *e) 
{
	if (q->front == q->rear)  return 0; 
	*e = q->data[q->front];
	q->front = (q->front+1) %queuesize; 
	return 1;
}
//��ջ���գ�����e���ض�ͷԪ��
int getfront(cirqueue q,elemtype0 *e)
{
	if (q.front == q.rear)  return 0; 
	*e=q.data[q.front];
	return  1;
}
//������Ϊ��ջ���򷵻�1�����򷵻�0 
int queueempty(cirqueue q)
{ 
	if(q.front == q.rear)return 1; 
	else return 0;
}
//���еĳ���
int queuelength(cirqueue q)
{ 
	return (q.rear-q.front+queuesize) % queuesize;
}
//�����ڽӱ�ʵ����ͨͼ�Ĺ��������������
int BFSvisited[maxsize]={0};
cirqueue q;
/*�ӵ�k���������������ȱ���ͼG,G���ڽӱ��ʾ��*/
void BFS(graph g,int k){
	int i;
	edgenode *p;
	initqueue(&q);/*��ʼ������*/
	printf("%3c",g.vexlist[k].data);/*���ʵ�k�����*/
	BFSvisited[k]=1;    
	enqueue(&q,k);/*��k���������*/
	while(queueempty(q)==0) {/*���зǿ�*/
		dequeue(&q,&i);
		p=g.vexlist[i].firstedge;/*��ȡ��1���ڽӵ�*/
		while(p!=NULL){
			if(BFSvisited[p->adjvex]==0){
				/*���ʵ�i�������ĩ�����ʵĶ���*/
				printf("%3c",g.vexlist[p->adjvex].data);
				BFSvisited[p->adjvex]=1;
				enqueue(&q,p->adjvex);/*��k���������*/
			}
			p=p->next;
		}        
	}
}
//��ͼG���й�����ȱ���
void BFStraverse(graph  g) 
{
	int v;
	for (v=0; v<g.n;v++) //��ʼ����־����
		BFSvisited[v]=0; 
	for  (v=0; v<g.n;v++) //��֤����ͨͼ�ı���
		if (!BFSvisited[v])BFS(g,v); 
        //�ӵ�v����������ݹ��������ȱ���ͼG
}
//���
void  indu(graph g)
{
	edgenode *p;
    int i;
    //������ÿ��������������������ʼֵ��Ϊ0
    int arr[maxsize];
    for(i=0;i<g.n;i++)
    {
        arr[i]=0;
    }
    for(i = 0;i<g.n;i++)
    {
        p = g.vexlist[i].firstedge;
        while(p!=NULL)
        {
            //��������ͼ�Ľṹ
            //��ͷ�ڵ�������ӵı��������p->adjvex������һ�ξ�����Ϊ���һ��
            //����0������1��2����ô����1��2�϶�����Ϊ����һ�Σ�����һ�����
            arr[p->adjvex]++;
            //ָ���ƶ�����һ������
            p=p->next;
        }
		
    }
    for(i=0;i<g.n;i++){
		printf("%c:",g.vexlist[i].data);
        if(i!=g.n-1)
            printf("%d ",arr[i]);
        else
            printf("%d",arr[i]);
    }
	
}
//���� 
void outdu(graph  g)
{
	int i;
	int degree;
	edgenode *p;
	for(i=0;i<g.n;i++)
	{
		degree=0;
		p=g.vexlist[i].firstedge;
		while(p!=NULL)
		{
			degree++;
			p=p->next;
		}
		printf("%c:",g.vexlist[i].data);
		if(i!=g.n-1)
			printf("%d ",degree);
		else
			printf("%d",degree);
	}
}
//�ж���ͨ�㷨
void LT(graph g,int i)
{
	edgenode *p;
	v[i]=1;
	count++;
	p=g.vexlist[i].firstedge;
	while(p!=NULL)    {
		if(v[p->adjvex]==0)
			LT(g,p->adjvex);
		p=p->next;
	}
}
//�����Ƿ���ͨ�Ľ��
void isLT(graph g,int i)
{
	LT(g,i);
	if(count==g.n)
		printf("������ͼ��ͨ\n");
	else
		printf("������ͼ����ͨ\n");
}
//������ͼ���ڽӱ�ת�����ڽӾ���
void trans(graph  g)
{
	int i,j;
	edgenode *p;	
	for(i=0;i<=g.n;i++)//�ȳ�ʼ����ȫ����ֵΪ��
		for(j=0;j<=g.n;j++)	
		{		
			a[i][j]=INT_MAX;	
		}
		for(i=0;i<g.n;i++)	
		{		
			p=g.vexlist[i].firstedge;
			while(p)		
			{			
				a[i][p->adjvex]=p->weight;
				p=p->next;		
			}	
		}
} 
//����ڽӾ���
void Output(graph  g,int arr[maxsize][maxsize])
{	
	int i,j;
	for(i=0;i<g.n;i++)
	{	
		for(j=0;j<g.n;j++)	
		{		
			if(arr[i][j]==Max)
				printf("�� ");
			else
				printf("%2d ",arr[i][j]);	
		}	
		printf("\n");
	}		
}
//����ͼ���ڽӾ���ת��������ͼ���ڽӾ���
void change(graph  g)
{
	int i,j;
	for(i=0;i<g.n;i++)
		for(j=0;j<g.n;j++)
		{
			b[i][j] = INT_MAX;
		}
		for(i=0;i<g.n;i++)
		{
			for(j=0;j<g.n;j++)
			{
				if(a[i][j]!=Max)
					b[j][i]=b[i][j]=a[i][j];
			}
		}
}
//��С������ ����ķ�㷨  �����ڽӾ���  
void MiniSpanTree(graph  g)  
{  
    int min, i, j, k;  
    char adjvex[maxsize];     //������ض����±�  
    int lowcost[maxsize];    //������ض����ߵ�Ȩֵ  
    lowcost[0] = 0;         //��ʼ����һ��ȨֵΪ0����V0����������  
    adjvex[0] = 'a';          //��ʼ����һ�������±�Ϊ0  
	//��ʼ������
    for (i=1; i<g.n; ++i)  
    {  
        lowcost[i] = b[0][i];  
        adjvex[i] = 'a';              //��v0������֮�бߵ�Ȩֵ��������  ����ʼ����Ϊv0���±�  
    }  //adjvex[i]��i�������ڵ�ı�ǣ�adjvex[i]=0���ǰ�0~n�Ľڵ㶼��ڵ�0��������
	
    for (i=1; i<g.n; ++i)  
    {  
        min = Max;  
        j = 1;  
        k = 0;  //����Ȩֵ��С�Ķ���
        //����v-u������ʣ�µĽڵ�
        while (j<g.n)  
        {  
            //�����������֮����ڱ߲���ȨֵС��min  
            if (lowcost[j]!=0 && lowcost[j]<min)  
            {  
                min = lowcost[j];  
                k = j;  
            }  
			
            ++j;  
        }  
        printf("(%c, %c) ", adjvex[k], g.vexlist[k].data);   //�����ǰ�������Ȩֵ��С�ı�  
        lowcost[k] = 0;                     //����ǰ�����Ȩֵ��Ϊ0����ʾ�˶����Ѿ��������  
        //�����½ڵ��������ڵ�֮�����С���Ѻ͹���
        for (j=1; j<g.n; ++j)  
        {  
            if (lowcost[j]!=0 && b[k][j]<lowcost[j])  
            {  
                lowcost[j] = b[k][j];  
                adjvex[j] = g.vexlist[k].data;  
            }  
        }  
    }  
}
//�ڳ���Ϊn�Ķ�������G��ɾ������������ϢΪc�Ķ���
void delete0(graph  g,char c)
{
	int position = -1; //��ʾɾ�������ڶ��������е�λ��
	int i,j;
	edgenode *p, *q, *r;
	if(locatevex(g,c)<0)
	{
		printf("��%c!\n",c);
		return;
	}
	else
	{
		//�����������飬��ɾ�����������еı�ɾ����		
		for(i=0; i<g.n; i++) 
		{	
			if(g.vexlist[i].data == c) 
			{	
				position = i;	
				p = g.vexlist[i].firstedge;		
				for(j=i+1; j<g.n; j++)
				{	
					g.vexlist[j-1].data=g.vexlist[j].data;
					g.vexlist[j-1].firstedge=g.vexlist[j].firstedge;	
				}
				g.n--;
				break;	
			}		
		}	
		if(position == -1) 
		{	
			printf("������������ϢΪ%c�Ķ���" ,c);	
		}
		else 
		{	
			//ɾ����ɾ�������ӵı���Ϣ
			while(p) 
			{		
				q = p->next;	
				free(p);		
				p = q;	
			}	
			//ɾ��������������position��صı߽��	
			for(i=0; i<g.n; i++) 
			{	
				p = g.vexlist[i].firstedge;	
				while(p) 
				{		
					if (p->adjvex == position) 
					{		
						if(p == g.vexlist[i].firstedge)
						{		
							g.vexlist[i].firstedge=p->next;		
						}		
						else 
						{			
							r->next = p->next;			
						}	
						q = p;
						p = p->next;	
						free(q);		
					}
					else 
					{	
						if(p->adjvex > position)
						{
							p->adjvex--;	
						}	
						r = p;
						p = p->next;	
					}	
				}
			}	
		}
		printf("ɾ������%c��DFS����Ϊ��\n",c);
		DFStraverse(g);
	}
}
int main()
{
	graph g;
	creategraph(&g);
	print(g);
	printf("\n");
	printf("ͼ��������ȱ������У�\n");
	DFS(g,2);
	//DFStraverse(g);
	printf("\n");
	printf("ͼ�Ĺ�����ȱ������У�\n");
	BFS(g,2);
	//BFStraverse(g);
	printf("\n"); 
	printf("ͼ�ĸ��������ȷֱ�Ϊ��\n");
	indu(g);
	printf("\n");
	printf("ͼ�ĸ�����ĳ��ȷֱ�Ϊ��\n");
	outdu(g);
	printf("\n");
	isLT(g,0);
	trans(g);
	printf("�ɸ�ͼ���ڽӱ�ת���ɵ��ڽӾ���Ϊ��\n");
	Output(g,a);
	change(g);
	printf("������ͼ��Ӧ������ͼ���ڽӾ���Ϊ��\n");
	Output(g,b);
	printf("��ͼ��һ����С������Ϊ��\n");
	MiniSpanTree(g);
	printf("\n");
	delete0(g,'x');
	delete0(g,'e');
	printf("\n");
	return 0;
}
/*
ab 2
ag 15
af 9
bc 4
bg 6
ci 15
cd 2
de 1
di 1
ef 6
eh 3
fh 11
hi 4
gh 15
gi 2
*/
