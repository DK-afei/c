#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define N 100
#define S 20
struct words//����һ��words �ṹ��
{
	char e[S];//���Ӣ�ﵥ��
	char c[S];//��Ӧ�ĺ��﷭��
	int score;//ÿ�����ʵ÷�
}str[N],str2[N];//����ṹ�����
int fenshu=0; //ȫ�ֱ���������ͳ�Ʒ���
int count1=0;//ȫ�ֱ���������ͳ�Ʋ��Ե��ʸ���
static int p=0;//ȫ�ֱ���������ͳ�Ƶ��ʸ���
int z=0;//�û�ָ�����뵥����
void showmenu();//��ʾ�˵�
void cunchu();//�洢
void tianjia();//�������
void shuchu();//����չʾ
void fanyi1();//Ӣ�뺺
void fanyi2();//����Ӣ
void chengji();//��ѯ�ɼ�
void  tuichu();//�˳�ϵͳ
//��ʾ�˵�
void showmenu()
{
	printf("\n");
	printf("\t*****************************\n"); 
	printf("\t**  ��ӭʹ�ñ�����ϵͳ!    **\n");
	printf("\t**  ����ߣ�xxx            **\n");
	printf("\t**  �༶��666   ѧ�ţ�666  **\n"); 
	printf("\t*****************************\n"); 
	printf("\t**0����ʾ�˵� 1���������  **\n");  
	printf("\t** 2������չʾ   3��Ӣ�뺺 **\n"); 
	printf("\t** 4������Ӣ    5���ɼ���ѯ**\n");
	printf("\t** 6���洢  7���˳�ϵͳ    **\n");
	printf("\t*****************************\n"); 
	printf(" ��ѡ������Ҫ�Ĳ������<1-7>,���س�����:");
}
//�洢
void cunchu()
{
	FILE*fp;
	int i=0;
	if((fp=fopen("E:\\�γ����\\�����ʿ���\\words.txt","w"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	fprintf(fp,"%s","����	Ӣ��	score");
	for(i=0;i<p;i++)
	{
		fprintf(fp,"\n%s	%s	%d",str2[i].e,str2[i].c,str2[i].score);
	}
	fclose(fp);
	printf("\n����ɹ�\n");
	printf("\n\n�����������.....\n");
	getch();
	system("cls");
	showmenu();
	return;
}
//�������
void tianjia()
{
	FILE*fp;
	char ch;
	if((fp=fopen("E:\\�γ����\\�����ʿ���\\words.txt","a"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	do
	{
		printf("¼��ʿ�!\n");
		printf("������Ӣ�ﵥ��:\n");
		scanf("%s",str[p].e);
		printf("\n��������Ӧ�����ķ���:\n");
		scanf("%s",str[p].c);
		fprintf(fp,"\n%s	%s	%d",str[p].e,str[p].c,str[p].score);
		p++;
		printf("%s�ѱ��棬�Ƿ����¼�룿y/n!\n",str[p].e); 
		scanf("%s",&ch);
	}while(ch=='y');
	fclose(fp);
	printf("\n\n�����������.....\n");
	getch();
	system("cls");
	showmenu();
	return;
}
//����չʾ
void shuchu()
{
	FILE*fp;
	int i=0;
	char s1[10],s2[10],s3[10];
	if((fp=fopen("E:\\�γ����\\�����ʿ���\\words.txt","r"))==NULL)
	{
		printf("Can't open the file!\n");
		return;
	}
	fscanf(fp,"%s%s%s",s1,s2,s3);
	printf("����ʿ������еĵ���!\n");
	while(!feof(fp))
	{
		fscanf(fp,"%s%s%d",str2[i].e,str2[i].c,&str2[i].score);
		printf("Ӣ�ĵ�����: %s",str2[i].e);
		printf("\n��Ӧ��������˼��: %s \n",str2[i].c);
		printf("�õ��ʵ�ǰ�÷֣�%d\n",str2[i].score);
		i++;
		p++;
	}
	printf("�ʿ����е���������!\n");
	fclose(fp);
	printf("\n\n�����������.....\n");
	getch();
	system("cls");
	showmenu();
}
//Ӣ�뺺
void fanyi1()
{
	int i=0;
	char f[S];
	char over[N]="jieshu";
	FILE*fp;
	char s1[10],s2[10],s3[10];
	if((fp=fopen("E:\\�γ����\\�����ʿ���\\words.txt","r"))==NULL)
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
	printf("������Ҫ���ĵ�����:\n");
	scanf("%d",&z);
	printf("����������Ӣ�ĵ��ʵķ��룬ϣ����������ʱ������ jieshu \n"); 
	while(i<z&&strcmp(f,over)!=0)//�û�������jieshu ���Ҵʿ��е���û��ȫ�����ʱִ��ѭ��
	{
		printf("%s ",str2[i].e);
		scanf("%s",&f);
		if(strcmp(str2[i].c,f)==0)
		{
			printf("��ȷ��\n");
			fenshu+=1; //���ڼ������
			str2[i].score++;
		}
		else
		{
			printf("���ź�����ȷ�ķ���Ϊ��");
			printf("%s\n",str2[i].c);
		}
		count1++;
		i++;
	}
	cunchu();
	printf("\n\n�����������.....\n");
	getch();
	system("cls");
	showmenu();
	return;
}
//����Ӣ
void fanyi2()
{
	int i=0;
	char f[S];
	char over[N]="jieshu";
	FILE*fp;
	char s1[10],s2[10],s3[10];
	if((fp=fopen("E:\\�γ����\\�����ʿ���\\words.txt","r"))==NULL)
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
	printf("������Ҫ���ĵ�����:\n");
	scanf("%d",&z);
	printf("����������Ӣ�ĵ��ʵķ��룬ϣ����������ʱ������ jieshu \n"); 
	while(i<z&&strcmp(f,over)!=0)
	{
		printf("%s",str2[i].c);
		scanf("%s",&f);
		if(strcmp(str2[i].e,f)==0)
		{
			printf("��ȷ��\n");
			fenshu+=1;
			str2[i].score++;
		}
		else
		{
			printf("���ź�����ȷ�ķ���Ϊ��");
			printf("%s\n",str2[i].e);
		}
		count1++;
		i++;
	}
	cunchu();
	printf("\n\n�����������.....\n");
	getch();
	system("cls");
	showmenu();
	return;
}
//��ѯ�ɼ�
void chengji()
{
	printf("���β��Եĳɼ���:\n");
	printf("�ܹ�:%d��\n",count1);
	printf("��ȷ:%d��\n",fenshu);
	printf("���÷�Ϊ(���һ����1�֣����һ��0��) ��%d \n",fenshu);
	printf("\n\n�����������.....\n");
	getch();
	system("cls");
	showmenu();
	return;
}
//�˳�ϵͳ
void tuichu()
{
	char ch;
	printf("�Ƿ��˳�ϵͳ����y��\n");
	scanf("%c",&ch);
	if(ch=='y')
	{
		printf("�˳��ɹ���\n");
		exit(0);
	}
	else
	{
		printf("�˳�ʧ�ܣ�");
		printf("\n\n�����������.....\n");
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
		{//ִ����Ӧ�ĺ�����ʵ����Ӧ�Ĺ���
			case 0:showmenu();break;
			case 1:tianjia();break;
			case 2:shuchu();break;
			case 3:fanyi1();break; 
			case 4:fanyi2();break; 
			case 5:chengji();break; 
			case 6:cunchu();break;
				//�˳�ϵͳ�Ĳ���
			case 7:tuichu();break;
			default :
				{
					printf("�������˴���Ĳ������޷�ִ��!\n");
					printf("\n\n�����������.....\n");
					getch();
					system("cls");
					showmenu();
					break;
				}
		}
	}
	return 0;
}