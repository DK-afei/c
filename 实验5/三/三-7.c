#include "stdio.h"
#define N 3
	int a[N][N];
void main()
{
	int row,col,max,min;
	for(row=0;row<N;row++)
	{
		for(col=0;col<N;col++)
		{
			scanf("%d",&a[row][col]);
		}
	}
	for(row=0;row<N;row++)
	{
		for(max=a[row][0],col=1;col<N;col++)
		{

		if(max<=a[row][col])
			max=a[row][col];
		if(max<=a[++row][col-1])
			min=max;
		else if(max<=min)
			min=max;
	
		}
	}
	printf("The min of max number is %d\n",min);
}