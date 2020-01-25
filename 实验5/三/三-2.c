#include <stdio.h>
#define M 3
#define N 2
void main(void)
{
			int i,j,k=0;
			int a[M][N];
			for (i=0;i<M;i++)
			{
			for (j=0;j<N;j++)
			{
			scanf("%d",&a[i][j]);
			}
			}
			for (i=0;i<M;i++)
			{
			for (j=0;j<N;j++)
			{
			printf("%4d",a[i][j]);

			}
			printf("\n");
			}

			for (i=0;i<M;i++)
			{
				for(j=0;j<N;j++)
				{
				if(a[i][j]>a[i+1][j])
				{
					k = a[i][j];
					a[i][j] = a[i+1][j];
					 a[i+1][j] = k;
				}
				}
			
			}
			for (i=0;i<M;i++)
			{
			for (j=0;j<N;j++)
			{
				printf("%-5d",a[i][j]);

			}
			printf("\n");
			}
}
