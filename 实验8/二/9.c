#include <stdio.h>
int isprime(int *data,int *prime,int len)
{
    int i,j,t,num=0;
    for(i=0;i<len;i++)
    {
		t=0;
        for(j=2;j<*(data+i);j++)
        {
            if(*(data+i)%j==0)
            {
              t++;   
            }        
        }
        if(t==0)
		{
		 *(prime+num)=*(data+i);   
		 num++;
		}
    }
    return num;
    
}
int main()
{
	int data[1024],prime[1024];
    int i,n;
    printf("������Ԫ�صĸ�����\n");
    scanf("%d",&n);
    printf("������Ԫ�أ�");
    for(i=0;i<n;i++)
    {
            scanf("%d",&data[i]);
    }
    printf("��������Ϊ��%d\n",isprime(data,prime,n));
    printf("��Щ����Ϊ��");
    for(i=0;i<isprime(data,prime,n);i++)
    {
            printf("\t%d",*(prime+i));
    }
	printf("\n");
	return 0;
}