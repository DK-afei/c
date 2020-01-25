#include <stdio.h>
#define M 14
	void main()
	{
		char a[M];
		int i;
		for(i=0;i<(M/2-1);i++)
		{
			scanf("%c",&a[i]);
		}
	
			if((a[i]==a[M/2-i-1])||(a[i]==(32+a[M/2-i-1]))||((a[i]+32)==a[M/2-i-1]))
				printf("回文数");
	
			else
				printf("请重新输入！");
	
				printf("\n");
	}

