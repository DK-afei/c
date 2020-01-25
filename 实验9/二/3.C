#include <stdio.h>
int del(int*data,int n,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		if(*(data+i)==n)
			return len-1;
		
	}
	return len;
}
void main()
{
	int a[100];
	int n,i,b;
	scanf("%d%d",&n,&b);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("	%d",del(a,b,n));
	printf("\n");
}