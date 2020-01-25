#include <stdio.h>
#define N 20
 void main()
 {
	 int a[N];
	int i,j;
	int max;
	 for(i=0;i<N;i++)
	 scanf("%d",&a[i]);
	 max=a[0];
	 for(i=0;i<N;i++)
	 {
		 if(a[i]>max)
			 max=a[i];
	 }
		for(i=0;i<N;i++)
	{
		for(j=2;j<max;j++)
		{
			if(a[i]%j==0)
				break;
		}
		if(j>=i)
		printf("%d\n",a[i]);
	}

 }
 
