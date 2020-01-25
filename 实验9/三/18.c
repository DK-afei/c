#include <stdio.h>
#include <string.h>
void stringvert(char*str)
{
    int i;
    char b[1024];
    for(i=0;i<strlen(str);i++)
    b[i]=*(str+strlen(str)-1-i);
    for(i=0;i<strlen(str);i++)
    *(str+i)=b[i];
}

int main()
{
    char a[1024];
    gets(a);
    stringvert(a);
    puts(a);
    return 0;
}
