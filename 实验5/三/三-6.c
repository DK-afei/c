#include <stdio.h>
#define N 5
void main(void)
{
			int i,j,k=0;
			int a[N][N] = {0};
			for (i=0;i<N;i++)
			{
			for (j=0;j<N;j++)
			{
			scanf("%d",&a[i][j]);
			}
			}

			printf("����������Ϊ��\n");
			for (i=0;i<N;i++)
			{
			for (j=0;j<N;j++)
			{
			printf("%4d",a[i][j]);

			}
			printf("\n");
			}

			for (i=0;i<N;i++)
			{
			k = a[1][i];
			a[1][i] = a[4][i];
			 a[4][i] = k;
			}
			printf("�ڶ��к͵����н���������Ϊ��\n");
			for (i=0;i<N;i++)
			{
			for (j=0;j<N;j++)
			{
			printf("%5d",a[i][j]);

			}
			printf("\n");
			}
}
