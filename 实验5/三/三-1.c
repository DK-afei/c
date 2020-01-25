#include <stdio.h>
#define n 15
void main()
{
	int i,j;
	int a[n],t;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(i=0;i<n;i++)
	{

		for(j=n-i-1;j<n-1;j++)
			if(a[j]<a[j+1])
			{   
				 t=a[j];
				 a[j]=a[j+1];
				 a[j+1]=t;
			}

	}
	for(i=0;i<n;i++)
	printf("%d ",a[i]);
	printf("\n");
} 
		
				
				

