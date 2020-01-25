#include <stdio.h>
#define N 1
struct stu
{
	char num[64];
	float score;
	float grade;
	float ave;
}students[N];
void main()
{
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%s",students[i].num);
		scanf("%f",&students[i].score);
		scanf("%f",&students[i].grade);
		scanf("%f",&students[i].ave);
	}
	for(i=0;i<N;i++)
	{
		printf("%s\t",students[i].num);
		printf("%.2f\t",students[i].score);
		printf("%.2f\t",students[i].grade);
		printf("%.2f\n",students[i].ave);
	}

}