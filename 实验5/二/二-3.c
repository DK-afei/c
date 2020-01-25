#include "stdio.h"
#define N 1000
void main()
{
	int a[N];
	int i,max,min;
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
		min=a[count-1];
	for(i=count-1;i=0;--i)
	{
	
		if(a[i]<min)
			min=a[i];
	}	
	printf("min=%d\n",min);	
	printf("max=%d\n",max);
	printf("cha=%d\n",max-min);
	printf("%d\n",count);
}
