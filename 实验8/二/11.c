#include <stdio.h>

void sort(int*array,int len)
{
    int i,j;
    int t;
    for(i=0;i<len-i-1;i++)
    {
        for(j=0;j<i-1;j++)
        {
            if((*(array+j))>(*(array+j+1)))
            {
                t=*(array+j);
                *(array+j)=*(array+j+1);
                *(array+j+1)=t;
            }
            
        }
    }
    for(i=0;i<len;i++)
   printf("%4d",*(array+i));
}
int main()
{
   int a[1024];
   int len,i;
   printf("������Ԫ�ظ�����\n");
   scanf("%d",&len);
   printf("������Ԫ�أ�");
   for(i=0;i<len;i++)
   scanf("%d",&a[i]);
   sort(a,len);
   return 0;
}
