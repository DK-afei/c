#include <stdio.h>
#include <string.h>
void sorts(char (*string)[1024],int n)
{
	int i,j;
	char str[1024];
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
		{
			if(strcmp(*(string+j),*(string+j+1))<0)
			{
				strcpy(str,*(string+j));
				strcpy(*(string+j),*(string+j+1));
				strcpy(*(string+j+1),str);
			}
		}
}	
int main()
{
	char a[100][1024];
	int n,i;
	scanf("%d",&n);
	fflush(stdin);
	for(i=0;i<n;i++)
		gets(*(a+i));
	sorts(a,n);
	for(i=0;i<n;i++)
		puts(*(a+i));
	return 0;
}
