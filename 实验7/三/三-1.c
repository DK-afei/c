#include "stdio.h"
#include "stdlib.h"
#define N 3
void main()
{
	int i;
	float ave=0,sum=0;
	float*temprature=(float*)malloc(N*sizeof(float));
	
	for(i=0;i<N;i++)
	{
	scanf("%f",temprature+i);
	}
	for(i=0;i<N;i++)
	{
	sum+=*(temprature+i);
	}
	ave=(float)(sum/N);
		printf("%f",ave);
		printf("\n");
}