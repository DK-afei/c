#include <stdio.h>
void reverse(int*data,int len)
{
	int i;
	int b[100];
	for(i=0;i<len;i++)
	{
		b[len-1-i]=*(data+i);
	}
	for(i=0;i<len;i++)
	{
		*(data+i)=b[i];
	}
}
void main()
{
	int a[100];
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	reverse(a,n);
    for(i=0;i<n;i++)
	{
		printf("	%d",a[i]);
	}
	printf("\n");
}