#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1
#define Overflow 2
#define Underflow 3
#define NotPresent 4
#define Duplicate 5
typedef int ElemType;
typedef struct
{
	ElemType **a;         
	int n;                
	int e;                
	ElemType noEdge;      
}mGraph;
typedef int Status;
Status Init (mGraph *mg,int nSize,ElemType noEdgeValue)
{
	int i,j;
    mg->n=nSize; 
    mg->e=0;  
	mg->noEdge=noEdgeValue; 
	mg->a=(ElemType**)malloc(nSize*sizeof(ElemType*));    
	if(!mg->a)
		return ERROR;
	for(i=0;i<mg->n;i++)               
	{
		mg->a [i]=(ElemType*)malloc(nSize*sizeof(ElemType*));
		for(j=0;j<mg->n;j++)
			mg->a[i][j]=mg->noEdge;
		mg->a[i][j]=0;
	}
	return OK;
}
void   Destroy (mGraph *mg )   
{
	int i;
	for(i=0;i<mg->n;i++)       
		free(mg->a[i]);        
	free(mg->a);
}
Status Exist(mGraph *mg,int u,int v)  
{
	if(u<0||v<0||v>mg->n-1||u==v||mg->a[u][v]==mg->noEdge)
		return ERROR;
	return OK;
}
Status Insert(mGraph *mg,int u,int v,ElemType w)        
{
	if(u<0||v<0||v>mg->n-1||u==v) return ERROR;
	if(mg->a[u][v]!=mg->noEdge)
		return Duplicate;      
	mg->a[u][v]=w;             
	mg->e++;
	return OK;
}
Status Remove(mGraph *mg,int u,int v)        
{
	if(u<0||v<0||v>mg->n-1||u==v)
		return ERROR;
	if(mg->a[u][v]==mg->noEdge)          
		return NotPresent;
	mg->a[u][v]=mg->noEdge;              
	mg->e--;
	return OK;
}
Status Putout(mGraph *mg)
{
	int i,j;
    for(i=0;i<mg->n;i++)
	{ for(j=0;j<mg->n;j++)
	{printf("%d",mg->a[i][j]);}
	printf("\n");
	}
}
void main()
{
	mGraph mg;
	Init (&mg,4,0);
	Insert(&mg,1,0,1);
	Insert(&mg,1,2,1);
	Insert(&mg,2,3,1);
	Insert(&mg,3,0,1);
	Remove(&mg,3,0);
	Putout(&mg);
	//Exist(&mg,1,1);
	// Destroy (&mg);
}
