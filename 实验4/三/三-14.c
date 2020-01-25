#include <stdio.h>
 void main()
 {
	 int x,i,j;	
	 scanf("%d",&x);
		for(i=2;i<=x;i++)
	{
		for(j=2;j<=i-1;j++)
		{
			if(i%j==0)
				break;
		}
		if(j>=i)
		printf("%d\n",i);
	}

 }
 
