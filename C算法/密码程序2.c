#include<stdio.h>
int main()
{
char mima[16];
int i=0;
printf("������Ҫ���ܵ��ַ���,���س�������\n");
gets(mima);
while(mima[i]!='\0')
{
if(mima[i]>='w'&&mima[i]<='z'||mima[i]>='W'&&mima[i]<='Z')mima[i]=mima[i]-22;
else mima[i]=mima[i]+4;
i++;
}
printf("����֮���������:");
puts(mima);
return 0;
}
