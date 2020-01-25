#include <stdio.h>
struct Date
{
	int year;
	int month;
	int day;
}date,date0;
int difdays(struct Date date,struct Date date0)
{
	int sum,sum0,leap,leap0,i,t=0,t0=0; 
	switch(date.month)
 { 
case 1:
	sum=0;
	break;
 case 2:
	 sum=31;
	 break; 
 case 3:
	 sum=59;
	 break; 
 case 4:
	 sum=90;
	 break;
 case 5:
	 sum=120;
	 break; 
 case 6:
	 sum=151;
	 break;
 case 7:
	 sum=181;
	 break; 
 case 8:
	 sum=212;
	 break;
 case 9:
	 sum=243;
	 break; 
 case 10:
	 sum=273;
	 break; 
 case 11:
	 sum=304;
	 break;
 case 12:
	 sum=334;
	 break; 
 default:
	 printf("data error");
	 break; 
 } 
 sum=sum+date.day; 
 if(date.year%400==0||(date.year%4==0&&date.year%100!=0))
 {
	 leap=1;
 } 
 else 
 {
	 leap=0;
 } 
 if(leap==1&&date.month>2)
 { 
	 sum++; 
 } 
 for(i=1900;i<=date.year;i++)
 {
	 if(i%400==0||(i%4==0&&i%100!=0))
	 {
		 t++;
	 }
 }
 	switch(date0.month)
 { 
case 1:
	sum0=0;
	break;
 case 2:
	 sum0=31;
	 break; 
 case 3:
	 sum0=59;
	 break; 
 case 4:
	 sum=90;
	 break;
 case 5:
	 sum0=120;
	 break; 
 case 6:
	 sum=151;
	 break;
 case 7:
	 sum0=181;
	 break; 
 case 8:
	 sum=212;
	 break;
 case 9:
	 sum0=243;
	 break; 
 case 10:
	 sum=273;
	 break; 
 case 11:
	 sum0=304;
	 break;
 case 12:
	 sum=334;
	 break; 
 default:
	 printf("data error");
	 break; 
 } 
 sum0=sum0+date0.day; 
 if(date0.year%400==0||(date0.year%4==0&&date0.year%100!=0))
 {
	 leap0=1;
 } 
 else 
 {
	 leap0=0;
 } 
 if(leap0==1&&date.month>2)
 { 
	 sum0++; 
 } 
 for(i=1900;i<=date.year;i++)
 {
	 if(i%400==0||(i%4==0&&i%100!=0))
	 {
		 t0++;
	 }
 }
 return (366*t+(date.year-1900-t)*365+sum)-(366*t0+(date0.year-1900-t0)*365+sum0);
}
void main()
{
	scanf("%d%d%d",date.year,date.month,date.day);
	scanf("%d%d%d",date0.year,date0.month,date0.day);
	printf("%d\n",difdays(date,date0));
}