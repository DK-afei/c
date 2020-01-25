#include <stdio.h>
#define N 20
void sum(int *a, int n, int *odd, int *even)
{
	int i;
	*odd=*even=0;
	for(i=0;i<n;i++)
	{
		if(a[i]%2==0)
			*even+=a[i];
		else
			*odd+=a[i];
	}
}
int main()
{
	int i;
	int a[N];
	int n;
	int odd,even;
	printf("please input the number:\n");
	scanf("%d",&n);
	printf("please input the a[]:\n");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sum(a,n,&odd,&even);
	printf("the sum of odds:%d, the sum of evens:%d\n",odd,even);
}