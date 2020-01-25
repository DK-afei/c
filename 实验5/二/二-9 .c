#include "stdio.h"
void main()
{
	int A[2][3],B[2][3],C[2][3];	
	int i,j;
	
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			scanf("%d%d",&A[i][j],&B[i][j]);
		}
	}
	for(i=0;i<2;++)
	{
		for(j=0;j<3;j++)
		{
		C[i][j]=A[i][j]+B[i][j];
		 printf("%d",C[i][j]);	
		}
		printf("\n");
	}
	
}