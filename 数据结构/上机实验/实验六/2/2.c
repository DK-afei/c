#include <stdio.h>  
#include <conio.h>  
#include <malloc.h>  
#define MAX_NUM 20  
typedef struct ArcNode {  
	int adjvex;  
	struct ArcNode *nextarc;  
}ArcNode;  
typedef int VertexType;  
typedef struct VNode {  
	VertexType data;  
	ArcNode *firstarc;  
}VNode,AdjList[MAX_NUM];  
void createDgraph(AdjList g,int n){  
	ArcNode *p,*q;  
	int i,j;  
	for (i=1;i<=n;i++)  
	{  
		g[i].data=i;  
		g[i].firstarc=NULL;  
	}  
	printf("\nEdgei->j:");  
	scanf("%d%d",&i,&j);  
	while (i!=-1)  
	{  
		p=(ArcNode *)malloc(sizeof(ArcNode));  
		q=(ArcNode *)malloc(sizeof(ArcNode));  
		p->adjvex=j;  
		p->nextarc=g[i].firstarc;  
		g[i].firstarc=p;  
		q->adjvex=i;  
		q->nextarc=g[j].firstarc;  
		g[j].firstarc=q;  
		printf("\nEdge i->j:");  
		scanf("%d%d",&i,&j);  
	}  
}  
int visited[MAX_NUM]={0};
int count=0;
void DFS(AdjList G,int v){
	ArcNode *p;
	visited[v]=1;
	count++;
	printf("%d ",v);
	p=G[v].firstarc;
	while(p!=NULL){
		if(visited[p->adjvex]==0){
			DFS(G,p->adjvex);
		}
		p=p->nextarc;
	}
}

void BFS(AdjList G,int v){
	ArcNode *p;
	int Qu[20],front,rear;
	int visited[20]={0};
	int w;
	front=rear=0;
	printf("%d ",v);
	visited[v]=1;
	rear=(rear+1)%20;
	Qu[rear]=v;
	while(front!=rear){
		front=(front+1)%20;
		w=Qu[front];
		p=G[w].firstarc;
		while(p){
			if(visited[p->adjvex]==0){
				printf("%d ",p->adjvex);
				visited[p->adjvex]=1;
				rear=(rear+1)%20;
				Qu[rear]=p->adjvex;
			}
			p=p->nextarc;
		}
	}
}
void printDgraph(AdjList g,int n){  
	ArcNode *p;  
	int i;  
	for (i=1;i<=n;i++)  
	{  
		printf("\n%d: ",g[i].data);  
		p=g[i].firstarc;  
		while (p)  
		{  
			printf("->%d",p->adjvex);  
			p=p->nextarc;  
		}  
	}  
}  
int main()  
{  
	AdjList g;  
	int num;  
	printf("Input Number of Vertex:");  
	scanf("%d",&num);  
	createDgraph(g,num);  
	printDgraph(g,num);  
	printf("\n");  
	printf("深度优先:");
	DFS(g,num);
	printf("\n");
	printf("广度优先:");
	BFS(g,num);
	printf("\n");
	if(count==num)
		printf("且得该无向图连通\n");
	else
		printf("且得该无向图不连通\n");
	
	return 0;  
}  