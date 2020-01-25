#include<stdio.h>
void main ()
{
	int y;
	for(y=100;y<301;y++)
	{
		if((y%10+(y%100)/10+y/100)%5==0)
		printf("%d\n",y);
	}

}