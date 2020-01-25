#include <stdio.h>
void strsta(char*string,int*num)
{
    int i,a=0,b=0,c=0,d=0;
    for(i=0;*(string+i)!='\0';i++)
    {
        if(*(string+i)>='a'&&*(string+i)<='z'||*(string+i)>='A'&&*(string+i)<='Z')
        a++;
        else if(*(string+i)>='0'&&*(string+i)<='9')
        b++;
        else if(*(string+i)==' ')
        c++;
        else
        d++;
    }
    *num=a;*(num+1)=b;*(num+2)=c;*(num+3)=d;
    
}
int main()
{
   char a[1024];
   int b[4];
   int i;
   gets(a);
   strsta(a,b);
   for(i=0;i<4;i++)
   printf("%d\n",b[i]);
   return 0;
}
