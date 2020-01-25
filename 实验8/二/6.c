#include "stdio.h"
void fun(int*x,int*y)
{
	printf("%d%d",*x,*y);
	*x=3;
	*y=4;
}
void main()
{
	int x=1,y=2;
	fun(&y,&x);
	printf("%d%d",x,y);
}