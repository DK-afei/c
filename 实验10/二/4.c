#include <stdio.h>
#define N 3
	struct dates
	{
		int year;
		int month;
		int day;
	}date[N];
	void main()
	{
		int i;
		printf("please input date:\n");
		for(i=0;i<N;i++)
		{
				scanf("%d",&date[i].year);
		scanf("%d",&date[i].month);
		scanf("%d",&date[i].day);
		}
		for(i=0;i<N;i++)
		{
			printf("%d\t",date[i].year);
		printf("%d\t",date[i].month);
		printf("%d\t",date[i].day);
		printf("\n");
		}
	}