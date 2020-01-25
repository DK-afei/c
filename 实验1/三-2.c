#include <stdio.h>
void main()
{
	int i2;
	int i1=1000;
	{
		int i1=100;
		printf("i1=%d",i1);
	}
	i2=i1;
	printf("i2=%d\n",i2);
}