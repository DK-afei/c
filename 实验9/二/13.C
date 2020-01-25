#include <stdio.h>
#include  <string.h>
int strtinglen(char *string)
{
		int i;
		int j=0;
		for(i=0;*(string+i)!='\0';i++)
		j++;
		return j;
}
void main()
{
	char a[1024];
	gets(a);
	fflush(stdin);	
	printf("%d\n",strtinglen(a));

}
