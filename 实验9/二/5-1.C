#include <stdio.h>
#define N 5
void delch(char*string,char ch)
{
    int i,j;
    char b[N];
    for(i=0;i<N;i++)
    {
        
        if(*(string+i)!=ch)
        {
        b[i]=*(string+i);
        }
        
    }
    for(i=0;i<N;i++)
    {
     
     
     *(string+i)=b[i];
    }
}

int main()
{
   char string[1024];
   int i;
   char ch;
   for(i=0;i<N+1;i++)
   scanf("%c",&string[i]);
   fflush(stdin);
   printf("������Ҫɾ�����ַ�:");
   scanf("%c",&ch);
   delch(string,ch);
   printf("ʣ����ЧԪ��Ϊ:");
   for(i=0;i<N;i++)
   printf("%c",string[i]);
   
   return 0;
}
