#include"stdio.h"
struct stu
{
    char num[20];
    char name[5];     
	float scores[3];
}stus[5];
int main()
{
 int i,j;
 int t;
 float max;
 float ave[5],s=0;
 printf("input num\tname\tscores\t\n");

    for(i=0;i<5;i++)

     {
      printf("input num:\n");
      gets(stus[i].num);
      printf("input name:\n");
      gets(stus[i].name);
     for(j=0;j<3;j++)
     {
     
      printf("input the %dth score:\n",j+1);
      scanf("%f",&stus[i].scores[j]);
     }
	 fflush(stdin);
     }

    

    for(i=0;i<5;i++)

    {
       for(j=0;j<3;j++)
       {
      s+=stus[i].scores[j];
       }
       ave[i]=(float)s/3;
       max=ave[0];
       if(max<ave[i])
       {
           max=ave[i];
           t=i;
       }
	 }
   

    for(i=0;i<5;i++)
{
      printf("%.2f\t",ave[i]);

}
 printf("%s\t%s\n",stus[t].num,stus[t].name);
 for(j=0;j<3;j++)
 printf("%.2f\t",stus[t].scores[j]);
 printf("\n");
 return 0;

}