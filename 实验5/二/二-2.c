#include "stdio.h"
#define N 1000
void main()
{
	float a[N],max;
	int i;
	int count,leap;
	for(i=0;i<N;i++)
	{
		scanf("%f",&a[i]);
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
		leap=i;
	}
	printf("%.3f\n",max);
	printf("%d\n",count);
	printf("%d",leap);
}
