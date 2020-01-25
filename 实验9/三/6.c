#include <stdio.h>
void dresort(int*data,int len)
{
	int i,j=0;
	int b[100];
	for(i=0;i<len;i++)
	{
		if((i+1)%2!=0)
		{
			b[j]=*(data+i);
			j++;
		}	
	}
	for(i=0;i<len;i++)
	{
		if((i+1)%2==0)
		{
		b[j]=*(data+i);
		j++;
		}
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
	dresort(a,n);
    for(i=0;i<n;i++)
	{
		printf("	%d",a[i]);
	}
	printf("\n");
}