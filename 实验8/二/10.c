#include <stdio.h>
#define N 3
void MatrixSearch(double a[N][N], double*pMax, double*pMin,int n)
{
    int i,j;
    *pMax=*pMin=*(*(a+0)+0);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(*(*(a+i)+j)>*pMax)
            *pMax=*(*(a+i)+j);
            if(*(*(a+i)+j)<*pMin)
            *pMin=*(*(a+i)+j);
        }
    }
}
int main()
{
   double a[N][N];
   int i,j;
   double max,min;
   for(i=0;i<N;i++)
   {
       for(j=0;j<N;j++)
       {
           scanf("%lf",&a[i][j]);
       }
   }
   MatrixSearch(a,&max,&min,N);
   printf("max=%.2lf,min=%.2lf \n",max,min);
   
   return 0;
}
