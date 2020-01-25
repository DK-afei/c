#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int getInt();//获取输入
void judge(int,int);//判断
void showOrder();//显示命令
int exception(int);//判断例外
int systemExit(int);//退出
//显示命令
void showOrder()
{
	printf("  自守数判断系统\n");
	printf("请输入一个任意的整数：（输入0退出）\n");
}
//获取输入
int getInt()
{
	int a;
	scanf("%d",&a);
	return a;
}
//判断
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
		printf("%d是自守数!\n",a);
	else
		printf("%d不是自守数!\n",a);
	getch();
	system("cls");//清屏
	return;
}
//判断例外
int exception(int a)
{
	if(a<0)
	{
		printf("%d不是自守数!\n",a);
		return 0;
	}
	else 
		return 1;
}
//退出
int systemExit(int a)
{
	if(a==0)
	printf("谢谢使用，再见了\n");
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
