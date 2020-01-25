#include <stdio.h>
 void main()
 {
	float a,b,c,d,e,f,g,h,i,j,sum,mul,x,y;
		scanf("%f%f%f%f%f%f%f%f%f%f",&a,&b,&c,&d,&e,&f,&g,&h,&i,&j);
		sum=a+b+c+d+e+f+g+h+i+j;
		mul=a*b*c*d*e*f*g*h*i*j;
		x=a*a+b*b+c*c+d*d+e*e+f*f+g*g+h*h+i*i+j*j;
		y=(a+b+c+d+e+f+g+h+i+j)*(a+b+c+d+e+f+g+h+i+j);
		printf("sum=%f,mul=%f,x=%f,y=%f\n",sum,mul,x,y);
 }
