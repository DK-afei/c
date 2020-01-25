#include <stdio.h>
int steps;
void print(int a,int b)
{
    printf("%d->%d\n",a,b);
    steps++;
}

void move(int n,int a,int b, int c)
{
    if(n==1)
    print(a,c);
    else
    {
    move(n-1,a,c,b);
    print(a,c);
    move(n-1,b,a,c);
    }
}
int main()
{
   int n;
   scanf("%d",&n);
   move(n,1,2,3);
   printf("steps=%d \n",steps);
   
   return 0;
}
