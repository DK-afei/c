#include <stdio.h>
#define N 1 
struct birthday
{
	int year;
	int month;
	int day;
};
struct stu
{
	char name[10];
	struct birthday date;
	float score;
	float grade;
	float ave;
}students[N];
void main()
{
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%s",students[i].name);
		scanf("%d%d%d",&students[i].date.year,&students[i].date.month,&students[i].date.day);
		scanf("%f",&students[i].score);
		scanf("%f",&students[i].grade);
		scanf("%f",&students[i].ave);
	}
	for(i=0;i<N;i++)
	{
		printf("%s\t",students[i].name);
		printf("%d.%d.%d\t",students[i].date.year,students[i].date.month,students[i].date.day);
		printf("%.2f\t",students[i].score);
		printf("%.2f\t",students[i].grade);
		printf("%.2f\n",students[i].ave);
	}

}