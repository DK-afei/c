#include <stdio.h>
#include <math.h>
void main()
{
	int i,j,flag;
	int count=0;;
	for(i=2;i<101;i++)
	{	
		
		for(j=2;j<i;j++)
		{
			flag=1;			
			if(i%j==0)
			{
			flag=0;	
			break;
			}					
		}


			if(flag)
			{	
			printf("%d	",i);
			count++;	
			if(count%5==0)	
			printf("\n");
			}
	}

			
		
}