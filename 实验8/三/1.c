#include <stdio.h>
	int m(unsigned k)
	{
		int s=1;
	do
	{
		s*=k%10;
		k/=10;
	}while(k);
	return s;
	}

void main()
{
	printf("%d,%d\n",m(1234),m(43209));
}