#include <stdio.h>
#include <string.h>
void strcpy_(char*to,char*from)
{
	while((*to++)=(*from++)) ; 
}

int main()
{
    char a[1024],b[1024];
    gets(b);
    strcpy_(a,b);
    puts(a);
    return 0;
}
