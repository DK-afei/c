#include <stdio.h>
#define n 5

	void main()
	{
		int a,i;
		int count=1;
		
		for(i=0;i<n;i++)

		{
			scanf("%d",&a);
			if((a=getchar())!='0')
				break;
		}
		if(a%2==0)
		{
			count++;
		printf("Å¼Êý=%d\n",count);
		}	
	}

