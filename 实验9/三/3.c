#include <stdio.h>
#include <string.h>
void mstrcpy(char*stc,char*does,int m)
{
    int i;
    int j=0;
    for(i=m-1;i<strlen(stc)+1;i++)
    {
        *(does+j)=*(stc+i);
        j++;
    }
}
int main()
{
    char a[100];
    char b[100];
    int n;
    printf("请输入从第几个复制:\n");
    scanf("%d",&n);
    printf("请输入源字符串:");
    gets(a);
    mstrcpy(a,b,n);
    puts(b);
    return 0;
}
