#include <stdio.h>
#define M 3
#define N 3
void minvert(int(*maxtrix)[M])
{
	int i,j,t;
	for(i=0;i<M;i++)
	{
		for(j=0;j<i;j++)
		{
		t=*(*(maxtrix+i)+j);
		*(*(maxtrix+i)+j)=*(*(maxtrix+j)+i);
		*(*(maxtrix+j)+i)=t;
		}
	}
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
	minvert(a);
		for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
		printf("	%d",a[i][j]);
		}
	}
	printf("\n");
}