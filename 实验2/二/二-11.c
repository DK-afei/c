#include <stdio.h>
void main()
{
	float x=1.2f,y=2.1f;
	x=y;
	y=x;
	printf("x=%f\ny=%f\n",x,y);
}