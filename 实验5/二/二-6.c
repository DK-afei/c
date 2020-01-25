#include <stdio.h>
#define N 20
void main()
{
	int i,all=0;
	int a[N];
	float ave;
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
			all+=a[i];
	}
	
		ave=(float)(all/N);
		printf("ave=%.2f\n",ave);
}
		