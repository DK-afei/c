#include <stdio.h>
#define M 5//subjects
#define N 100//peoples
void stuave(float(*score)[N],float ave[10],int n)
{
	int i,j;
	float sum;
	for(j=0;j<n;j++)
	{
		sum=0;
		for(i=0;i<M;i++)
		{
			sum+=*(*(score+i)+j);
		}
		ave[j]=sum/M;
	}
}
void main()
{
	float a[M][N];
	float b[10];
	int n,i,j;
	scanf("%d",&n);
	fflush(stdin);
	for(i=0;i<M;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%f",&a[i][j]);
		}
	}
	stuave(a,b,n);
	for(i=0;i<10;i++)
		printf(	"	%.2f",b[i]);
	printf("\n");
}
