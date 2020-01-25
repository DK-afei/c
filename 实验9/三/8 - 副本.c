#include <stdio.h>
#define M 3//subjects
#define N 3//peoples
void mscore(float(*score)[N],int*s,int*c)
{
	int i,j;
	float max=*(*(score+0)+0);
	for(j=0;j<N;j++)
	{
		for(i=0;i<M;i++)
		{
			if(max<*(*(score+i)+j))
			{
				*s=j;
				*c=i;
			}
		}
	}
}
void main()
{
	float a[M][N];
	int i,j,c,d;
	for(i=0;i<M;i++)
	{
		for(j=0;j<N;j++)
		{
			scanf("%f",&a[i][j]);
		}
	}
	mscore(a,&c,&d);
		printf(	"%d,%d",c,d);
	printf("\n");
}
