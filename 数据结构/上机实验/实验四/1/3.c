#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define m 22
int index(char s1[], char s2[])
{
	unsigned int i,j;
	int flag;
	if(strlen(s2)>strlen(s1))
		return -1;
	for(i=0;i<strlen(s2);i++)
		for(j=0;j<strlen(s1);j++)
		{
			if(s2[i]==s1[j])
			{
				i++;
				flag=j;
				if(i==(strlen(s2)+1))
					break;
			}
		}
		i=i-1;
	if(i==strlen(s2))
		return flag-i+1;
	else
		return -1;
	
}
int main()
{
	char s1[m], s2[m];
	gets(s1);
	gets(s2);
	printf("%d\n",index(s1,s2));
	return 0;
}