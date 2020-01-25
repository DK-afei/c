
#include<stdio.h>
 void main()
 {
	 int n,d1,d2,d3,d4;
	 scanf("%d",&n);
	 d1=n%10;
	 d2=(n%100)/10;
	 d3=(n%1000)/100;
	 d4=(n%10000)/1000;
	 printf("n:%d change to:%d%d%d%d\n",n,d1,d2,d3,d4);
 }