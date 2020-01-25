#include <stdio.h>
#include <math.h>
void main()
{
	int a,b,c;
	float s;
		a=5;
		b=10;
		c=6;
		s=(float)(a+b+c)/2;
	s=(float)sqrt(s*(s-a)*(s-b)*(s-c));
	printf("s=%f\n",s);
}
