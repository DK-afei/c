#include <stdio.h>
#include <conio.h>
void main()
{
	char a[6],b[6]={'1','2','1','1','2','1'};
	int i,j,k;
	printf("please input the key:\n");
	for(k=0;k<3;k++)
	{
	for(i=0;i<6;i++)
	{
		a[i]=getch();
		printf("*");
	}
		for(i=0,j=0;i<6;i++)
	{
		if(a[i]==b[i])
		j++;
	}
		if(j==6)
		{
		printf("\nWelcome!\n");
		break;
		}
		else
			printf("\nplease input again!\n");
	}
}
