#include <stdio.h>
struct Date
{
	int year;
	int month;
	int day;
}date;
int days(struct Date date)
{
	int sum,leap,i,t=0; 
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
 return (366*t+(date.year-1900-t)*365+sum);
}
void main()
{
	scanf("%d%d%d",date.year,date.month,date.day);
	printf("%d\n",days(date));
}