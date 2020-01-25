#include "stdio.h"
int findmax(int n1,int n2,int n3)
{
	int max;
	max=(n1>n2)?(max=n1):(max=n2);
	max=(n3>max)?(max=n3):(max=(n1>n2)?(max=n1):(max=n2));
	return max;
}
void main()
{
	int a,b,c,max;
	scanf("%d%d%d",&a,&b,&c);
	max= findmax (a,b,c);
		printf("max=%d\n",max);
}