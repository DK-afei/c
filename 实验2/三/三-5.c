#include <stdio.h>
void main()
{
	int v0=10,a=2,t=20,vt,s,v;
	vt=v0+a*t;
	s=v0*t+a*t*t/2;
	v=(v0+vt)/2;
	printf("vt=%d,s=%d,v=%d\n",vt,s,v);
}
