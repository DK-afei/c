#include <stdio.h>
	void main()
	{
		int a, k;
		scanf("%d:",&a);
		if (a>0)
		{
			printf("%d:",a);
			for (a,k=1;;k++)
			if (a%k==0)
			printf("%d ",k);
		}
		printf("\n");
	}