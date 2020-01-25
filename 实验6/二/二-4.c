#include <stdio.h>
#define N 1024
void main()
{
	char a[N];
	char t;
	int i,n;

	printf("请输入要输入的字符的数目：");
	scanf("%d",&n);
	printf("请输入字符串：");

	for(i=0;i<n;i++)
		scanf("%c",&a[i]);
	
	for(i=0;i<n+1;i++)
	{
		if(a[i]<=a[i+1])
		{
			t=a[i];
			a[i]=a[i+1];
			a[i+1]=t;
		}	
	
	}
	for(i=0;i<n+1;i++)
	{
		printf("%c",a[i]);
		printf("\n");
	}
		printf("\n");
}