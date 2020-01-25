#include <stdio.h>
#include <string.h>
void strsort(char*s[],int n)
{
	int i,j,k;
	char*temp=NULL;
	for(i=0;i<n-1;i++)
	{
		k=i;
		for(j=i+1;j<n;j++)
			if(strcmp(s[j],s[k])<0)
				k=j;
			if(k!=i)
			{
				temp=s[i];
				s[i]=s[k];
				s[k]=temp;
			}
	}
}
void main()
{
	char *s[10],**p=NULL;
	int i;
	for(i=0;i<10;i++)
	{
		gets(s[i]);
	}
	strsort(s,10);
	p=s;
	for(i=0;i<10;i++)
		printf("%s\n",*p++);
}