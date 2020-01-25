#include <stdio.h>
#include <string.h>
int searchno(char (*stuno)[12],char*no,int n)
{

		int j;
		for(j=0;j<n;j++)
		{
			if(strcmp(*(stuno+j),no)==0)
			{
			return j;
			}
		}
		return -1;
}	
int main()
{
	char a[100][12];
	char b[12];
	int n,i;
	scanf("%d",&n);
	fflush(stdin);
	for(i=0;i<n;i++)
		gets(*(a+i));
	gets(b);

	printf("%d\n"	,searchno(a,b,n));
	return 0;
}
