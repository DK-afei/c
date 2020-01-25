
#include <stdio.h>
 void main()
 {
	char ch1,ch2,ch3,ch4,ch5;
	scanf("%c%c%c%c%c",&ch1,&ch2,&ch3,&ch4,&ch5);
		if (ch1+4>'z'&&ch1+4<'a')
			ch1='a'+ch1+4-'z';
		else if(ch1+4>'Z'&&ch1+4<'A')
			ch1='A'+ch1+4-'Z';
		else
			ch1=ch1+4;
			if (ch2+4>'z'&&ch2+4<'a')
			ch2='a'+ch2+4-'z';
		else if(ch2+4>'Z'&&ch2+4<'A')
			ch2='A'+ch2+4-'Z';
		else
			ch2=ch2+4;
		if (ch3+4>'z'&&ch3+4<'a')
			ch3='a'+ch3+4-'z';
		else if(ch3+4>'Z'&&ch3+4<'A')
			ch3='A'+ch3+4-'Z';
		else
			ch3=ch3+4;
			if (ch4+4>'z'&&ch4+4<'a')
			ch4='a'+ch4+4-'z';
		else if(ch4+4>'Z'&&ch4+4<'A')
			ch4='A'+ch4+4-'Z';
		else
			ch4=ch4+4;
			if (ch5+4>'z'&&ch5+4<'a')
			ch5='a'+ch5+4-'z';
		else if(ch5+4>'Z'&&ch5+4<'A')
			ch5='A'+ch5+4-'Z';
		else
			ch5=ch5+4;
		printf("%c%c%c%c%c\n",ch1,ch2,ch3,ch4,ch5);
 }
