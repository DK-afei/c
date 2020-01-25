/*#include <stdio.h>

	void main()
	{
		int a,i,mul;
			for(a=1,i=1;i<10;i++)
			{
				mul=a*i;
				printf("%d*%d=%d	",a,i,mul);
			}
	printf("\n");
			for(a=2,i=2;i<10;i++)
			{
				mul=a*i;
		     	printf("%d*%d=%d	",a,i,mul);
			}
	printf("\n");
			for(a=3,i=3;i<10;i++)
			{
				mul=a*i;
				printf("%d*%d=%d	",a,i,mul);
			}
	printf("\n");
			for(a=4,i=4;i<10;i++)
			{
				mul=a*i;
				printf("%d*%d=%d	",a,i,mul);
			}
	printf("\n");
			for(a=5,i=5;i<10;i++)
			{
				mul=a*i;
				printf("%d*%d=%d	",a,i,mul);
			}
	printf("\n");
			for(a=6,i=6;i<10;i++)
			{
				mul=a*i;
				printf("%d*%d=%d	",a,i,mul);
			}
	printf("\n");
			for(a=7,i=7;i<10;i++)
			{
				mul=a*i;
				printf("%d*%d=%d	",a,i,mul);
			}
	printf("\n");
			for(a=8,i=8;i<10;i++)
			{
				mul=a*i;
				printf("%d*%d=%d	",a,i,mul);
			}
	printf("\n");
			for(a=9,i=9;i<10;i++)
			{
				mul=a*i;
				printf("%d*%d=%d	",a,i,mul);
			}
	printf("\n");
	}*/
#include <stdio.h>
	void main()
	{
		int i,j;
		for(i=1;i<=9;i++)
		{
			for(j=1;j<=i;j++)
			{
				printf("%d*%d=%d\t",j,i,i*j);
			}
			printf("\n");
		}
		printf("\n");
	}


