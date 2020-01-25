#include <stdio.h>
struct Date
{
	int year;
	int month;
	int day;
}dates[2];
struct Date large(struct Date d1,struct Date d2)
{
  if(d1.year==d2.year&&d1.year==d2.year&&d1.month>d2.month&&d1.year==d2.year&&d1.month==d2.month&&d1.day>d2.day&&d1.year==d2.year&&d1.month==d2.month&&d1.day==d2.day)
	   return d1;
else 
		return d2;
}
void main()
{
	int i;
	struct Date d1,d2,d3;
	for(i=0;i<2;i++)
	{
		scanf("%d",&dates[i].year);
		scanf("%d",&dates[i].month);
		scanf("%d",&dates[i].day);
	}
d1=dates[0];
d2=dates[1];
d3=large(d1,d2);
 printf("%d,%d,%d",d3.year,d3.month,d3.day);
printf("\n");
}