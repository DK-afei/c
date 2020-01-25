#include <stdio.h>
#define N 5
void main()
{
	int i,j,t;
	int a[N];
	int min;
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);																		   
	for(i=0;i<N-1;i++)
	{
		min=i;
		for(j=i+1;j<N;j++)
		{
			if(a[j]<a[min])
				min=j;
		}
		if(min!=i)
		{
			t=a[min];
			a[min]=a[i];
			a[i]=t;
		}
	}
	for(i=0;i<N;i++)
		printf("%-5d",a[i]);
	printf("\n");

}