#include <stdio.h>
struct MonthDays
{
	char name[10];
	int days;
}cover[12]={{"January",31},{"February",29},{"March",31},{"April",30},{"May",31},{"June",30},{"July",31},{"August",31},{"September",30},{"October",31},{"November",30},{"December",31}};
void main()
{
 int i;
 int n;
 scanf("%d",&n);
 fflush(stdin);
 for(i=0;i<12;i++)
 {
	 if(n==i+1)
	 {
		 printf("%s has %d days\n",cover[i].name,cover[i].days);
	 }
 }
}