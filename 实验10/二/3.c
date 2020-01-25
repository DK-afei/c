#include <stdio.h>
	struct persons
	{
		char name[64];
		int birthyear;
	};
	struct mem
	{
		char num[9];
		struct persons person;
	}mems[2]={{"302039823","John",1985},{"302039776","Alice",2000}};
void input(struct mem *p)
{
	int i;
	for(i=0;i<2;i++)
	{
		printf("%s\t",(p+i)->num);
		printf("%s\t",(p+i)->person.name);
		printf("%d",(p+i)->person.birthyear);
		printf("\n");
	}

}
void main()
{
    struct mem *p;
	p=mems;
	input(p);
}
