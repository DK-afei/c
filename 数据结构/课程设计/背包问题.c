#include <stdio.h>
#include <stdlib.h>
#define maxsize 20
typedef struct
{
    int size[maxsize];
    int top;
}seqstack;//栈
//栈的初始化
void initstack(seqstack *s)
{
	int i;
    s->top=0;
    for(i=0;i<maxsize;i++)
        s->size[i]=0;
}
//入栈
void push(seqstack *s,int x)
{
    if(s->top+1==maxsize)   
		printf("Overflow\n");
    else    
    {
        s->size[s->top++]=x;
    }
}
//出栈
void pop(seqstack *s)
{
    if(s->top==-1)   
		printf("Underflow\n");
    else
		s->top--;
}
//利用栈的后进先出进行回溯法求解
void ways(seqstack *s,int num,int w[],int T)
{
    int k=0,i=0,j=1;
    do   
    {  
        while(T>0&&k<=num)   
        {    
            if(T>=w[k])    
            {     
                push(s,k);
                T-=w[k];    
            }    
            k++;   
        }   
        if(T==0)   
        {
            printf("\n第%d组解（",j );
            for(i=0;i<s->top;i++)    
            {     
                printf("%d  ",w[s->size[i]]);    
            }    
            j++;    
            printf("）\n");   
        }   
        pop(s);   
        k=s->size[s->top];
        s->size[s->top]=0;   
        T+=w[k];   
        k++;  
    }while(!(s->top==0&&k==num));  
}
int main()
{
	int i;
    int T;
	int num;
	int w[maxsize];
	seqstack *s;
	s=(seqstack*)malloc(sizeof(seqstack));
	initstack(s);
    printf("请输入背包体积：");
    scanf("%d",&T); 
    printf("请输入物品件数：");
    scanf("%d",&num);	 
    printf("请输入各物体体积：\n");
    for(i=0;i<num;i++)
    {
        scanf("%d",&w[i]);
	} 
    ways(s,num,w,T);
    return 0;
}