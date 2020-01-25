#include <stdio.h>
#define N 5
struct boat
{
	char name[20] ; 
	int n1;
	float l;	
	int n2;
}boats[N];
void main()
{
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%s",&boats[i].name);
		scanf("%d",&boats[i].n1);
		scanf("%f",&boats[i].l);
		scanf("%d",&boats[i].n2);
	}
	printf("姓名：\t小船行驶证号：\t小船长度：\t当前停靠的码头号：\n");
	for(i=0;i<N;i++)
	{
		printf("%s\t\t",boats[i].name);
		printf("%d\t",boats[i].n1);
		printf(" %.2f\t\t",boats[i].l);
		printf("   %d\n",boats[i].n2);
	}
	printf("\n");
}