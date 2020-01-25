#include<stdio.h>
void main ()
{
	int y;
	float a,r;
	for(r=0.1,a=4672,y=2013;y<2018;y++)
		a*=(1+r);
		printf("%f\n",a);
}

