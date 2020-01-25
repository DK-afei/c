#include <stdio.h>
#include <stdlib.h>
void MatrixSearch(double **a, double*pMax, double*pMin,int n)
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
   int i,j;
   double max,min;
   int n;   
   double **a=(double**)malloc(100*sizeof(double*));
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
	   *(a+i)=malloc(100*sizeof(double));
       for(j=0;j<n;j++)
       {
           scanf("%lf",*(a+i)+j);
       }
   }
   MatrixSearch(a,&max,&min,n);
   printf("max=%.2lf,min=%.2lf \n",max,min);
    for(i=0;i<n;i++)
    {
      free(*(a+i));
	}
	free(a);
   return 0;
}
