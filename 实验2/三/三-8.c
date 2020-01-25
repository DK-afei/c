#include <stdio.h>
#include <math.h>
void main()
{

	float r,h,l,s,v;
		r=1.5;
		h=3;
		l=(float)3.14*2*r*2;
		s=(float)(3.14*r*r*2+2*3.14*r*l);
		v=(float)3.14*r*r*h;
		printf("l=%f\n,s=%f\n,v=%f/n",l,s,v);
}
