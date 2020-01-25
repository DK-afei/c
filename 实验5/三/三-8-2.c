#include "stdio.h"
#define N 10
void main()
{
	int a[N];
	int j,i,t,leap;
	for(i=0;i<N;i++)
		scanf("%d",&a[i]);

	for(i=0;i<N-1;i++)
	{
		leap=i;
		for(j=i+1;j<N;j++)
		{
			if(a[leap]<a[j])
				leap=j;
		}

		if(leap!=i)
		{
			t=a[leap];
			a[leap]=a[i];
			a[i]=t;
		}

	}

	for(i=0;i<N;i++)
	printf("%-3d",a[i]);
	printf("\n");
}
