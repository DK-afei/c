#include <stdio.h>
int search(int*data,int n,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		if(*(data+i)==n)
			return i;
		
	}
	return -1;
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
	printf("	%d",search(a,b,n));
	printf("\n");
}