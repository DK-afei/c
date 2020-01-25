#include"stdio.h"
struct mem
{
    char *name;
    int age;
    float salary;
}man[3]={
          {"李明",25,2500},
          {"王利",22,2300},
          {"赵勇",30,3000}
        };
 main()
{
     int i;
     printf("name\t\t\tage\t\t\tsalary\n\n");

    for(i=0;i<3;i++)

      printf("%s\t\t\t%d\t\t\t%.2f\n",man[i].name,man[i].age,man[i].salary);

}
