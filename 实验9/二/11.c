#include  <stdio.h>
#include  <string.h>
#define   N   5
#define   M   8
int fun(char  (*ss)[M],char  *t)
{  int  i;
   for(i=0; i< N; i++)

     if(strcmp(ss[i],t)==0 ) return  i;
   return 0;
}
main()
{ char  ch[N][M]={"if","while","switch","int","for"},t[M];
  int  n,i;
  printf("\nThe original string\n\n");
  for(i=0;i<N;i++)puts(ch[i]);  printf("\n");
  printf("\nEnter a string for search:  ");  gets(t);
  n=fun(ch,t);

  if(n==  0)  printf("\nDon't found!\n");
  else   printf("\nThe position is  %d .\n",n);
}
