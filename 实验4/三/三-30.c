#include <stdio.h>

	void main()
	{
		int a,b,c,x,n;
			a=0;
			b=0;
			c=1;
			n=4;
				printf("%d %d %d",a,b,c);
			while(n<=10)
			{
				x=a+b+c;
				a=b;
				b=c;
				c=x;
				printf(" %d ",x);
				n++;
			}
			printf("\n");
		
	}

