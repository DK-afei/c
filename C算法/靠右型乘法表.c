#include <stdio.h>
main()
{
			int i,j,m;
			for(i=1;i<10;i++)

			{
			for(m=1;m<i;m++)
			printf("	");
			for(j=i;j<10;j++)
			printf("%d*%d=%2d	",i,j,i*j);
			printf("\n");
			}
}
