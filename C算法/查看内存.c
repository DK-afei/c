#include <stdio.h>
#include <stdlib.h>
void main()
{
	int t=0;
	void*p;
	while(p=(malloc(1*1024*1024)))
	{
		t++;
	}
	printf("%dM\n",t);
	free(p);
}