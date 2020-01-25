#include <stdio.h>
#include <math.h>
void main()
{
	int a,b,c;
	float d,v1,v2;
	scanf("%d %d %d",&a,&b,&c);
	d=(float)b*b-4*a*c;
	v1=(float)(-1*b+sqrt(d))/2/a;
	v2=(float)(-1*b-sqrt(d))/2/a;
	printf("v1=%f",v1);
	printf("v2=%f",v2);
}
