#include <stdio.h>
struct time
{
	int h;
	int m;
};
void main()
{
	struct time t;
	scanf("%d ",&t.h);
	scanf("0%d",&t.m);
	if((t.m)+1<60)
	{
	printf("%d ",t.h);
	printf("%d\n",(t.m)+1);
	}
	else 
	printf("%d ",(t.h)+1);
	printf("00\n");
}