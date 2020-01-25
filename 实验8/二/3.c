#include <stdio.h>
#include <math.h>

double distance(int x1,int y1,int x2,int y2)
{
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
   int a,b,c,d;
   printf("d=%.2lf \n",distance(a,b,c,d));
   
   return 0;
}
