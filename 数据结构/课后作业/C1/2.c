#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void menu();
void complex_make(int *p1, int *p2);
void complex_add(int *p1, int *p2,int *p3, int *p4);
void complex_subtract(int *p1, int *p2,int *p3, int *p4);
void complex_mutiply(int *p1, int *p2,int *p3, int *p4);
void complex_separate();
int main()
{
	int choice,a,b,c,d;
	menu();
	for(;;)
	{
		printf("please input a functional choice :\n");
		scanf("%d",&choice);
		switch(choice) 
		{
			case 1:complex_make(&a,&b);break;
			case 2:complex_add(&a,&b,&c,&d);break;
			case 3:complex_subtract(&a,&b,&c,&d);break; 
			case 4:complex_mutiply(&a,&b,&c,&d);break;
			case 5:complex_separate();break;
			default:
			{
				printf("\n\n������󣬰����������.....\n");
				getch();
				system("cls"); /*����*/
			}
		}
	}
	return 0;
}
void menu()
{
	printf("1����������\n");
	printf("2���������\n");
	printf("3���������\n");
	printf("4���������\n");
	printf("5��������ʵ����\n");
	printf("�κ�����°�ctrl+c�˳���\n");
}
void complex_make(int *p1, int *p2)
{
	printf("please input the real part of the complex:\n");
	scanf("%d",p1);
	printf("please input the imaginary part of the complex:\n");
	scanf("%d",p2);
	printf("the maked complex is : (%d, %di)\n",*p1,*p2);
}
void complex_add(int *p1, int *p2,int *p3, int *p4)
{
	printf("please input the first complex:\n");
	complex_make(p1,p2);
	printf("please input the second complex:\n");
	complex_make(p3,p4);
	printf("the final result is (%d,%di)\n",*p1+*p3,*p2+*p4);
}
void complex_subtract(int *p1, int *p2,int *p3, int *p4)
{
	printf("please input the first complex:\n");
	complex_make(p1,p2);
	printf("please input the second complex:\n");
	complex_make(p3,p4);
	printf("the final result is (%d,%di)\n",*p1-*p3,*p2-*p4);
}
void complex_mutiply(int *p1, int *p2,int *p3, int *p4)
{
	printf("please input the first complex:\n");
	complex_make(p1,p2);
	printf("please input the second complex:\n");
	complex_make(p3,p4);
	printf("the final result is (%d,%di)\n",(*p1)*(*p3)-(*p2)*(*p4),(*p2)*(*p3)+(*p1)*(*p4));
}
void complex_separate()
{
	int m, n;
	printf("please input the complex:\n");
	scanf("%d,%di",&m,&n);
	printf("the imaginary part of the complex is %d\n",n);
}