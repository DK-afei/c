#include <stdio.h>
#define M 14
	void main()
	{
		char a[M];
		int i;
		for(i=0;i<M;i++)
		{
			scanf("%c",&a[i]);
		}
		for(i=0;i<M;i++)
		{
			if(a[i]==',')
				printf("\n");
			else if ((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z'))
				printf("%c",a[i]);
			else
				printf("ÇëÖØÐÂÊäÈë£¡");
		}
				printf("\n");
	}

