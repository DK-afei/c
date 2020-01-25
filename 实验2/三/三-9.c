#include <stdio.h>
#include <math.h>
void main()
{

	float R,i1,i2,i3,i4;	
	int U,R1,R2,R3,R4;
			U=220;
			R1=10000;
			R2=10000;
			R3=200000;
			R4=200000;
		R=(float)(1.0/(1.0/R1+1.0/R2+1.0/R3+1.0/R4));
		i1=(float)U/R1;
		i2=(float)U/R2;
		i3=(float)U/R3;
		i4=(float)U/R4;
		printf("R=%.3f,i1=%.3f,i2=%.3f,i3=%.3f,i4=%.3f\n",R,i1,i2,i3,i4);
}
