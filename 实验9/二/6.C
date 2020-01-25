#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5
int searchch_1(char*string,char ch)
{
    int i;
    for(i=0;i<N;i++)
    {
        if(*(string+i)==ch)
			return i;
    }
	return -1;
}

int main()
{
   char a[1024];
   int i,d;
   char ch;
   for(i=0;i<N;i++)
   scanf("%c",&a[i]);
   fflush(stdin);
   printf("请输入要查找的字符:");
   scanf("%c",&ch);
   d=searchch_1(a,ch);
   printf("%d\n",d); 
   return 0;
}
