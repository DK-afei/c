#include <stdio.h>
#include <string.h>
void stringcat(char*str1,char*str2)
{
    int i;
    for(i=0;i<strlen(str2)+1;i++)
    *(str1+strlen(str1))=*(str2+i);
}

int main()
{
    char a[1024],b[1024];
    gets(a);
    gets(b);
    stringcat(a,b);
    puts(a);
    return 0;
}
