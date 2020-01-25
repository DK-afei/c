#include "stdio.h"
#define N 5
void main()
{
	int a[N],b[N];
	int c[N];
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
		scanf("%d",&b[i]);
	}
	for(i=0;i<N;i++)
	{
		c[i]=a[i]+b[i];
		printf("%-5d",c[i]);
	}
	printf("\n");	
}