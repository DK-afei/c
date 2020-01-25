#include  <stdio.h>
int fun(char  *s)
{
	int  n=0, flag=0;
  while(*s!='\0')
  {
	  if(*s!=' ' && flag==0) 
  {

    n++;  
	flag=1;
  }

    if (*s==' ')  
		flag=0;

		s++ ;
  }
  return  n;
}
main()
{
  char  str[1024];  
  int  n;
  printf("\nEnter a line text:\n");  
  gets(str);
  n=fun(str);
  printf("\nThere are %d words in this text.\n\n",n);
}
