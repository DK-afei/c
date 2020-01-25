#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef char elemtype;//顶点类型
typedef int elemtype0;//队列元素类型
#define maxsize 10//图顶点的最大数目
#define queuesize 100//队列的最大容量
#define Max INT_MAX//无穷大
//边结点的类型定义
typedef struct edgenode
{
	int adjvex;//存放邻接的点在顶点表的下标，邻接点
	struct edgenode *next;//指向Vi下一个邻接点的边结点
	int weight;/*权值*/
}edgenode;
//顶点结点类型定义
typedef struct vexnode
{
	elemtype data; //存储顶点的名称或其相关信息 
	edgenode *firstedge;//边表头指针
}vexnode;
//图的邻接表数据类型
typedef struct{
	vexnode vexlist[maxsize];//顶点数组
	int n,e;
}graph;
int a[maxsize][maxsize];//有向图的邻接矩阵 
int b[maxsize][maxsize];//无向图的邻接矩阵
//在图g中查找顶点v
int locatevex(graph g,elemtype v)
{
	int i;
	for(i=0;i<g.n;i++)
		if(g.vexlist[i].data==v)return i;
		return -1;
}
//输出图的邻接表信息
void print(graph g)
{
	int i;
	edgenode *p;
	printf("图的邻接表表示：");
	for(i=0;i<g.n;i++){
		printf("\n%4c",g.vexlist[i].data);
		p=g.vexlist[i].firstedge;
		while(p!=NULL){
			printf("-->%c",g.vexlist[p->adjvex].data);p=p->next;
		}
	}
	printf("\n");
}
//创建图的邻接表
void creategraph(graph *g){
	int i,j,k;
	int w;
	elemtype v1,v2;
	edgenode *s;
	printf("请输入图的顶点数及边数\n");
	printf("顶点数 n=");scanf("%d",&g->n);
	printf("边  数 e=");scanf("%d",&g->e);
	printf("请输入图的顶点信息：\n");getchar();
	for(i=0;i<=g->n;i++){
		scanf("%c",&g->vexlist[i].data); //构造顶点信息
		g->vexlist[i].firstedge=NULL;
	}
	printf("请输入图的边的信息：\n");
	for(k=0;k<g->e;k++)
	{
		printf("请输入第%d条边的两个端点下标及其权值：",k+1);
		scanf("%c%c %d",&v1,&v2,&w);getchar();//输入一条边的两个顶点
		i=locatevex(*g,v1);
		j=locatevex(*g,v2);
		if(i>=0&&j>=0){
			//建立无向图的邻接表
			/*s=(edgenode *)malloc(sizeof(edgenode));
			s->adjvex=j;
			s->next=g->vexlist[i].firstedge;
			g->vexlist[i].firstedge=s;
			
			  s=(edgenode *)malloc(sizeof(edgenode));
			  s->adjvex=i;
			  s->next=g->vexlist[j].firstedge;
			g->vexlist[j].firstedge=s;*/
			//建立有向图的邻接表
			s=(edgenode *)malloc(sizeof(edgenode));
			s->adjvex=j;
			s->weight=w;
			s->next=g->vexlist[i].firstedge;
			g->vexlist[i].firstedge=s;
		}
	}
}
int visited[maxsize]={0};/* 访问标志数组1*/
int v[maxsize]={0};/* 访问标志数组2*/
int count=0;//记录遍历顶点数
//从第i个顶点出发递归地深度优先遍历图G
void DFS(graph g,int i)
{
	edgenode *p;
	printf("%3c",g.vexlist[i].data);/*访问第i个项点*/
	visited[i]=1;
	p=g.vexlist[i].firstedge;
	while(p!=NULL)    {
		if(visited[p->adjvex]==0)
			DFS(g,p->adjvex);/*对i的尚未访问的邻接顶点j递归调用DFS*/
		p=p->next;
	}
}
//对图G进行深度优先遍历
void DFStraverse(graph  g) 
{
	int v;
	for (v=0; v<g.n;v++)visited[v]=0; /*初始化标志数组*/
	for  (v=0; v<g.n;v++) /*保证非连通图的遍历*/
		/*从第v个顶点出发递归地深度优先遍历图G*/
		if (!visited[v])DFS(g,v);        
}
//循环队列存储结构定义
typedef struct  cirqueue
{
	elemtype0  *data;  //队列存储空间的首地址
	int front;         
	int rear;   
}cirqueue; // 循环队列
//构造空队
int initqueue(cirqueue *q)
{
	q->data=(elemtype0 *)malloc(queuesize*sizeof(cirqueue));
	if (q->data==NULL)return 0; // 存储分配失败 
	q->front=q->rear=0;    
	return 1;
}
// 插入元素e
int enqueue (cirqueue *q,elemtype0 e)
{ 
	if ((q->rear+1) % queuesize == q->front) 
		return 0;
	q->data[q->rear] = e;
	q->rear = (q->rear+1) % queuesize; 
	return 1;
}
//若队列不空，删除Q的队头元素
int dequeue (cirqueue *q,int *e) 
{
	if (q->front == q->rear)  return 0; 
	*e = q->data[q->front];
	q->front = (q->front+1) %queuesize; 
	return 1;
}
//若栈不空，则用e返回队头元素
int getfront(cirqueue q,elemtype0 *e)
{
	if (q.front == q.rear)  return 0; 
	*e=q.data[q.front];
	return  1;
}
//若队列为空栈，则返回1，否则返回0 
int queueempty(cirqueue q)
{ 
	if(q.front == q.rear)return 1; 
	else return 0;
}
//队列的长度
int queuelength(cirqueue q)
{ 
	return (q.rear-q.front+queuesize) % queuesize;
}
//利用邻接表实现连通图的广度优先搜索遍历
int BFSvisited[maxsize]={0};
cirqueue q;
/*从第k个顶点出发广度优先遍历图G,G以邻接表表示。*/
void BFS(graph g,int k){
	int i;
	edgenode *p;
	initqueue(&q);/*初始化队列*/
	printf("%3c",g.vexlist[k].data);/*访问第k个项点*/
	BFSvisited[k]=1;    
	enqueue(&q,k);/*第k个顶点进队*/
	while(queueempty(q)==0) {/*队列非空*/
		dequeue(&q,&i);
		p=g.vexlist[i].firstedge;/*获取第1个邻接点*/
		while(p!=NULL){
			if(BFSvisited[p->adjvex]==0){
				/*访问第i个顶点的末曾访问的顶点*/
				printf("%3c",g.vexlist[p->adjvex].data);
				BFSvisited[p->adjvex]=1;
				enqueue(&q,p->adjvex);/*第k个顶点进队*/
			}
			p=p->next;
		}        
	}
}
//对图G进行广度优先遍历
void BFStraverse(graph  g) 
{
	int v;
	for (v=0; v<g.n;v++) //初始化标志数组
		BFSvisited[v]=0; 
	for  (v=0; v<g.n;v++) //保证非连通图的遍历
		if (!BFSvisited[v])BFS(g,v); 
        //从第v个顶点出发递归地深度优先遍历图G
}
//入度
void  indu(graph g)
{
	edgenode *p;
    int i;
    //数组存放每个顶点的入度数量，赋初始值都为0
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
            //根据有向图的结构
            //表头节点后面连接的表体的数据p->adjvex，出现一次就是作为入度一次
            //比如0后面有1，2，那么顶点1和2肯定都作为后驱一次，就有一个入度
            arr[p->adjvex]++;
            //指针移动到下一个表体
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
//出度 
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
//判断连通算法
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
//给出是否连通的结果
void isLT(graph g,int i)
{
	LT(g,i);
	if(count==g.n)
		printf("该有向图连通\n");
	else
		printf("该有向图不连通\n");
}
//将有向图的邻接表转换成邻接矩阵
void trans(graph  g)
{
	int i,j;
	edgenode *p;	
	for(i=0;i<=g.n;i++)//先初始化，全部赋值为∞
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
//输出邻接矩阵
void Output(graph  g,int arr[maxsize][maxsize])
{	
	int i,j;
	for(i=0;i<g.n;i++)
	{	
		for(j=0;j<g.n;j++)	
		{		
			if(arr[i][j]==Max)
				printf("∞ ");
			else
				printf("%2d ",arr[i][j]);	
		}	
		printf("\n");
	}		
}
//有向图的邻接矩阵转化成无向图的邻接矩阵
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
//最小生成树 普里姆算法  采用邻接矩阵  
void MiniSpanTree(graph  g)  
{  
    int min, i, j, k;  
    char adjvex[maxsize];     //保存相关顶点下标  
    int lowcost[maxsize];    //保存相关顶点间边的权值  
    lowcost[0] = 0;         //初始化第一个权值为0，即V0加入生成树  
    adjvex[0] = 'a';          //初始化第一个顶点下标为0  
	//初始化操作
    for (i=1; i<g.n; ++i)  
    {  
        lowcost[i] = b[0][i];  
        adjvex[i] = 'a';              //将v0顶点与之有边的权值存入数组  并初始化都为v0的下标  
    }  //adjvex[i]，i是其他节点的标记，adjvex[i]=0即是把0~n的节点都与节点0关联起来
	
    for (i=1; i<g.n; ++i)  
    {  
        min = Max;  
        j = 1;  
        k = 0;  //保存权值最小的顶点
        //遍历v-u集合中剩下的节点
        while (j<g.n)  
        {  
            //如果两个顶点之间存在边并且权值小于min  
            if (lowcost[j]!=0 && lowcost[j]<min)  
            {  
                min = lowcost[j];  
                k = j;  
            }  
			
            ++j;  
        }  
        printf("(%c, %c) ", adjvex[k], g.vexlist[k].data);   //输出当前顶点边中权值最小的边  
        lowcost[k] = 0;                     //将当前顶点的权值设为0，表示此顶点已经完成任务  
        //更新新节点与其他节点之间的最小花费和关联
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
//在长度为n的顶点数组G中删除顶点数据信息为c的顶点
void delete0(graph  g,char c)
{
	int position = -1; //表示删除顶点在顶点数组中的位置
	int i,j;
	edgenode *p, *q, *r;
	if(locatevex(g,c)<0)
	{
		printf("无%c!\n",c);
		return;
	}
	else
	{
		//遍历顶点数组，并删除顶点数组中的被删顶点		
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
			printf("不存在数据信息为%c的顶点" ,c);	
		}
		else 
		{	
			//删除被删顶点链接的边信息
			while(p) 
			{		
				q = p->next;	
				free(p);		
				p = q;	
			}	
			//删除其它顶点中与position相关的边结点	
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
		printf("删除顶点%c的DFS序列为：\n",c);
		DFStraverse(g);
	}
}
int main()
{
	graph g;
	creategraph(&g);
	print(g);
	printf("\n");
	printf("图的深度优先遍历序列：\n");
	DFS(g,2);
	//DFStraverse(g);
	printf("\n");
	printf("图的广度优先遍历序列：\n");
	BFS(g,2);
	//BFStraverse(g);
	printf("\n"); 
	printf("图的各顶点的入度分别为：\n");
	indu(g);
	printf("\n");
	printf("图的各顶点的出度分别为：\n");
	outdu(g);
	printf("\n");
	isLT(g,0);
	trans(g);
	printf("由该图的邻接表转化成的邻接矩阵为：\n");
	Output(g,a);
	change(g);
	printf("该有向图对应的无向图的邻接矩阵为：\n");
	Output(g,b);
	printf("该图的一颗最小生成树为：\n");
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
