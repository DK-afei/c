#include <stdio.h>
 void main()
 {
	 float e,i,s;	   
		for(s=1,i=1;e<1e-6;i++)	
		{
			e=1/(s*=i);
			e+=(1/(s*=i));
			printf("e=%.6f\n",e);
		}
 }
