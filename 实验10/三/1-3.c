#include <stdio.h>
#define N 1 
struct address
{
	char street[10];
	char city[10];
	char country[10];
	int pc;
};
struct person
{
	char name[10];
	struct address p;
}persons[N];
void main()
{
	int i;
	for(i=0;i<N;i++)
	{
		scanf("%s",persons[i].name);
		scanf("%s",persons[i].p.street);
		scanf("%s",persons[i].p.city);
		scanf("%d",&persons[i].p.pc);
	}
for(i=0;i<N;i++)
	{
		printf("%s\t",persons[i].name);
		printf("%s\t",persons[i].p.street);
		printf("%s\t",persons[i].p.city);
		printf("%d\n",persons[i].p.pc);
	}

}