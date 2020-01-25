#include <stdio.h>
#include <string.h>
int scmp(char*p1,char*p2)
{
    int i;
	int j=0;
    for(i=0;;i++)
	{
		if(*(p1+i)!=*(p2+i))
		{	
			return (*(p1+i)-*(p2+i));
		}
	}
	return 0;
}

int main()
{
    char a[1024],b[1024];
    gets(a);
	gets(b);
	printf("%d",scmp(a,b));
	printf("\n");
    return 0;
}
