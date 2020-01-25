#include <stdio.h>
void main()
{
	int a , b, c, d, sum;
	a=10; b=20; c=30;
	sum=a+b*c;
	a=c; d=a+c;
	printf("sum=%d, d=%d", sum,d);
}