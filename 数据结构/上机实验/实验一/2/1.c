#include <stdio.h>
int fun(int *a, int *b)
{
	if(((*a)*(*b))>0)
		return 1;
	else
		return 0;
}
int main()
{
	int a,b;
	printf("please input a and b:(a!=0,b!=0)\n");
	scanf("%d%d",&a,&b);
	if(fun(&a,&b))
		printf("a b符号相同\n");
	else
		printf("a b符号不同\n");
	return 0;
}