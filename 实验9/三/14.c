#include <stdio.h>
int fact(int x,int*f)
{
    int i,t=0;
    int j=0;
    for(i=2;i<x;i=i+2)
    {
        if(x%i==0)
        {
        *(f+j)=i;
        j++;
        t++;
        }
    }
    printf("ż�����ӷֱ�Ϊ:");
    for(i=0;i<t;i++)
    printf(" %d",*(f+i));
    return t;
}
int main()
{
    int a;
    int b[5];
    int c;
    scanf("%d",&a);
    c=fact(a,b);
    printf("\nż��������Ϊ:%d",c);
    return 0;
}
