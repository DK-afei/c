#include <stdio.h>
	void main()
	{
		int a,b,c,d=100; 
		
		for (;d<=999;d++)	
	{
			a=d/100;
			b=(d%100)/10;
			c=d%10;
			if(a==((a*a*a+b*b*b+c*c*c-b*10-c)/100)&&b==((a*a*a+b*b*b+c*c*c-a*100-c)/10)&&c==((a*a*a+b*b*b+c*c*c-a*100-b*10)))
		printf("%d\n",d);
	}	
		
	}