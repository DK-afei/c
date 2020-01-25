#include <stdio.h>
#include <math.h>
void main()
{
	float x;
	float sinx=0;
	float fenzi;
	float item;
	int fenmu=1;
	int i,j;
	scanf("%f",&x);
	for(i=1;;i++)
	{
		fenzi=(float)pow(x,2*i-1);
		fenmu=1;
		for(j=1;j<=2*i-1;j++)
			fenmu*=j;
		item=fenzi/fenmu;
		if (item<1e-6)
			break;
		sinx+=(float)pow(-1,i+1)*item;
	}
	printf("sin(%.2f)=%.3f\n",x,sinx);
}

