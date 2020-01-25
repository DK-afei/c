#include <stdio.h>
#define N 5
struct shares
{
	char name[64];
	float profit;
	float rate;
}share[N];
void main()
{


		int i;
		printf("please input datas:\n");
		for(i=0;i<N;i++)
		{
		scanf("%s",share[i].name);
		scanf("%f",&share[i].profit);
		scanf("%f",&share[i].rate);
		}
		for(i=0;i<N;i++)
		{
		printf("%.2f",share[i].profit*share[i].rate);
		printf("\n");
		}
	
}

