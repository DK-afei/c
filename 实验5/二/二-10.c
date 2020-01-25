#include "stdio.h"
#define N 3
void main()
{
	int a[N][N];	
	int i,j,sum;
	
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
		sum=a[0][0]+a[1][1]+a[2][2];
		printf("%d ",sum);
		printf("\n");		
		
	
	
}