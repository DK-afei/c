/*贪吃蛇*/
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<stdlib.h>
int head=3 ,tail=0;
int main()
{
int i,j,k=0;
int zuobiao[2][80];
long start;
int direction=77;
int gamespeed;
int timeover;
int change(char qipan[20][80],int zuobiao[2][80],char direction);
zuobiao[0][tail]=1;zuobiao[1][tail]=1;zuobiao[0][1]=1;zuobiao[1][1]=2;zuobiao[0][2]=1;zuobiao[1][2]=3;zuobiao[0][head]=1;zuobiao[1][head]=4;
/*处理棋盘*/
char qipan[20][80];//定义棋盘
for(i=0;i<20;i++)
for(j=0;j<80;j++)
qipan[i][j]=' ';//初始化棋盘
for(i=0;i<80;i++)
qipan[0][i]='_';
for(i=0;i<20;i++)
qipan[i][0]='|';
for(i=0;i<20;i++)
qipan[i][79]='|';
for(i=0;i<80;i++)
qipan[19][i]='_';
qipan[1][1]=qipan[1][2]=qipan[1][3]='*';//初始化蛇的位置
qipan[1][4]='#';
printf("This is a game of a SNAKE.\nGOOD LUCK TO YOU !\n");
printf("Input your game speed,please.(e.g.300)\n");
scanf("%d",&gamespeed);
while(direction!='q')
{
system("cls");
for(i=0;i<20;i++)//打印出棋盘
for(j=0;j<80;j++)
printf("%c",qipan[i][j]);
timeover=1;
start=clock();
while(!kbhit()&&(timeover=clock()-start<=gamespeed));
if(timeover)
{
getch();
direction=getch();
}
else
direction=direction;
if(!(direction==72||direction==80||direction==75||direction==77))
{
return 0;
system("cls");
printf("GAME OVER!\n");
}
if(!change(qipan,zuobiao,direction))
{
direction='q';
system("cls");
printf("GAME OVER!\n");
}
}
return 0;
}
int change(char qipan[20][80],int zuobiao[2][80],char direction)
{
int x,y;
if(direction==72)
x=zuobiao[0][head]-1;y=zuobiao[1][head];
if(direction==80)
x=zuobiao[0][head]+1;y=zuobiao[1][head];
if(direction==75)
x=zuobiao[0][head];y=zuobiao[0][head]-1;
if(direction==77)
x=zuobiao[0][head];y=zuobiao[1][head]+1;
if(x==0||x==18||y==78||y==0)
return 0;
if(qipan[x][y]!=' ')
return 0;
qipan[zuobiao[0][tail]][zuobiao[1][tail]]=' ';
tail=(tail+1)%80;
qipan[zuobiao[0][head]][zuobiao[1][head]]='*';
head=(head+1)%80;
zuobiao[0][head]=x;
zuobiao[1][head]=y;
qipan[zuobiao[0][head]][zuobiao[1][head]]='#';
return 1;
}
