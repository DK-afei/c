#include <stdio.h>
	void main()
	{
		int a,i,max;
		printf("输入十个整数\n");
		scanf("%d:",&a);
			max=a;
			for (i=0;i<9;i++)
			
		{
			scanf("%d:",&a);
			if(max<a)
				max=a;
		}	
				printf("max=%d\n",max);
	}