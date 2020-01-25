#include <stdio.h>
#include <string.h>
void sortno(char (*stuno)[12],int n)
{
	int i,j;
	char str[12];
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
		{
			if(strcmp(*(stuno+j),*(stuno+j+1))>0)
			{
				strcpy(str,*(stuno+j));
				strcpy(*(stuno+j),*(stuno+j+1));
				strcpy(*(stuno+j+1),str);
			}
		}
}	
int main()
{
	char a[100][12];
	int n,i;
	scanf("%d",&n);
	fflush(stdin);
	for(i=0;i<n;i++)
		gets(*(a+i));
	sortno(a,n);
	for(i=0;i<n;i++)
		puts(*(a+i));
	return 0;
}
