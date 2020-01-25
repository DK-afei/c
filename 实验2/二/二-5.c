#include  <stdio.h>
void main()
{
	int a=12,n=5;
	a+=a;
	printf("a=%d\n",a);
	a=12;
	a-=a;
	printf("a=%d\n",a);
	a=12;
	a*=2+3;
	printf("a=%d\n",a);
	a=12;
	n=5;
	a%=(n%=2);
	printf("a=%d\n",a);
	a=12;
	a+=a-=a*=a;
	printf("a=%d\n",a);
}
