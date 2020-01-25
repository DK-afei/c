#include <stdio.h>
 void main()
 {
	 int i,j;	
		for(i=1;i<100;i+=2)
	{
		j=(i*i)%8;
		if(j==1)
		printf("yes\n");
		else
		printf("no\n");
		break;
	}

 }
