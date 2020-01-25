#include "stdio.h"
#define N 1000
void main()
{
	int a[N];
	int i,max;
	int count;
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==0)
		{
			count=i;
		break;
		}
	}
	max=a[0];
	for(i=0;i<N;i++)
	{
	
		if(a[i]>max)
			max=a[i];
	}
	printf("%d\n",max);
	printf("%d\n",count);
}
