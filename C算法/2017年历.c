#include<stdio.h>
int main()
{
	int a[12],sum=0,s=0,m=0,i,j,day;
	for(i=0;i<12;i++)
	a[i]=i+1;
	printf("2017日历");
	for(i=0;i<12;i++)
	{
		printf("\n \n");
		if(a[i]%2!=0&&a[i]!=9&&a[i]!=11||a[i]==8||a[i]==10||a[i]==12)
		{
			day=31;
			printf("%d月\n",a[i]);
			for(j=1;j<=day;j++)
			{
				printf("%5d",j);
				sum++;
				if(sum%7==0)
				printf("\n");
			}
		}
		else if(a[i]==2)
		{
			day=28;
			printf("%d月\n",a[i]);
			for(j=1;j<=day;j++)
			{
				printf("%5d",j);
				s++;
				if(s%7==0)
				printf("\n");
			}
		}	
		else if(a[i]==4||a[i]==6||a[i]==9||a[i]==11)
		{
			day=30;
			printf("%d月\n",a[i]);
			for(j=1;j<=day;j++)
			{
				printf("%5d",j);
				m++;
				if(m%7==0)
				printf("\n");
			}
		}
	}
}