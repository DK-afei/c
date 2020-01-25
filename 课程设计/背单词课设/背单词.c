#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define N 100
#define S 20
struct words//定义一个words 结构体
{
	char e[S];//存放英语单词
	char c[S];//相应的汉语翻译
	int score;//每个单词得分
}str[N],str2[N];//定义结构体变量
int fenshu=0; //全局变量，用于统计分数
int count1=0;//全局变量，用于统计测试单词个数
static int p=0;//全局变量，用于统计单词个数
int z=0;//用户指定输入单词数
void showmenu();//显示菜单
void cunchu();//存储
void tianjia();//单词添加
void shuchu();//单词展示
void fanyi1();//英译汉
void fanyi2();//汉译英
void chengji();//查询成绩
void  tuichu();//退出系统
//显示菜单
void showmenu()
{
	printf("\n");
	printf("\t*****************************\n"); 
	printf("\t**  欢迎使用背单词系统!    **\n");
	printf("\t**  设计者：xxx            **\n");
	printf("\t**  班级：666   学号：666  **\n"); 
	printf("\t*****************************\n"); 
	printf("\t**0、显示菜单 1、单词添加  **\n");  
	printf("\t** 2、单词展示   3、英译汉 **\n"); 
	printf("\t** 4、汉译英    5、成绩查询**\n");
	printf("\t** 6、存储  7、退出系统    **\n");
	printf("\t*****************************\n"); 
	printf(" 请选择您需要的操作序号<1-7>,按回车结束:");
}
//存储
void cunchu()
{
	FILE*fp;
	int i=0;
	if((fp=fopen("E:\\课程设计\\背单词课设\\words.txt","w"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	fprintf(fp,"%s","中文	英文	score");
	for(i=0;i<p;i++)
	{
		fprintf(fp,"\n%s	%s	%d",str2[i].e,str2[i].c,str2[i].score);
	}
	fclose(fp);
	printf("\n储存成功\n");
	printf("\n\n按任意键返回.....\n");
	getch();
	system("cls");
	showmenu();
	return;
}
//单词添加
void tianjia()
{
	FILE*fp;
	char ch;
	if((fp=fopen("E:\\课程设计\\背单词课设\\words.txt","a"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	do
	{
		printf("录入词库!\n");
		printf("请输入英语单词:\n");
		scanf("%s",str[p].e);
		printf("\n请输入相应的中文翻译:\n");
		scanf("%s",str[p].c);
		fprintf(fp,"\n%s	%s	%d",str[p].e,str[p].c,str[p].score);
		p++;
		printf("%s已保存，是否继续录入？y/n!\n",str[p].e); 
		scanf("%s",&ch);
	}while(ch=='y');
	fclose(fp);
	printf("\n\n按任意键返回.....\n");
	getch();
	system("cls");
	showmenu();
	return;
}
//单词展示
void shuchu()
{
	FILE*fp;
	int i=0;
	char s1[10],s2[10],s3[10];
	if((fp=fopen("E:\\课程设计\\背单词课设\\words.txt","r"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	fscanf(fp,"%s%s%s",s1,s2,s3);
	printf("输出词库中所有的单词!\n");
	while(!feof(fp))
	{
		fscanf(fp,"%s%s%d",str2[i].e,str2[i].c,&str2[i].score);
		printf("英文单词是: %s",str2[i].e);
		printf("\n相应的中文意思是: %s \n",str2[i].c);
		printf("该单词当前得分：%d\n",str2[i].score);
		i++;
		p++;
	}
	printf("词库所有单词输出完毕!\n");
	fclose(fp);
	printf("\n\n按任意键返回.....\n");
	getch();
	system("cls");
	showmenu();
}
//英译汉
void fanyi1()
{
	int i=0;
	char f[S];
	char over[N]="jieshu";
	FILE*fp;
	char s1[10],s2[10],s3[10];
	if((fp=fopen("E:\\课程设计\\背单词课设\\words.txt","r"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	fscanf(fp,"%s%s%s",s1,s2,s3);
	while(!feof(fp))
	{
		fscanf(fp,"%s%s%d",str2[i].e,str2[i].c,&str2[i].score);
		i++;
	}
	fclose(fp);
	i=0;
	printf("请输入要背的单词数:\n");
	scanf("%d",&z);
	printf("请输入下面英文单词的翻译，希望结束输入时请输入 jieshu \n"); 
	while(i<z&&strcmp(f,over)!=0)//用户不输入jieshu 并且词库中单词没有全部输出时执行循环
	{
		printf("%s ",str2[i].e);
		scanf("%s",&f);
		if(strcmp(str2[i].c,f)==0)
		{
			printf("正确！\n");
			fenshu+=1; //用于计算分数
			str2[i].score++;
		}
		else
		{
			printf("很遗憾，正确的翻译为：");
			printf("%s\n",str2[i].c);
		}
		count1++;
		i++;
	}
	cunchu();
	printf("\n\n按任意键返回.....\n");
	getch();
	system("cls");
	showmenu();
	return;
}
//汉译英
void fanyi2()
{
	int i=0;
	char f[S];
	char over[N]="jieshu";
	FILE*fp;
	char s1[10],s2[10],s3[10];
	if((fp=fopen("E:\\课程设计\\背单词课设\\words.txt","r"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	fscanf(fp,"%s%s%s",s1,s2,s3);
	while(!feof(fp))
	{
		fscanf(fp,"%s%s%d",str2[i].e,str2[i].c,&str2[i].score);
		i++;
	}
	fclose(fp);
	i=0;
	printf("请输入要背的单词数:\n");
	scanf("%d",&z);
	printf("请输入下面英文单词的翻译，希望结束输入时请输入 jieshu \n"); 
	while(i<z&&strcmp(f,over)!=0)
	{
		printf("%s",str2[i].c);
		scanf("%s",&f);
		if(strcmp(str2[i].e,f)==0)
		{
			printf("正确！\n");
			fenshu+=1;
			str2[i].score++;
		}
		else
		{
			printf("很遗憾，正确的翻译为：");
			printf("%s\n",str2[i].e);
		}
		count1++;
		i++;
	}
	cunchu();
	printf("\n\n按任意键返回.....\n");
	getch();
	system("cls");
	showmenu();
	return;
}
//查询成绩
void chengji()
{
	printf("本次测试的成绩是:\n");
	printf("总共:%d个\n",count1);
	printf("正确:%d个\n",fenshu);
	printf("最后得分为(答对一个得1分，答错一个0分) ：%d \n",fenshu);
	printf("\n\n按任意键返回.....\n");
	getch();
	system("cls");
	showmenu();
	return;
}
//退出系统
void tuichu()
{
	char ch;
	printf("是否退出系统，是y。\n");
	scanf("%c",&ch);
	if(ch=='y')
	{
		printf("退出成功！\n");
		exit(0);
	}
	else
	{
		printf("退出失败！");
		printf("\n\n按任意键返回.....\n");
		getch();
		system("cls");
		showmenu();
		return;
	}
	
}
int main()
{
	int n;
	showmenu();
	while(1)
	{
		scanf("%d",&n);
		fflush(stdin);
		switch(n)
		{//执行相应的函数，实现相应的功能
			case 0:showmenu();break;
			case 1:tianjia();break;
			case 2:shuchu();break;
			case 3:fanyi1();break; 
			case 4:fanyi2();break; 
			case 5:chengji();break; 
			case 6:cunchu();break;
				//退出系统的操作
			case 7:tuichu();break;
			default :
				{
					printf("你输入了错误的操作，无法执行!\n");
					printf("\n\n按任意键返回.....\n");
					getch();
					system("cls");
					showmenu();
					break;
				}
		}
	}
	return 0;
}