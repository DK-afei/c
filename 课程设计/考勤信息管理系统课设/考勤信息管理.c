#include <stdio.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#define LEN sizeof(struct worker)
struct node
{
	char no[20];
	char name[20];
	char depart[20];
	char sex[10];
	char num[20];
	char career[10];
	char rights[20];
	struct node * link;
};
struct worker
{
	char number[20];
	char name[20];
	int late;
	int earlyleave;
	int notwork;
	struct worker *next;
};
typedef struct now
{
	int year;
	int month;
	int day;
	int weekday;
	int hour;
	int minute;
}NOW;
typedef struct node NODE;
NOW nowtime;
struct worker *head=NULL,*p1,*p2,*p3;/*定义结构体指针head 为头指针p1 为输入数据缓存空间指针p2 为尾指针,下同*/
NODE*head_=NULL,*p1_,*p2_,*p3_;
static int x=0;//职工人数
int writenflag=0;
int flag=0;
void welcome(); /*欢迎函数*/
void menuprint1(); /*主菜单打印*/
void menuprint2(); 
void loadinf(); /*从磁盘导入职工信息到内存*/
void monuprecord(); /*上午上班时间录入*/
void mondownrecord(); /*上午下班时间录入*/
void afteruprecord(); /*下午上班时间录入*/
void afterdownrecord(); /*下午下班时间录入*/
void evenuprecord(); /*晚上上班时间录入*/
void evendownrecord(); /*晚上下班时间录入*/
void allprint1(); /*显示所有职工信息*/
void allprint2();
void seek1(); /*查找*/
void seek2(); 
void change1(); /*修改*/
void change2();
void cutoff1(); /*删除*/
void cutoff2(); 
void add1();/*添加职工信息*/
void add2();
void inforsave1(); /*保存考勤信息*/
void inforsave2(); 
void quit(); /*退出*/
int input1(); /*输入选择*/
int input2();
void getjudge1(char wh[]); /*输入判断*/
void getjudge2(char wh[]); 
void putsecret(); /*密码*/
int changesecret();/*修改密码*/
int choice();
void Administrator();
void Attendanceclerk();
int main()
{
	welcome(); /*欢迎函数*/
	for(;;)
	{
		switch(choice()) 
		{
			case 1:	Administrator();break; 
			case 2:	Attendanceclerk();break; 
			default:
			{
				printf("\n\n输入错误，按任意键返回.....\n");
				getch();
				system("cls"); /*清屏*/
			}
		}
	}
	return 0;
}
void welcome()
{
	printf("\t\t\t***********************************************************\n");
	printf("\t\t\t***********************************************************\n");
	printf("\t\t\t***********************************************************\n");	
	printf("\t\t\t***********************************************************\n");
	printf("\t\t\t***********	    欢迎使用职工考勤系统！	    ***********\n");
	printf("\t\t\t***********		   WELCOME!	     	    ***********\n");
	printf("\t\t\t***********	    制作人：		    ***********\n");
	printf("\t\t\t***********		按任意键进入系统！！    ***********\n");
	printf("\t\t\t***********************************************************\n");
	printf("\t\t\t***********************************************************\n");
	printf("\t\t\t***********************************************************\n");	
	printf("\t\t\t***********************************************************\n");
	getch();
	system("cls");
	rewind(stdin);
}
int choice()
{
	int c;
	printf("1——管理员系统，2——考勤员系统\n");
	printf("请输入:\n");
	scanf("%d",&c);
	return c;
}
void Administrator()
{
	menuprint1();
	for(;;)
	{
		switch(input1()) 
		{
			case 1:	add1();break; /*添加职工信息*/
			case 2:	cutoff1();break; /*删除*/
			case 3:seek1();break; /*查找 */
			case 4:change1();break; /*修改*/
			case 5:inforsave1();break; /*保存考勤信息*/
			case 6:allprint1();break; /*显示所有职工信息*/
			default:
			{
				printf("\n\n输入错误，按任意键返回.....\n");
				getch();
				system("cls"); /*清屏*/
			}
		}
	}


}
void Attendanceclerk()
{
	menuprint2();
	loadinf();
	system("cls");
	for(;;)
	{
		switch(input2()) /*显示主菜单*/
		{
			case 1:monuprecord();break; /*上午上班时间录入*/
			case 2:mondownrecord();break; /*上午下班时间录入*/
			case 3:afteruprecord();break; /*下午上班时间录入*/
			case 4:afterdownrecord();break; /*下午下班时间录入*/
			case 5:evenuprecord();break; /*晚上上班时间录入*/
			case 6:evendownrecord();break; /*晚上下班时间录入*/
			case 7:allprint2();break; /*显示所有职工信息*/
			case 8:seek2();break; /*查找*/
			case 9:change2();break; /*修改*/
			case 10:cutoff2();break; /*删除*/
			case 11:inforsave2(); system("cls");break; /*保存考勤信息*/
			case 12:system("cls");quit();return ; /*退出*/
			case 13:add2();break;/*添加职工信息*/
			case 14:flag=1;putsecret();break;/*修改密码*/
			default:
			{
				rewind(stdin);
				printf("\n\n输入错误，按任意键返回.....\n");
				getch();
				system("cls"); /*清屏*/
			}
		}
	}
}
void menuprint1()
{
	printf("****************管理员系统主菜单********************\n");
	printf("*\t\t1.添加职工信息。	    \t   *\n");
	printf("*\t\t2.删除记录。（执行完此操请注意保存）*\n");
	printf("*\t\t3. 查询记录。		    \t   *\n");
	printf("*\t\t4.修改记录。（执行完此操请注意保存）*\n");
	printf("*\t\t5.保存记录。		    \t   *\n");
	printf("*\t\t6.职工整体浏览。	    \t   *\n");
	printf("*\t     （任何情况下按ctrl+c退出）     \t   *\n");
	printf("****************************************************\n");
}
void getjudge1(char wh[])
{
	char *p;
	p=wh;
	rewind(stdin);
	printf("\n请输入职工号：");
	while(1)
	{
		rewind(stdin);
		gets(wh);
		rewind(stdin);
		if((*p=='1'&&*(p+1)=='0'&&*(p+2)=='0'&&*(p+3)>='0'&&*(p+3)<='9'
		)||(*p=='1'&&*(p+1)=='0'&&*(p+2)=='1'&&*(p+3)>='0'))
		{
			printf("\n合法输入。\n");
			break;
		}
		else 
			printf("\n\n不合法输入，请重新输入职工号：");
	}
	return;
}
void allprint1()
{
	FILE*fp;
	int n=0;
	char s1[20],s2[20],s3[20],s4[20],s5[20],s6[20],s7[20];
	if((fp=fopen("E:\\课程设计\\考勤信息管理系统课设\\职工基本信息.txt","r"))==NULL)
	{
		printf("文件不存在或文件无法打开！\n");
		getch();
		return ;
	}
	fscanf(fp,"%s%s%s%s%s%s%s",s1,s2,s3,s4,s5,s6,s7);
	head_=p1_=(NODE*)malloc(sizeof(NODE));
	p1_->link=NULL;
	printf("\n职工信息如下：\n");
	printf("\n职工号  姓名   所属部门 性别 身份证号码  职务   权限\n");
	while(!feof(fp))
	{
		n++;
		fscanf(fp,"%s%s%s%s%s%s%s",p1_->no,p1_->name,p1_->depart,p1_->sex,p1_->num,p1_->career,p1_->rights);
		printf("%s	%s	%s	%s	%s	%s	%s\n",p1_->no,p1_->name,p1_->depart,p1_->sex,p1_->num,p1_->career,p1_->rights);
		p2_=(NODE*)malloc(sizeof(NODE));
		p1_->link=p2_;
		p3_=p1_;
		p1_=p2_;
		p1_->link=NULL;
	}
	x=n;
	printf("成功读取%d项数据",n);
	printf("\n按任意键返回.....\n");
	getch();
	system("cls");
	menuprint1();
	return ;
}
void add1()
{
	FILE*fp;
	char s1[20],s2[20],s3[20],s4[20],s5[20],s6[20],s7[20];
	int i=0,j=0;
	if((fp=fopen("E:\\课程设计\\考勤信息管理系统课设\\职工基本信息.txt","a+"))==NULL)
	{
		printf("文件不存在或文件无法打开！\n");
		getch();
		system("cls");
		return ;
	}
	printf("\n请输入要添加的职工数量：\n");
	scanf("%d",&j);
	while(1)
	{
		fseek(fp,0,SEEK_END);
		scanf("%s%s%s%s%s%s%s",s1,s2,s3,s4,s5,s6,s7);
		fprintf(fp,"\n%s	%s	%s	%s	%s	%s	%s",s1,s2,s3,s4,s5,s6,s7);
		i++;
		if(i==j)
			break;
	}
	fclose(fp);
	x+=j;
	printf("\n已添加%d项职工信息信息，按任意键返回····",j); 
	getch();
	system("cls");
	menuprint1();
	if(!fclose(fp))
	{
		printf("Can not close the file!\n\n");
		exit(0);
	}
}
void inforsave1()
{
	FILE *fp;
	int i=0;
	if(head_==NULL)
	{
		printf("\n数据库中没有考勤信息，按任意键返回...");
		getch();
		system("cls");
		return;
	}
	if((fp=fopen("E:\\课程设计\\考勤信息管理系统课设\\职工基本信息.txt","w"))==NULL)
	{
		printf("\n数据库中考勤信息无法保存，按任意键返回....");
		getch();
		system("cls");
		return;
	}
	fprintf(fp,"%s  %s  %s %s %s  %s	%s","职工号","姓名","所属部门","性别","身份证号码","职务","权限");
	p1_=head_;
	while(i<x)
	{
		fprintf(fp,"\n%s	%s	%s	%s	%s	%s	%s",p1_->no,p1_->name,p1_->depart,p1_->sex,p1_->num,p1_->career,p1_->rights);
		p1_=p1_->link;
		i++;
	}
	fclose(fp);
	printf("\n\n数据库中信息已保存完毕，按任意键返回....\n"); 
	getch();
	system("cls");
	menuprint1();
	return;
}
void seek1()
{ 
	char num[20];
	rewind(stdin);
	getjudge1(num);
	p1_=head_;
	if(p1_==NULL)
	{ 
		printf("\n信息数据库为空，按任意键返回...\n");
		getch();
		system("cls");
		return ;
	}
	printf("\n职工信息如下：\n");
	printf("\n职工号  姓名  所属部门  性别  身份证号码 职务   权限\n");
	while(p1_!=NULL)
	{
		if(strcmp(p1_->no,num )==0)
		{
			printf("%s	%s	%s	%s	%s	%s	%s\n",p1_->no,p1_->name,p1_->depart,p1_->sex,p1_->num,p1_->career,p1_->rights);
			break;
		}
		else 
			p1_=p1_->link;
	}
	if(p1_==NULL)
	{ 
		printf("\n职工信息数据库为空，按任意键返回...\n");
		printf("\n职工信息如下：\n");
		getch();
		system("cls");
		return ;
	}
	printf("\n按任意键返回....");
	getch();
	system("cls");
	menuprint1();
	return;
}
void change1()
{
	char num[20];
	rewind(stdin);
	getjudge1(num);
	if(head_==NULL)
	{
		getchar();
		printf("\n信息数据库为空，不能修改，按任意键返回..."); 
		getch();
		system("cls");
		return;
	}
	p1_=head_;
	while(strcmp(num,p1_->no)!=0&&p1_->link!=NULL)
		p1_=p1_->link;
	if(strcmp(num,p1_->no)==0)
	{
		strcpy(p1_->no,num);
		printf("\n请输入该职工的名字：");
		scanf("%s",p1_->name);
		printf("\n请输入该职工的所属部门：");
		scanf("%s",p1_->depart);
		printf("\n请输入该职工的性别：");
		scanf("%s",p1_->sex);
		printf("\n请输入该职工的身份证号码：");
		scanf("%s",p1_->num);
		printf("\n请输入该职工的职务：");
		scanf("%s",p1_->career);
		printf("\n请输入该职工的权限：");
		scanf("%s",p1_->rights);
		printf("\n一项信息修改完毕。\n");
	}
	else
	printf("\n找不到该职工的考勤信息！\n");
	getchar();
	printf("\n按任意键返回.....\n");
	getch();
	system("cls");
	menuprint1();
	return ;
}
void cutoff1()
{
	char num[20];
	if(head_==NULL)
	{
		getchar();
		printf("\n信息为空，不能删除，按任意键返回....");
		getch();
		system("cls");
		return;
		getchar();
	}
	p1_=head_;
	rewind(stdin);
	getjudge1(num);
	while(strcmp(num,p1_->no)!=0&&p1_->link!=NULL)
	{
		p2_=p1_;
		p1_=p1_->link;
	}
	if(strcmp(num,p1_->no)==0)
	{
		if(head_->link==NULL)
		{
			free(head_);
			head_=NULL;
		}
		else if(head_==p1_)
		{
			head_=p1_->link;
			free(p1_);
		}
		else 
		{ 
			p2_->link=p1_->link;
			free(p1_);
		}
		printf("\n删除完毕。\n");
		x-=1;
	}
	else
	printf("\n找不到该职工的考勤信息！\n");
	printf("\n按任意键返回...");
	getch();
	system("cls");
	menuprint1();
	return ;
}
int input1()
{
	int c;
	printf("请输入你的选择（1~6）：");
	scanf("%d",&c);
	return c;
}
int input2()
{
	int c;
	printf("******************************考勤员系统主菜单***********************************\n");
	printf("*\t\t\t\t\t\t\t\t\t\t*\n");
	printf("*\t\t\t\t1.上午上班时间录入。 \t\t\t\t*\n");
	printf("*\t\t\t\t2.上午下班时间录入。\t\t\t\t*\n");
	printf("*\t\t\t\t3.下午上班时间录入。 \t\t\t\t*\n");
	printf("*\t\t\t\t4.下午下班时间录入。 \t\t\t\t*\n");
	printf("*\t\t\t\t5.晚上上班时间录入。 \t\t\t\t*\n");
	printf("*\t\t\t\t6.晚上下班时间录入。 \t\t\t\t*\n");
	printf("*\t\t\t\t7.职工整体出勤情况浏览。 \t\t\t*\n");
	printf("*\t\t\t\t8.查询考勤记录。 \t\t\t\t*\n");
	printf("*\t\t\t\t9.修改考勤记录。 \t\t\t\t*\n");
	printf("*\t\t\t\t10.删除考勤记录。 \t\t\t\t*\n");
	printf("*\t\t\t\t11.保存考勤记录。 \t\t\t\t*\n");
	printf("*\t\t\t\t12.退出。（任何情况下按ctrl+c退出） \t\t*\n");
	printf("*\t\t\t\t13.添加职工信息。 \t\t\t\t*\n");
	printf("*\t\t\t\t14.修改密码。 \t\t\t\t\t*\n");
	printf("*\t\t\t\t\t\t\t\t\t\t*\n");
	printf("*********************************************************************************\n");
	printf("请输入你的选择（1~14）：");
	scanf("%d",&c);
	rewind(stdin);
	return c;
}
/*主菜单*/
void menuprint2()
{
	printf("******************************考勤员系统主菜单***********************************\n");
	printf("*\t\t\t\t\t\t\t\t\t\t*\n");
	printf("*\t\t\t\t1.上午上班时间录入。 \t\t\t\t*\n");
	printf("*\t\t\t\t2.上午下班时间录入。\t\t\t\t*\n");
	printf("*\t\t\t\t3.下午上班时间录入。 \t\t\t\t*\n");
	printf("*\t\t\t\t4.下午下班时间录入。 \t\t\t\t*\n");
	printf("*\t\t\t\t5.晚上上班时间录入。 \t\t\t\t*\n");
	printf("*\t\t\t\t6.晚上下班时间录入。 \t\t\t\t*\n");
	printf("*\t\t\t\t7.职工整体出勤情况浏览。 \t\t\t*\n");
	printf("*\t\t\t\t8.查询考勤记录。 \t\t\t\t*\n");
	printf("*\t\t\t\t9.修改考勤记录。 \t\t\t\t*\n");
	printf("*\t\t\t\t10.删除考勤记录。 \t\t\t\t*\n");
	printf("*\t\t\t\t11.保存考勤记录。 \t\t\t\t*\n");
	printf("*\t\t\t\t12.退出。（任何情况下按ctrl+c退出） \t\t*\n");
	printf("*\t\t\t\t13.添加职工信息。 \t\t\t\t*\n");
	printf("*\t\t\t\t14.修改密码。 \t\t\t\t\t*\n");
	printf("*\t\t\t\t\t\t\t\t\t\t*\n");
	printf("*********************************************************************************\n");
}
/*输入判断*/
void getjudge2(char wh[])
{
	char *p;
	p=wh;
	rewind(stdin);
	printf("\n请输入职工号：");
	while(1)
	{
		rewind(stdin);
		gets(wh);
		rewind(stdin);
		if((*p=='1'&&*(p+1)=='0'&&*(p+2)=='0'&&*(p+3)>='0'&&*(p+3)<='9'
		)||(*p=='1'&&*(p+1)=='0'&&*(p+2)=='1'&&*(p+3)>='0'))
		{
			printf("\n合法输入。\n");
			break;
		}
		else 
			printf("\n\n不合法输入，请重新输入职工号：");
	}
	return;
}
/*密码*/
void putsecret()
{
	int y;
	int i;
	FILE *fp;
	static char str1[7]="abc123";
	char str2[7]="0";
	rewind(stdin);
	if((fp=fopen("E:\\课程设计\\考勤信息管理系统课设\\password","r+"))==NULL)
	{
		printf("文件不存在或文件无法打开！\n");
		getch();
		system("cls");
		return ;
	}
	fread(str1,sizeof(char),7,fp);
	rewind(fp);
	printf("\n请输入密码：");
	while(1)
	{
		gets(str2);
		y=strcmp(str1,str2);
		if(y!=0)
			printf("\n密码输入错误，请重新输入：");
		else
			break;
	}
	if(changesecret()==1)
	{
		printf("请输入新密码：（注意：密码最多六位）\n");
		for(i=0;i<6;i++)
		{
			str1[i]=getch();
			printf("*");
		}
		str1[7]='\0';
		flag=0;
		fwrite(str1,sizeof(char),7,fp);
		printf("\n已成功修改密码，按任意键返回····"); 
		getch();
		system("cls");
	}
	fclose(fp);
	return ;
}
/*修改密码*/
int changesecret()
{
	if(flag==1)
		return 1;
	else
		return 0;
}
/*从磁盘导入职工信息到内存*/
void loadinf()
{
	FILE *fp;
	int n=0;
	if((fp=fopen("E:\\课程设计\\考勤信息管理系统课设\\职工考勤信息.txt","r"))==NULL)
	{
		printf("文件不存在或文件无法打开！\n");
		getch();
		system("cls");
		return ;
	}
	printf("\n\t\t\t\t读入考勤信息如下\n");
	printf("\n职工号\t\t姓 名\t\t迟到次数\t早退次数\t旷工次数\n");
	head=p1=(struct worker*)malloc(LEN);
	p1->next=NULL;
	while(!feof(fp))
	{
		n++;
		fscanf(fp,"%s%s%d%d%d",p1->number,p1->name,&p1->late,&p1->earlyleave,&p1->notwork);
		if(p1->number[0]<'0'||p1->number[0]>'9')
		{
			n--;
			break;
		}
		printf("%s\t\t%s\t\t%5d\t\t%5d\t\t%5d\n",p1->number,p1->name,p1->late,p1->earlyleave,p1->notwork);
		p2=(struct worker *)malloc(LEN);
		p1->next=p2;
		p3=p1;
		p1=p2;
		p1->next=NULL;
	}
	free(p2);
	p3->next=NULL;
	fclose(fp);
	printf("\n已读取%d项职工信息信息，按任意键返回····",n); 
	getch();
	system("cls");
	writenflag=0;
	if(!fclose(fp))
	{
		printf("Can not close the file!\n\n");
		exit(0);
	}
}
/*添加职工信息*/
void add2()
{
	FILE*fp;
	char number0[20],name0[20];
	int late0,earlyleave0,notwork0,i=0,j=0;
	if((fp=fopen("E:\\课程设计\\考勤信息管理系统课设\\职工考勤信息.txt","a+))==NULL)
	{
		printf("文件不存在或文件无法打开！\n");
		getch();
		system("cls");
		return ;
	}
	printf("\n请输入要添加的职工数量：\n");
	scanf("%d",&j);
	while(1)
	{
		fseek(fp,0,SEEK_END);
		scanf("%s%s%d%d%d",number0,name0,&late0,&earlyleave0,&notwork0);
		fprintf(fp,"\n%s %s %d %d %d",number0,name0,late0,earlyleave0,notwork0);
		i++;
		if(i==j)
			break;
	}
	fclose(fp);
	printf("\n已添加%d项职工信息信息，按任意键返回····",j); 
	getch();
	system("cls");
	if(!fclose(fp))
	{
		printf("Can not close the file!\n\n");
		exit(0);
	}
}
/*上午上班时间录入*/
void monuprecord()
{
	char num[20];
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	asctime (timeinfo);
	if(timeinfo->tm_wday==6||timeinfo->tm_wday==0)
	{
		printf("\n现在是周末，不是上班时间。\n");
		printf("\n按任意键返回...");
		getch();
		system("cls");
		return;
	}
	if(timeinfo->tm_hour>=12)
	{
		printf("\n现在不是上午，不能进行此操作。按任意键返回...");
		getch();
		system("cls");
		return;
	}
	printf ( "\n现在时间为：%4d-%02d-%02d %02d:%02d:%02d\t星期：%d\n",1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_wday);
	nowtime.year=1900+timeinfo->tm_year;
	nowtime.month=1+timeinfo->tm_mon;
	nowtime.day=timeinfo->tm_mday;
	nowtime.weekday=timeinfo->tm_wday;
	nowtime.hour=timeinfo->tm_hour;
	nowtime.minute=timeinfo->tm_min;
	p1=head;
	rewind(stdin);
	getjudge2(num);
	if((nowtime.hour==8&&nowtime.minute==0)||nowtime.hour<8)
		printf("\n正常上班。\n");
	/*迟到判断*/
	if((nowtime.hour==8&&nowtime.minute>=0&&nowtime.minute<=5))
	{
		printf("\n上班迟到\n。");
		while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
		if(strcmp(num,p1->number)==0)
		{
			(p1->late)++;
		}
	}
	/*旷工判断*/
	if((nowtime.hour==8&&nowtime.minute>5)||nowtime.hour>8) 
	{
		printf("\n旷工一次。\n");
		while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
		if(strcmp(num,p1->number)==0)
		{
			(p1->notwork)++;
		}
	}
	writenflag=1;
	printf("\n考勤信息已录入，按任意键返回...");
	getch();
	system("cls");
}
/*上午下班时间录入*/
void mondownrecord()
{
	char num[20];
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	asctime (timeinfo);
	if(timeinfo->tm_wday==6||timeinfo->tm_wday==0)
	{
		printf("\n现在是周末，不允许进行此操作。\n");
		printf("\n按任意键返回...");
		getch();
		system("cls");
		return;
	}
	printf ( "\n现在时间为：%4d-%02d-%02d %02d:%02d:%02d\t星期：%d\n\n",1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_wday);
	nowtime.year=1900+timeinfo->tm_year;
	nowtime.month=1+timeinfo->tm_mon;
	nowtime.day=timeinfo->tm_mday;
	nowtime.weekday=timeinfo->tm_wday;
	nowtime.hour=timeinfo->tm_hour;
	nowtime.minute=timeinfo->tm_min;
	p1=head;
	rewind(stdin);
	getjudge2(num);
	if(nowtime.hour>11||(nowtime.hour==11&&nowtime.minute>=30)) printf("\n正常下班。\n");
	/*早退判断*/
	if(nowtime.hour<11||(nowtime.hour==11&&nowtime.minute<=30))
	{
		printf("\n早退。\n");
		while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
		if(strcmp(num,p1->number)==0)
		{
			(p1->earlyleave)++;
		}
	}
	writenflag=1;
	printf("\n考勤信息已录入，按任意键返回...");
	getch();
	system("cls");
}
/*下午上班时间录入*/
void afteruprecord()
{
	char num[20];
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	asctime (timeinfo);
	if(timeinfo->tm_wday==6||timeinfo->tm_wday==0)
	{
		printf("\n现在是周末，不是上班时间。\n");
		printf("\n按任意键返回...");
		getch();
		system("cls");
		return;
	}
	if(timeinfo->tm_hour<=12)
	{
		printf("\n现在不是下午，不能进行此操作。按任意键返回..."); getch();
		system("cls");
		return;
	}
	printf ( "\n现在时间为：%4d-%02d-%02d %02d:%02d:%02d\t星期：%d\n",1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_wday);
	nowtime.year=1900+timeinfo->tm_year;
	nowtime.month=1+timeinfo->tm_mon;
	nowtime.day=timeinfo->tm_mday;
	nowtime.weekday=timeinfo->tm_wday;
	nowtime.hour=timeinfo->tm_hour;
	nowtime.minute=timeinfo->tm_min;
	p1=head;
	rewind(stdin);
	getjudge2(num);
	if(nowtime.hour<=14)
	printf("\n正常上班。\n");
	/*迟到判断*/
	if(nowtime.hour==14&&nowtime.minute>=0&&nowtime.minute<=5)
	{
		printf("\n上班迟到\n。");
		while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
		if(strcmp(num,p1->number)==0)
		{
			(p1->late)++;
		}
	}
	/*旷工判断*/
	if((nowtime.hour==14&&nowtime.minute>5)||nowtime.hour>14)
	{
		printf("\n旷工一次。\n");
		while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
		if(strcmp(num,p1->number)==0)
		{
			(p1->notwork)++;
		}
	}
	writenflag=1;
	printf("\n考勤信息已录入，按任意键返回...");
	getch();
	system("cls");
}
/*下午下班时间录入*/
void afterdownrecord()
{
	char num[20];
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	asctime (timeinfo);
	if(timeinfo->tm_wday==6||timeinfo->tm_wday==0)
	{
		printf("\n现在是周末，不允许进行此操作。\n");
		printf("\n按任意键返回...");
		getch();
		system("cls");
		return;
	}
	printf ( "\n现在时间为：%4d-%02d-%02d %02d:%02d:%02d\t星期：%d\n\n",1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_wday);
	nowtime.year=1900+timeinfo->tm_year;
	nowtime.month=1+timeinfo->tm_mon;
	nowtime.day=timeinfo->tm_mday;
	nowtime.weekday=timeinfo->tm_wday;
	nowtime.hour=timeinfo->tm_hour;
	nowtime.minute=timeinfo->tm_min;
	p1=head;
	//getchar();
	rewind(stdin);
	getjudge2(num);
	if(nowtime.hour>=17)
	printf("\n正常下班。\n");
	/*早退判断*/
	if(nowtime.hour<17||(nowtime.hour=17&&nowtime.minute<30))
	{
		printf("\n早退。\n");
		while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
		if(strcmp(num,p1->number)==0)
		{
			(p1->earlyleave)++;
		}
	}
	writenflag=1;
	printf("\n考勤信息已录入，按任意键返回...");
	getch();
	system("cls");
}
/*晚上上班时间录入*/
void evenuprecord()
{
	char num[20];
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	asctime (timeinfo);
	if(timeinfo->tm_wday==6||timeinfo->tm_wday==0)
	{
		printf("\n现在是周末，不是上班时间。\n");
		printf("\n按任意键返回...");
		getch();
		system("cls");
		return;
	}
	if(timeinfo->tm_hour<=17)
	{
		printf("\n现在不是晚上，不能进行此操作。按任意键返回..."); getch();
		system("cls");
		return;
	}
	printf ( "\n现在时间为：%4d-%02d-%02d %02d:%02d:%02d\t星期：%d\n",1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_wday);
	nowtime.year=1900+timeinfo->tm_year;
	nowtime.month=1+timeinfo->tm_mon;
	nowtime.day=timeinfo->tm_mday;
	nowtime.weekday=timeinfo->tm_wday;
	nowtime.hour=timeinfo->tm_hour;
	nowtime.minute=timeinfo->tm_min;
	p1=head;
	rewind(stdin);
	getjudge2(num);
	if((nowtime.hour==18&&nowtime.minute==0)||nowtime.hour<18) printf("\n正常上班。\n");
	/*迟到判断*/
	if((nowtime.hour==18&&nowtime.minute>=0&&nowtime.minute<=5)) 
	{
		printf("\n上班迟到\n。");
		while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
		if(strcmp(num,p1->number)==0)
		{
			(p1->late)++;
		}
	}
	/*旷工判断*/
	if((nowtime.hour==18&&nowtime.minute>5)||nowtime.hour>18) 
	{
		printf("\n旷工一次。\n");
		while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
		if(strcmp(num,p1->number)==0)
		{
			(p1->notwork)++;
		}
	}
	writenflag=1;
	printf("\n考勤信息已录入，按任意键返回...");
	getch();
	system("cls");
}
/*晚上下班时间录入*/
void evendownrecord()
{
	char num[20];
	time_t rawtime;
	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	asctime (timeinfo);
	if(timeinfo->tm_wday==6||timeinfo->tm_wday==0)
	{
		printf("\n现在是周末，不允许进行此操作。\n");
		printf("\n按任意键返回...");
		getch();
		system("cls");
		return;
	}
	printf ( "\n现在时间为：%4d-%02d-%02d %02d:%02d:%02d\t星期：%d\n\n",1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_wday);
	nowtime.year=1900+timeinfo->tm_year;
	nowtime.month=1+timeinfo->tm_mon;
	nowtime.day=timeinfo->tm_mday;
	nowtime.weekday=timeinfo->tm_wday;
	nowtime.hour=timeinfo->tm_hour;
	nowtime.minute=timeinfo->tm_min;
	p1=head;
	//getchar();
	rewind(stdin);
	getjudge2(num);
	if(nowtime.hour>=21)
	printf("\n正常下班。\n");
	/*早退判断*/
	if(nowtime.hour<=21)
	{
		printf("\n早退。\n");
		while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
		if(strcmp(num,p1->number)==0)
		{
			(p1->earlyleave)++;
		}
	}
	writenflag=1;
	printf("\n考勤信息已录入，按任意键返回...");
	getch();
	system("cls");
}
/*查找*/
void seek2()
{ 
	char num[20];
	rewind(stdin);
	putsecret();
	rewind(stdin);
	getjudge2(num);
	p1=head;
	if(p1==NULL)
	{ 
		printf("\n职工信息数据库为空，按任意键返回...\n");
		getch();
		system("cls");
		return ;
	}
	printf("\n\t\t\t\t职工考勤信息如下：\n");
	printf("\n职工号\t\t姓 名\t\t迟到次数\t早退次数\t矿工次数\n");
	while(p1!=NULL)
	{
		if(strcmp(p1->number,num )==0)
		{
			printf("%s\t\t%s\t\t%5d\t\t%5d\t\t%5d\n",p1->number,p1->name,p1->late,p1->earlyleave,p1->notwork);
			break;
		}
		else 
			p1=p1->next;
	}
	if(p1==NULL)
	{ 
		printf("\n职工信息数据库为空，按任意键返回...\n");
		printf("\n\t\t\t\t职工考勤信息如下：\n");
		getch();
		system("cls");
		return ;
	}
	printf("\n按任意键返回....");
	getch();
	system("cls");
}
/*显示所有信息*/
void allprint2()
{
	rewind(stdin);
	if(head==NULL)
	{
		printf("\n数据库中没有考勤信息，按Enter 键返回。\n"); 
		getchar();
		system("cls");
	}
	printf("\n\t\t\t\t全部考勤信息如下\n");
	printf("\n职工号\t\t姓 名\t\t迟到次数\t早退次数\t矿工次数\n");
	p1=head;
	while(p1!=NULL)
	{
		printf("%s\t\t%s\t\t%5d\t\t%5d\t\t%5d\n",p1->number,p1->name,p1->late,p1->earlyleave,p1->notwork);
		p1=p1->next;
	}
	printf("\n按任意键返回....");
	getch();
	system("cls");
}
/*修改*/
void change2()
{
	char num[20];
	rewind(stdin);
	putsecret();
	rewind(stdin);
	getjudge2(num);
	if(head==NULL)
	{
		getchar();
		printf("\n考勤信息数据库为空，不能修改，按任意键返回..."); 
		getch();
		system("cls");
		return;
	}
	p1=head;
	while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
	p1=p1->next;
	if(strcmp(num,p1->number)==0)
	{
		strcpy(p1->number,num);
		printf("\n请输入该职工的名字：");
		scanf("%s",p1->name);
		printf("\n请输入该职工的迟到的次数：");
		scanf("%d",&p1->late);
		printf("\n请输入该职工的早退的次数：");
		scanf("%d",&p1->earlyleave);
		printf("\n请输入该职工的旷工的天数：");
		scanf("%d",&p1->notwork);
		printf("\n一项信息修改完毕。\n");
	}
	else
	printf("\n找不到该职工的考勤信息！\n");
	getchar();
	printf("\n按任意键返回.....\n");
	getch();
	system("cls");
	writenflag=1;
	return ;
}
/*删除*/
void cutoff2()
{
	char num[20];
	putsecret();
	if(head==NULL)
	{
		getchar();
		printf("\n考勤信息为空，不能删除，按任意键返回....");
		getch();
		system("cls");
		return;
		getchar();
	}
	p1=head;
	rewind(stdin);
	getjudge2(num);
	while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
	{
		p2=p1;
		p1=p1->next;
	}
	if(strcmp(num,p1->number)==0)
	{
		if(head->next==NULL)
		{
			free(head);
			head=NULL;
		}
		else if(head==p1)
		{
			head=p1->next;
			free(p1);
		}
		else 
		{ 
			p2->next=p1->next;
			free(p1);
		}
		printf("\n删除完毕。\n");
	}
	else
	printf("\n找不到该职工的考勤信息！\n");
	printf("\n按任意键返回...");
	getch();
	system("cls");
	writenflag=1;
	return ;
}
/*保存考勤信息*/
void inforsave2()
{
	FILE *fp;
	if(head==NULL)
	{
		printf("\n数据库中没有考勤信息，按任意键返回...");
		getch();
		system("cls");
		return;
	}
	if(writenflag==0)
	{
		printf("\n数据库中考勤信息已保存过，按任意键返回...."); 
		getch();
		return;
	}
	if((fp=fopen("E:\\课程设计\\考勤信息管理系统课设\\职工考勤信息.txt","W"))==NULL)
	{
		printf("\n数据库中考勤信息无法保存，按任意键返回...."); getch();
		system("cls");
		return;
	}
	p1=head;
	while(p1!=NULL)
	{
		fprintf(fp,"%s %s %d %d %d\n",p1->number,p1->name,p1->late,p1->earlyleave,p1->notwork);
		p1=p1->next;
	}
	fclose(fp);
	printf("\n\n数据库中考勤信息已保存完毕，按任意键返回....\n"); 
	getch();
	system("cls");
	writenflag=0;
	return;
}
/*退出*/
void quit()
{
	rewind(stdin);
	printf("\n\n\n\n\t\t\t*************************\n");
	printf("\t\t\t*\t谢谢使用！\t*\n");
	printf("\t\t\t*************************\n\n\n\n\n");
	if( writenflag==1)
	inforsave2();
	p1=head;
	while(p1!=NULL)
	{
		p2=p1->next;
		free(p1);
		p1=p2;
	}
	return ;
}