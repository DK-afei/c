#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
main( )
{
	int p=-1;
	int n=0;
	char command[20];
	while(1){
		if(n==1)
		while((p=fork())==-1);
		if(p==0)
		{
			system(command);
			n=0;
			p=-1;
		}
		else
		{
			while(1){
			printf("$$$:");
			fflush(stdin);
			gets(command);
			n=1;
			if(n==1)
			break;}
		}
	}
	return 0;
}
