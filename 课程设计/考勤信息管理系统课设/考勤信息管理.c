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
struct worker *head=NULL,*p1,*p2,*p3;/*����ṹ��ָ��head Ϊͷָ��p1 Ϊ�������ݻ���ռ�ָ��p2 Ϊβָ��,��ͬ*/
NODE*head_=NULL,*p1_,*p2_,*p3_;
static int x=0;//ְ������
int writenflag=0;
int flag=0;
void welcome(); /*��ӭ����*/
void menuprint1(); /*���˵���ӡ*/
void menuprint2(); 
void loadinf(); /*�Ӵ��̵���ְ����Ϣ���ڴ�*/
void monuprecord(); /*�����ϰ�ʱ��¼��*/
void mondownrecord(); /*�����°�ʱ��¼��*/
void afteruprecord(); /*�����ϰ�ʱ��¼��*/
void afterdownrecord(); /*�����°�ʱ��¼��*/
void evenuprecord(); /*�����ϰ�ʱ��¼��*/
void evendownrecord(); /*�����°�ʱ��¼��*/
void allprint1(); /*��ʾ����ְ����Ϣ*/
void allprint2();
void seek1(); /*����*/
void seek2(); 
void change1(); /*�޸�*/
void change2();
void cutoff1(); /*ɾ��*/
void cutoff2(); 
void add1();/*���ְ����Ϣ*/
void add2();
void inforsave1(); /*���濼����Ϣ*/
void inforsave2(); 
void quit(); /*�˳�*/
int input1(); /*����ѡ��*/
int input2();
void getjudge1(char wh[]); /*�����ж�*/
void getjudge2(char wh[]); 
void putsecret(); /*����*/
int changesecret();/*�޸�����*/
int choice();
void Administrator();
void Attendanceclerk();
int main()
{
	welcome(); /*��ӭ����*/
	for(;;)
	{
		switch(choice()) 
		{
			case 1:	Administrator();break; 
			case 2:	Attendanceclerk();break; 
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
void welcome()
{
	printf("\t\t\t***********************************************************\n");
	printf("\t\t\t***********************************************************\n");
	printf("\t\t\t***********************************************************\n");	
	printf("\t\t\t***********************************************************\n");
	printf("\t\t\t***********	    ��ӭʹ��ְ������ϵͳ��	    ***********\n");
	printf("\t\t\t***********		   WELCOME!	     	    ***********\n");
	printf("\t\t\t***********	    �����ˣ�		    ***********\n");
	printf("\t\t\t***********		�����������ϵͳ����    ***********\n");
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
	printf("1��������Աϵͳ��2��������Աϵͳ\n");
	printf("������:\n");
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
			case 1:	add1();break; /*���ְ����Ϣ*/
			case 2:	cutoff1();break; /*ɾ��*/
			case 3:seek1();break; /*���� */
			case 4:change1();break; /*�޸�*/
			case 5:inforsave1();break; /*���濼����Ϣ*/
			case 6:allprint1();break; /*��ʾ����ְ����Ϣ*/
			default:
			{
				printf("\n\n������󣬰����������.....\n");
				getch();
				system("cls"); /*����*/
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
		switch(input2()) /*��ʾ���˵�*/
		{
			case 1:monuprecord();break; /*�����ϰ�ʱ��¼��*/
			case 2:mondownrecord();break; /*�����°�ʱ��¼��*/
			case 3:afteruprecord();break; /*�����ϰ�ʱ��¼��*/
			case 4:afterdownrecord();break; /*�����°�ʱ��¼��*/
			case 5:evenuprecord();break; /*�����ϰ�ʱ��¼��*/
			case 6:evendownrecord();break; /*�����°�ʱ��¼��*/
			case 7:allprint2();break; /*��ʾ����ְ����Ϣ*/
			case 8:seek2();break; /*����*/
			case 9:change2();break; /*�޸�*/
			case 10:cutoff2();break; /*ɾ��*/
			case 11:inforsave2(); system("cls");break; /*���濼����Ϣ*/
			case 12:system("cls");quit();return ; /*�˳�*/
			case 13:add2();break;/*���ְ����Ϣ*/
			case 14:flag=1;putsecret();break;/*�޸�����*/
			default:
			{
				rewind(stdin);
				printf("\n\n������󣬰����������.....\n");
				getch();
				system("cls"); /*����*/
			}
		}
	}
}
void menuprint1()
{
	printf("****************����Աϵͳ���˵�********************\n");
	printf("*\t\t1.���ְ����Ϣ��	    \t   *\n");
	printf("*\t\t2.ɾ����¼����ִ����˲���ע�Ᵽ�棩*\n");
	printf("*\t\t3. ��ѯ��¼��		    \t   *\n");
	printf("*\t\t4.�޸ļ�¼����ִ����˲���ע�Ᵽ�棩*\n");
	printf("*\t\t5.�����¼��		    \t   *\n");
	printf("*\t\t6.ְ�����������	    \t   *\n");
	printf("*\t     ���κ�����°�ctrl+c�˳���     \t   *\n");
	printf("****************************************************\n");
}
void getjudge1(char wh[])
{
	char *p;
	p=wh;
	rewind(stdin);
	printf("\n������ְ���ţ�");
	while(1)
	{
		rewind(stdin);
		gets(wh);
		rewind(stdin);
		if((*p=='1'&&*(p+1)=='0'&&*(p+2)=='0'&&*(p+3)>='0'&&*(p+3)<='9'
		)||(*p=='1'&&*(p+1)=='0'&&*(p+2)=='1'&&*(p+3)>='0'))
		{
			printf("\n�Ϸ����롣\n");
			break;
		}
		else 
			printf("\n\n���Ϸ����룬����������ְ���ţ�");
	}
	return;
}
void allprint1()
{
	FILE*fp;
	int n=0;
	char s1[20],s2[20],s3[20],s4[20],s5[20],s6[20],s7[20];
	if((fp=fopen("E:\\�γ����\\������Ϣ����ϵͳ����\\ְ��������Ϣ.txt","r"))==NULL)
	{
		printf("�ļ������ڻ��ļ��޷��򿪣�\n");
		getch();
		return ;
	}
	fscanf(fp,"%s%s%s%s%s%s%s",s1,s2,s3,s4,s5,s6,s7);
	head_=p1_=(NODE*)malloc(sizeof(NODE));
	p1_->link=NULL;
	printf("\nְ����Ϣ���£�\n");
	printf("\nְ����  ����   �������� �Ա� ���֤����  ְ��   Ȩ��\n");
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
	printf("�ɹ���ȡ%d������",n);
	printf("\n�����������.....\n");
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
	if((fp=fopen("E:\\�γ����\\������Ϣ����ϵͳ����\\ְ��������Ϣ.txt","a+"))==NULL)
	{
		printf("�ļ������ڻ��ļ��޷��򿪣�\n");
		getch();
		system("cls");
		return ;
	}
	printf("\n������Ҫ��ӵ�ְ��������\n");
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
	printf("\n�����%d��ְ����Ϣ��Ϣ������������ء�������",j); 
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
		printf("\n���ݿ���û�п�����Ϣ�������������...");
		getch();
		system("cls");
		return;
	}
	if((fp=fopen("E:\\�γ����\\������Ϣ����ϵͳ����\\ְ��������Ϣ.txt","w"))==NULL)
	{
		printf("\n���ݿ��п�����Ϣ�޷����棬�����������....");
		getch();
		system("cls");
		return;
	}
	fprintf(fp,"%s  %s  %s %s %s  %s	%s","ְ����","����","��������","�Ա�","���֤����","ְ��","Ȩ��");
	p1_=head_;
	while(i<x)
	{
		fprintf(fp,"\n%s	%s	%s	%s	%s	%s	%s",p1_->no,p1_->name,p1_->depart,p1_->sex,p1_->num,p1_->career,p1_->rights);
		p1_=p1_->link;
		i++;
	}
	fclose(fp);
	printf("\n\n���ݿ�����Ϣ�ѱ�����ϣ������������....\n"); 
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
		printf("\n��Ϣ���ݿ�Ϊ�գ������������...\n");
		getch();
		system("cls");
		return ;
	}
	printf("\nְ����Ϣ���£�\n");
	printf("\nְ����  ����  ��������  �Ա�  ���֤���� ְ��   Ȩ��\n");
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
		printf("\nְ����Ϣ���ݿ�Ϊ�գ������������...\n");
		printf("\nְ����Ϣ���£�\n");
		getch();
		system("cls");
		return ;
	}
	printf("\n�����������....");
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
		printf("\n��Ϣ���ݿ�Ϊ�գ������޸ģ������������..."); 
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
		printf("\n�������ְ�������֣�");
		scanf("%s",p1_->name);
		printf("\n�������ְ�����������ţ�");
		scanf("%s",p1_->depart);
		printf("\n�������ְ�����Ա�");
		scanf("%s",p1_->sex);
		printf("\n�������ְ�������֤���룺");
		scanf("%s",p1_->num);
		printf("\n�������ְ����ְ��");
		scanf("%s",p1_->career);
		printf("\n�������ְ����Ȩ�ޣ�");
		scanf("%s",p1_->rights);
		printf("\nһ����Ϣ�޸���ϡ�\n");
	}
	else
	printf("\n�Ҳ�����ְ���Ŀ�����Ϣ��\n");
	getchar();
	printf("\n�����������.....\n");
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
		printf("\n��ϢΪ�գ�����ɾ���������������....");
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
		printf("\nɾ����ϡ�\n");
		x-=1;
	}
	else
	printf("\n�Ҳ�����ְ���Ŀ�����Ϣ��\n");
	printf("\n�����������...");
	getch();
	system("cls");
	menuprint1();
	return ;
}
int input1()
{
	int c;
	printf("���������ѡ��1~6����");
	scanf("%d",&c);
	return c;
}
int input2()
{
	int c;
	printf("******************************����Աϵͳ���˵�***********************************\n");
	printf("*\t\t\t\t\t\t\t\t\t\t*\n");
	printf("*\t\t\t\t1.�����ϰ�ʱ��¼�롣 \t\t\t\t*\n");
	printf("*\t\t\t\t2.�����°�ʱ��¼�롣\t\t\t\t*\n");
	printf("*\t\t\t\t3.�����ϰ�ʱ��¼�롣 \t\t\t\t*\n");
	printf("*\t\t\t\t4.�����°�ʱ��¼�롣 \t\t\t\t*\n");
	printf("*\t\t\t\t5.�����ϰ�ʱ��¼�롣 \t\t\t\t*\n");
	printf("*\t\t\t\t6.�����°�ʱ��¼�롣 \t\t\t\t*\n");
	printf("*\t\t\t\t7.ְ����������������� \t\t\t*\n");
	printf("*\t\t\t\t8.��ѯ���ڼ�¼�� \t\t\t\t*\n");
	printf("*\t\t\t\t9.�޸Ŀ��ڼ�¼�� \t\t\t\t*\n");
	printf("*\t\t\t\t10.ɾ�����ڼ�¼�� \t\t\t\t*\n");
	printf("*\t\t\t\t11.���濼�ڼ�¼�� \t\t\t\t*\n");
	printf("*\t\t\t\t12.�˳������κ�����°�ctrl+c�˳��� \t\t*\n");
	printf("*\t\t\t\t13.���ְ����Ϣ�� \t\t\t\t*\n");
	printf("*\t\t\t\t14.�޸����롣 \t\t\t\t\t*\n");
	printf("*\t\t\t\t\t\t\t\t\t\t*\n");
	printf("*********************************************************************************\n");
	printf("���������ѡ��1~14����");
	scanf("%d",&c);
	rewind(stdin);
	return c;
}
/*���˵�*/
void menuprint2()
{
	printf("******************************����Աϵͳ���˵�***********************************\n");
	printf("*\t\t\t\t\t\t\t\t\t\t*\n");
	printf("*\t\t\t\t1.�����ϰ�ʱ��¼�롣 \t\t\t\t*\n");
	printf("*\t\t\t\t2.�����°�ʱ��¼�롣\t\t\t\t*\n");
	printf("*\t\t\t\t3.�����ϰ�ʱ��¼�롣 \t\t\t\t*\n");
	printf("*\t\t\t\t4.�����°�ʱ��¼�롣 \t\t\t\t*\n");
	printf("*\t\t\t\t5.�����ϰ�ʱ��¼�롣 \t\t\t\t*\n");
	printf("*\t\t\t\t6.�����°�ʱ��¼�롣 \t\t\t\t*\n");
	printf("*\t\t\t\t7.ְ����������������� \t\t\t*\n");
	printf("*\t\t\t\t8.��ѯ���ڼ�¼�� \t\t\t\t*\n");
	printf("*\t\t\t\t9.�޸Ŀ��ڼ�¼�� \t\t\t\t*\n");
	printf("*\t\t\t\t10.ɾ�����ڼ�¼�� \t\t\t\t*\n");
	printf("*\t\t\t\t11.���濼�ڼ�¼�� \t\t\t\t*\n");
	printf("*\t\t\t\t12.�˳������κ�����°�ctrl+c�˳��� \t\t*\n");
	printf("*\t\t\t\t13.���ְ����Ϣ�� \t\t\t\t*\n");
	printf("*\t\t\t\t14.�޸����롣 \t\t\t\t\t*\n");
	printf("*\t\t\t\t\t\t\t\t\t\t*\n");
	printf("*********************************************************************************\n");
}
/*�����ж�*/
void getjudge2(char wh[])
{
	char *p;
	p=wh;
	rewind(stdin);
	printf("\n������ְ���ţ�");
	while(1)
	{
		rewind(stdin);
		gets(wh);
		rewind(stdin);
		if((*p=='1'&&*(p+1)=='0'&&*(p+2)=='0'&&*(p+3)>='0'&&*(p+3)<='9'
		)||(*p=='1'&&*(p+1)=='0'&&*(p+2)=='1'&&*(p+3)>='0'))
		{
			printf("\n�Ϸ����롣\n");
			break;
		}
		else 
			printf("\n\n���Ϸ����룬����������ְ���ţ�");
	}
	return;
}
/*����*/
void putsecret()
{
	int y;
	int i;
	FILE *fp;
	static char str1[7]="abc123";
	char str2[7]="0";
	rewind(stdin);
	if((fp=fopen("E:\\�γ����\\������Ϣ����ϵͳ����\\password","r+"))==NULL)
	{
		printf("�ļ������ڻ��ļ��޷��򿪣�\n");
		getch();
		system("cls");
		return ;
	}
	fread(str1,sizeof(char),7,fp);
	rewind(fp);
	printf("\n���������룺");
	while(1)
	{
		gets(str2);
		y=strcmp(str1,str2);
		if(y!=0)
			printf("\n��������������������룺");
		else
			break;
	}
	if(changesecret()==1)
	{
		printf("�����������룺��ע�⣺���������λ��\n");
		for(i=0;i<6;i++)
		{
			str1[i]=getch();
			printf("*");
		}
		str1[7]='\0';
		flag=0;
		fwrite(str1,sizeof(char),7,fp);
		printf("\n�ѳɹ��޸����룬����������ء�������"); 
		getch();
		system("cls");
	}
	fclose(fp);
	return ;
}
/*�޸�����*/
int changesecret()
{
	if(flag==1)
		return 1;
	else
		return 0;
}
/*�Ӵ��̵���ְ����Ϣ���ڴ�*/
void loadinf()
{
	FILE *fp;
	int n=0;
	if((fp=fopen("E:\\�γ����\\������Ϣ����ϵͳ����\\ְ��������Ϣ.txt","r"))==NULL)
	{
		printf("�ļ������ڻ��ļ��޷��򿪣�\n");
		getch();
		system("cls");
		return ;
	}
	printf("\n\t\t\t\t���뿼����Ϣ����\n");
	printf("\nְ����\t\t�� ��\t\t�ٵ�����\t���˴���\t��������\n");
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
	printf("\n�Ѷ�ȡ%d��ְ����Ϣ��Ϣ������������ء�������",n); 
	getch();
	system("cls");
	writenflag=0;
	if(!fclose(fp))
	{
		printf("Can not close the file!\n\n");
		exit(0);
	}
}
/*���ְ����Ϣ*/
void add2()
{
	FILE*fp;
	char number0[20],name0[20];
	int late0,earlyleave0,notwork0,i=0,j=0;
	if((fp=fopen("E:\\�γ����\\������Ϣ����ϵͳ����\\ְ��������Ϣ.txt","a+))==NULL)
	{
		printf("�ļ������ڻ��ļ��޷��򿪣�\n");
		getch();
		system("cls");
		return ;
	}
	printf("\n������Ҫ��ӵ�ְ��������\n");
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
	printf("\n�����%d��ְ����Ϣ��Ϣ������������ء�������",j); 
	getch();
	system("cls");
	if(!fclose(fp))
	{
		printf("Can not close the file!\n\n");
		exit(0);
	}
}
/*�����ϰ�ʱ��¼��*/
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
		printf("\n��������ĩ�������ϰ�ʱ�䡣\n");
		printf("\n�����������...");
		getch();
		system("cls");
		return;
	}
	if(timeinfo->tm_hour>=12)
	{
		printf("\n���ڲ������磬���ܽ��д˲����������������...");
		getch();
		system("cls");
		return;
	}
	printf ( "\n����ʱ��Ϊ��%4d-%02d-%02d %02d:%02d:%02d\t���ڣ�%d\n",1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_wday);
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
		printf("\n�����ϰࡣ\n");
	/*�ٵ��ж�*/
	if((nowtime.hour==8&&nowtime.minute>=0&&nowtime.minute<=5))
	{
		printf("\n�ϰ�ٵ�\n��");
		while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
		if(strcmp(num,p1->number)==0)
		{
			(p1->late)++;
		}
	}
	/*�����ж�*/
	if((nowtime.hour==8&&nowtime.minute>5)||nowtime.hour>8) 
	{
		printf("\n����һ�Ρ�\n");
		while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
		if(strcmp(num,p1->number)==0)
		{
			(p1->notwork)++;
		}
	}
	writenflag=1;
	printf("\n������Ϣ��¼�룬�����������...");
	getch();
	system("cls");
}
/*�����°�ʱ��¼��*/
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
		printf("\n��������ĩ����������д˲�����\n");
		printf("\n�����������...");
		getch();
		system("cls");
		return;
	}
	printf ( "\n����ʱ��Ϊ��%4d-%02d-%02d %02d:%02d:%02d\t���ڣ�%d\n\n",1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_wday);
	nowtime.year=1900+timeinfo->tm_year;
	nowtime.month=1+timeinfo->tm_mon;
	nowtime.day=timeinfo->tm_mday;
	nowtime.weekday=timeinfo->tm_wday;
	nowtime.hour=timeinfo->tm_hour;
	nowtime.minute=timeinfo->tm_min;
	p1=head;
	rewind(stdin);
	getjudge2(num);
	if(nowtime.hour>11||(nowtime.hour==11&&nowtime.minute>=30)) printf("\n�����°ࡣ\n");
	/*�����ж�*/
	if(nowtime.hour<11||(nowtime.hour==11&&nowtime.minute<=30))
	{
		printf("\n���ˡ�\n");
		while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
		if(strcmp(num,p1->number)==0)
		{
			(p1->earlyleave)++;
		}
	}
	writenflag=1;
	printf("\n������Ϣ��¼�룬�����������...");
	getch();
	system("cls");
}
/*�����ϰ�ʱ��¼��*/
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
		printf("\n��������ĩ�������ϰ�ʱ�䡣\n");
		printf("\n�����������...");
		getch();
		system("cls");
		return;
	}
	if(timeinfo->tm_hour<=12)
	{
		printf("\n���ڲ������磬���ܽ��д˲����������������..."); getch();
		system("cls");
		return;
	}
	printf ( "\n����ʱ��Ϊ��%4d-%02d-%02d %02d:%02d:%02d\t���ڣ�%d\n",1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_wday);
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
	printf("\n�����ϰࡣ\n");
	/*�ٵ��ж�*/
	if(nowtime.hour==14&&nowtime.minute>=0&&nowtime.minute<=5)
	{
		printf("\n�ϰ�ٵ�\n��");
		while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
		if(strcmp(num,p1->number)==0)
		{
			(p1->late)++;
		}
	}
	/*�����ж�*/
	if((nowtime.hour==14&&nowtime.minute>5)||nowtime.hour>14)
	{
		printf("\n����һ�Ρ�\n");
		while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
		if(strcmp(num,p1->number)==0)
		{
			(p1->notwork)++;
		}
	}
	writenflag=1;
	printf("\n������Ϣ��¼�룬�����������...");
	getch();
	system("cls");
}
/*�����°�ʱ��¼��*/
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
		printf("\n��������ĩ����������д˲�����\n");
		printf("\n�����������...");
		getch();
		system("cls");
		return;
	}
	printf ( "\n����ʱ��Ϊ��%4d-%02d-%02d %02d:%02d:%02d\t���ڣ�%d\n\n",1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_wday);
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
	printf("\n�����°ࡣ\n");
	/*�����ж�*/
	if(nowtime.hour<17||(nowtime.hour=17&&nowtime.minute<30))
	{
		printf("\n���ˡ�\n");
		while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
		if(strcmp(num,p1->number)==0)
		{
			(p1->earlyleave)++;
		}
	}
	writenflag=1;
	printf("\n������Ϣ��¼�룬�����������...");
	getch();
	system("cls");
}
/*�����ϰ�ʱ��¼��*/
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
		printf("\n��������ĩ�������ϰ�ʱ�䡣\n");
		printf("\n�����������...");
		getch();
		system("cls");
		return;
	}
	if(timeinfo->tm_hour<=17)
	{
		printf("\n���ڲ������ϣ����ܽ��д˲����������������..."); getch();
		system("cls");
		return;
	}
	printf ( "\n����ʱ��Ϊ��%4d-%02d-%02d %02d:%02d:%02d\t���ڣ�%d\n",1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_wday);
	nowtime.year=1900+timeinfo->tm_year;
	nowtime.month=1+timeinfo->tm_mon;
	nowtime.day=timeinfo->tm_mday;
	nowtime.weekday=timeinfo->tm_wday;
	nowtime.hour=timeinfo->tm_hour;
	nowtime.minute=timeinfo->tm_min;
	p1=head;
	rewind(stdin);
	getjudge2(num);
	if((nowtime.hour==18&&nowtime.minute==0)||nowtime.hour<18) printf("\n�����ϰࡣ\n");
	/*�ٵ��ж�*/
	if((nowtime.hour==18&&nowtime.minute>=0&&nowtime.minute<=5)) 
	{
		printf("\n�ϰ�ٵ�\n��");
		while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
		if(strcmp(num,p1->number)==0)
		{
			(p1->late)++;
		}
	}
	/*�����ж�*/
	if((nowtime.hour==18&&nowtime.minute>5)||nowtime.hour>18) 
	{
		printf("\n����һ�Ρ�\n");
		while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
		if(strcmp(num,p1->number)==0)
		{
			(p1->notwork)++;
		}
	}
	writenflag=1;
	printf("\n������Ϣ��¼�룬�����������...");
	getch();
	system("cls");
}
/*�����°�ʱ��¼��*/
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
		printf("\n��������ĩ����������д˲�����\n");
		printf("\n�����������...");
		getch();
		system("cls");
		return;
	}
	printf ( "\n����ʱ��Ϊ��%4d-%02d-%02d %02d:%02d:%02d\t���ڣ�%d\n\n",1900+timeinfo->tm_year,1+timeinfo->tm_mon,timeinfo->tm_mday,timeinfo->tm_hour,timeinfo->tm_min,timeinfo->tm_sec,timeinfo->tm_wday);
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
	printf("\n�����°ࡣ\n");
	/*�����ж�*/
	if(nowtime.hour<=21)
	{
		printf("\n���ˡ�\n");
		while(strcmp(num,p1->number)!=0&&p1->next!=NULL)
		p1=p1->next;
		if(strcmp(num,p1->number)==0)
		{
			(p1->earlyleave)++;
		}
	}
	writenflag=1;
	printf("\n������Ϣ��¼�룬�����������...");
	getch();
	system("cls");
}
/*����*/
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
		printf("\nְ����Ϣ���ݿ�Ϊ�գ������������...\n");
		getch();
		system("cls");
		return ;
	}
	printf("\n\t\t\t\tְ��������Ϣ���£�\n");
	printf("\nְ����\t\t�� ��\t\t�ٵ�����\t���˴���\t�󹤴���\n");
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
		printf("\nְ����Ϣ���ݿ�Ϊ�գ������������...\n");
		printf("\n\t\t\t\tְ��������Ϣ���£�\n");
		getch();
		system("cls");
		return ;
	}
	printf("\n�����������....");
	getch();
	system("cls");
}
/*��ʾ������Ϣ*/
void allprint2()
{
	rewind(stdin);
	if(head==NULL)
	{
		printf("\n���ݿ���û�п�����Ϣ����Enter �����ء�\n"); 
		getchar();
		system("cls");
	}
	printf("\n\t\t\t\tȫ��������Ϣ����\n");
	printf("\nְ����\t\t�� ��\t\t�ٵ�����\t���˴���\t�󹤴���\n");
	p1=head;
	while(p1!=NULL)
	{
		printf("%s\t\t%s\t\t%5d\t\t%5d\t\t%5d\n",p1->number,p1->name,p1->late,p1->earlyleave,p1->notwork);
		p1=p1->next;
	}
	printf("\n�����������....");
	getch();
	system("cls");
}
/*�޸�*/
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
		printf("\n������Ϣ���ݿ�Ϊ�գ������޸ģ������������..."); 
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
		printf("\n�������ְ�������֣�");
		scanf("%s",p1->name);
		printf("\n�������ְ���ĳٵ��Ĵ�����");
		scanf("%d",&p1->late);
		printf("\n�������ְ�������˵Ĵ�����");
		scanf("%d",&p1->earlyleave);
		printf("\n�������ְ���Ŀ�����������");
		scanf("%d",&p1->notwork);
		printf("\nһ����Ϣ�޸���ϡ�\n");
	}
	else
	printf("\n�Ҳ�����ְ���Ŀ�����Ϣ��\n");
	getchar();
	printf("\n�����������.....\n");
	getch();
	system("cls");
	writenflag=1;
	return ;
}
/*ɾ��*/
void cutoff2()
{
	char num[20];
	putsecret();
	if(head==NULL)
	{
		getchar();
		printf("\n������ϢΪ�գ�����ɾ���������������....");
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
		printf("\nɾ����ϡ�\n");
	}
	else
	printf("\n�Ҳ�����ְ���Ŀ�����Ϣ��\n");
	printf("\n�����������...");
	getch();
	system("cls");
	writenflag=1;
	return ;
}
/*���濼����Ϣ*/
void inforsave2()
{
	FILE *fp;
	if(head==NULL)
	{
		printf("\n���ݿ���û�п�����Ϣ�������������...");
		getch();
		system("cls");
		return;
	}
	if(writenflag==0)
	{
		printf("\n���ݿ��п�����Ϣ�ѱ�����������������...."); 
		getch();
		return;
	}
	if((fp=fopen("E:\\�γ����\\������Ϣ����ϵͳ����\\ְ��������Ϣ.txt","W"))==NULL)
	{
		printf("\n���ݿ��п�����Ϣ�޷����棬�����������...."); getch();
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
	printf("\n\n���ݿ��п�����Ϣ�ѱ�����ϣ������������....\n"); 
	getch();
	system("cls");
	writenflag=0;
	return;
}
/*�˳�*/
void quit()
{
	rewind(stdin);
	printf("\n\n\n\n\t\t\t*************************\n");
	printf("\t\t\t*\tллʹ�ã�\t*\n");
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