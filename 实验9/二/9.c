#include <stdio.h>
void swap(int*data,int len)
{
	int i;
	int max,min;
	max=min=*data;
	for(i=0;i<len;i++)
	{
		if(*(data+i)>max)
			max=*(data+i);
			if(*(data+i)<min)
			min=*(data+i);
	}
	*data=min;
	*(data+len-1)=max;
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
	swap(a,n);
    for(i=0;i<n;i++)
	{
		printf("	%d",a[i]);
	}
	printf("\n");
}