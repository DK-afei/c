#include<stdio.h>
void exchange(int*n1,int*n2)
{
    int*t=*n1;
    *n1=*n2;
    *n2=t;
}
 int main()
 { 
	 int n1,n2;
     scanf("%d%d",&n1,&n2);
     exchange(&n1,&n2);
     printf("n1=%d n2=%d",n1,n2);
     return 0;
 }