#include <stdio.h>
#include <stdlib.h>
#define N 1
typedef struct
{
	char *pname;
	int state;
	float arrival_time;
	float run_time;
}pcb;
pcb *m(int i)
{
	pcb *p;
	p=(pcb*)malloc(sizeof(pcb));
	printf("please input name,state,arrival_time and run_time of the %dth process :\n",i+1);
	scanf("%s",p->pname);
	scanf("%d",p->state);
	scanf("%f",p->arrival_time);
	scanf("%f",p->run_time);
	return p;
}
void pp(pcb *p)
{
	printf("%s\n",p->pname);
	printf("%d\n",p->state);
	printf("%f\n",p->arrival_time);
	printf("%f\n",p->run_time);
}
void input(pcb *p[N])
{
	int i;
	for(i=0;i<N;i++)
	{
		p[i]=m(i);
	}
	
	for(i=0;i<N;i++)
	{
		pp(p[i]);
	}
}
int main()
{
	pcb *p[N];
	input(p);
	printf("hello world!\n");
	return 0;
}
