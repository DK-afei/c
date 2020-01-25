#include <stdio.h>
#define N 1024
void main()
{
	char str1[N]={0},str2[N];
	int i,n;

	printf("请输入要输入的str2字符的数目：");
	scanf("%d",&n);
	printf("请输入字符串：");

	for(i=0;i<n+1;i++);
		scanf("%c",&str2[i]);

	for(i=0;((str1[i])=(str2[i]))!='\0';i++);

		printf("\n");

}