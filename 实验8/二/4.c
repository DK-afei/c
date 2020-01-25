#include <stdio.h>
 double tempt(double temp,char ctype) 
{
	double x;
	switch(ctype) 
	{
		case 'C':
		       x=(9/5)*temp+32;
		break;
		case 'F':
		       x=(5/9)*(temp-32);
		break;
		default:
		       printf("请输入正确类型!");
		break;
	}
	return x;
}
int main() 
{
	double t;
    char c;
	scanf("%lf %c",&t,&c);
	printf("%.5lf\n",tempt(t,c));
	return 0;
}
