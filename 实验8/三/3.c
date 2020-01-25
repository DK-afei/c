#include "stdio.h"
#define pi 3.141
double cvolume(double r, double h)
{
	double v=0;
	v=pi*r*r*h;
	return v;
}
void main()
{
	double a=0,b=0,v=0;
	scanf("%lflf",&a,&b);
	v= cvolume (a,b);
		printf("v=%.3lf\n",v);
}