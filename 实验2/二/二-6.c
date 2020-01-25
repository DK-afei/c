#include  <stdio.h>
void main()
{
	float a=2,b=3,x=3.5f,y=2.5f,X,Y,Z;
	X=(float)((a+b)/2+(int)x%(int)y);
	printf("X=%f,",X);
	Y=(float)(a+b/2+(int)x%(int)y);
	printf("Y=%f",Y);
	Z=(float)((a+b/2)+(int)x%(int)y);
	printf("Z=%f",Z);
}
