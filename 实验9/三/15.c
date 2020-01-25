#include <stdio.h>
void zprocess(int*data,int len)
{
	int i,j=0;
	int b[100];
	for(i=0;i<len;i++)
	{
		if(*(data+i)!=0)
		{
			b[j]=*(data+i);
			j++;
		}	
	}
	for(i=j;i<len;i++)
	{
		b[i]=0;
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
	zprocess(a,n);
    for(i=0;i<n;i++)
	{
		printf("	%d",a[i]);
	}
	printf("\n");
}