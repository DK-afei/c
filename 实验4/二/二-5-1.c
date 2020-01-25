#include <stdio.h>
void main()
{
			int i,j;
			int count=0;

			for(i=1;i<=9;i++)
			{

			count++;
			for(j=1;j<=count;j++)
			printf("	");
			for(j=count;j<=9;j++)
			printf("%d*%d=%d	",i,j,i*j);
			printf("\n");

			}
}