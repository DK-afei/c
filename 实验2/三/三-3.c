
#include  <stdio.h>
void main()
{
	int sum ;
	char ch1,ch2,ch3;
	scanf("%c%c%c",&ch1,&ch2,&ch3);
	sum=(ch1-'0')*100+(ch2-'0')*10+(ch3-'0');
	printf("sum=%d\n",sum);
}