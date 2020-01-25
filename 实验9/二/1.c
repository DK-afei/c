#include <stdio.h>
void maxmin(int*data,int*max,int*min,int len)
{
	int i;
	*max=*min=*data;
	for(i=0;i<len;i++)
	{
		if(*(data+i)>*max)
			*max=*(data+i);
			if(*(data+i)<*min)
			*min=*(data+i);
	}
}
void main()
{
	int a[100];
	int n,i,b,c;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	maxmin(a,&b,&c,n); 
		printf("max=%d,min=%d",b,c);
	printf("\n");
}