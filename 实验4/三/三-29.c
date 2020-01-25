#include <stdio.h>

	void main()
	{
		int a,b,c,d,e;
		scanf("%d",&a);//请输入一个在10-9999的整数且凑够4位
		{
			b=a%10;
			c=(a%100)/10;
			d=(a%1000)/100;
			e=(a%10000)/1000;
			printf("a:%d change to:%d%d%d%d\n",a,b,c,d,e);
		}
		printf("\n");	
	}

