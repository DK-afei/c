#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int getInt();//��ȡ����
void judge(int,int);//�ж�
void showOrder();//��ʾ����
int exception(int);//�ж�����
int systemExit(int);//�˳�
//��ʾ����
void showOrder()
{
	printf("  �������ж�ϵͳ\n");
	printf("������һ�������������������0�˳���\n");
}
//��ȡ����
int getInt()
{
	int a;
	scanf("%d",&a);
	return a;
}
//�ж�
void judge(int a,int i)
{
	int b;
	b=a;
	do
	{
		b=b/10;
		i*=10;
	}while(b>0);
	if((a*a)%i==a)
		printf("%d��������!\n",a);
	else
		printf("%d����������!\n",a);
	getch();
	system("cls");//����
	return;
}
//�ж�����
int exception(int a)
{
	if(a<0)
	{
		printf("%d����������!\n",a);
		return 0;
	}
	else 
		return 1;
}
//�˳�
int systemExit(int a)
{
	if(a==0)
	printf("ллʹ�ã��ټ���\n");
	return a;
}
int main()
{
	int i,a;
	for(;;)
	{
		i=1;
		showOrder();
		a=getInt();
		if(!systemExit(a))
			break;
		if(!exception(a))
		{
			getch();
			system("cls");
			continue;
		}
		else
			judge(a,i);
	}
		return 0;
}
