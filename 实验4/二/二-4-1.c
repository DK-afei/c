#include <stdio.h>
#include <math.h>
#define A 1e-5
	void main()
	{
		float x,y,sum;
		int n=1;
		scanf("%f:",&x);
		y=x;
		sum=x;
	do
	{
		n+=2;
		y*=(-x*x)/(n-1)/n;
		sum+=y;
	}while(fabs(y)>A);
		printf("sin(x)=%.5f",sum);
	}

