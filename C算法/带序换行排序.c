#include "stdio.h"
#define N 5
void main()
{
	int a[N],b[N];
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<N;i++)
	{
		b[i]=a[N-i-1];
		printf("%-3d",b[i]);
	}

}