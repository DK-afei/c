#include <stdio.h>
#define N 1024
void main()
{
	char a[N];
	int i,n;
	int upper=0,lower=0;

	printf("请输入要输入的字符的数目：");
	scanf("%d",&n);
	printf("请输入字符串：");

	for(i=0;i<n+1;i++)
		scanf("%c",&a[i]);

	for(i=0;i<n+1;i++)
	{
		if(a[i]>=65&&a[i]<97)
			upper++;
		else if(a[i]>=97&&a[i]<123)
			lower++;
	}
	
		printf("upper=%d,lower=%d",upper,lower);
		printf("\n");

}