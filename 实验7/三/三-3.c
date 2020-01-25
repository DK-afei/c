#include "stdio.h"
#include "stdlib.h"
#define N 3
void main()
{
	int i,sum=0;
	float ave=0,cha=0;
	int*a=(int*)malloc(N*sizeof(int));
	
	for(i=0;i<N;i++)
	{
	scanf("%d",a+i);
	}
	for(i=0;i<N;i++)
	{
	sum+=*(a+i);
	
	}
	ave=(float)(sum/N);
	for(i=0;i<N;i++)
	printf("cha=%.f\n",(*(a+i)-ave));

		printf("ave=%.f",ave,cha);
		printf("\n");
}