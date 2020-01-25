#include <stdio.h>

	void main()
	{
		int a,b,x,n;
		printf("0	1	");
		for(a=0,b=1,n=3;n<=100;n++)
		{
			if(n%2!=0)
			{	
			x=a+b;
			a=b;
			b=x;
				printf("%d	",x);
			}
			 else
			 {
			x=a-b;
			a=b;
			b=x;
				printf("%d	",x);
			 }
		}
	
			
			printf("\n");
		
	}

