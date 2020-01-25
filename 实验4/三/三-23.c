#include <stdio.h>
void main()
{
	int a;
	int i,j;
	char ch;
		printf ("请输入一个数字：");
		scanf("%d",&a);
		for(i=0;i<a;i++)
		{
					for(j=0;j<a-i;j++)
					{
						printf(" ");
					}	
						for(j=0;j<i+1;j++)
					{
						ch='*'+j;
						printf("*");
					}	
						for(j=0;j<i;j++)
					{
							printf("*",ch-j-1);
					}
			printf("\n");			
		}
			for(i=a-2;i>-1;i--)
		{
					for(j=0;j<a-i;j++)
					{
						printf(" ");
					}	
						for(j=0;j<i+1;j++)
					{
						ch='*'+j;
						printf("*");
					}	
						for(j=0;j<i;j++)
					{
							printf("*",ch-j-1);
					}
				printf("\n");			
		}
	

}
		