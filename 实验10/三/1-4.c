#include <stdio.h>
#define N 1
struct birthday
{
	int year;
	int month;
	int day;
};
struct share
{
	char name[10];
	float p;
	struct birthday date;
}shares[N];
void main()
{
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%s",shares[i].name);
		scanf("%f",&shares[i].p);
		scanf("%d%d%d",&shares[i].date.year,&shares[i].date.month,&shares[i].date.day);
	}
	for(i=0;i<N;i++)
	{
		printf("%s\t",shares[i].name);
		printf("%.2f\t",shares[i].p);
		printf("%d.%d.%d\n",shares[i].date.year,shares[i].date.month,shares[i].date.day);
	}
}
