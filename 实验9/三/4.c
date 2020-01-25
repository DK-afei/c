#include <stdio.h>
#define M 3
#define N 4
int FindMax(int(*data)[4])
{
	int i,j;
	int max=*(*(data+0)+0);
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			if(max<*(*(data+i)+j))
				max=*(*(data+i)+j);
		}
	}
		return max;
}
void main()
{
	int a[M][N];
	int i,j;
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
		scanf("%d",&a[i][j]);
		}
	}
	printf("max=%d\n",FindMax(a));
}