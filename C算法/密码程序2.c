#include<stdio.h>
int main()
{
char mima[16];
int i=0;
printf("请输入要加密的字符串,按回车结束！\n");
gets(mima);
while(mima[i]!='\0')
{
if(mima[i]>='w'&&mima[i]<='z'||mima[i]>='W'&&mima[i]<='Z')mima[i]=mima[i]-22;
else mima[i]=mima[i]+4;
i++;
}
printf("加密之后的密码是:");
puts(mima);
return 0;
}
