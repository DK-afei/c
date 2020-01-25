#include <stdlib.h>
#include <stdio.h>
#define N 12
#define B 3
typedef struct flag{
    int fblock[B];//��¼���������ʱ���
    int pflag;//ָ��
}FLAG;

//ȫ�ֱ���������
int page[N]={1,2,3,4,1,2,5,1,2,3,4,5};//ҳ������
int block[B]={0};//�����3��������ֵ��ҳ��
int C=0;
FLAG myflag={{0},0};

void lru();
int inBlock(int value);
void disPlay();
int findMaxTime();
void addStamp();


int main()
{
	int i;
	printf("��ʼҳ������Ϊ:\n");
	for(i=0;i<N;i++)
		printf("%d ",page[i]);
	printf("\n");
	printf("�ڴ����Ϊ:\n");
	printf("%d\n",B);
	printf("LRU��Least Recently Used���û��㷨:\n");
	lru();
	printf("���㷨��ȱҳ����ȱҳ�ʷֱ���:\n");
	printf("%d,%f\n",C,(float)C/N);
	return 0;
}

void lru(){
    int i;
    int getIndex;
    int maxOfIndex;
    for(i=0;i<N;i++){
        if(i<B){//ǰ����ҳ
            block[i]=page[i];
            myflag.fblock[i]=B-i;
			printf("ȱҳ��%d\n",page[i]);
			C++;
        }
        else{
            getIndex=inBlock(page[i]);
            if(getIndex==-1){//ȱҳ
                maxOfIndex=findMaxTime();
                block[maxOfIndex]=page[i];
                myflag.pflag=maxOfIndex;
				printf("ȱҳ��%d\n",page[i]);
				C++;
            }
            else{
                myflag.pflag=getIndex;
            }
            addStamp();
        }
        disPlay();
    }
}

//��������ʱ���
void addStamp(){
    int i=0;
    while(i<B){
        if(i!=myflag.pflag)
            myflag.fblock[i]++;
        else
            myflag.fblock[i]=0;
        i++;
    }
}

//��������оͷ������������򷵻�-1
int inBlock(int value){
    int index=-1;
    int i=0;
    while(i<B){
        if(block[i]==value){
            index=i;
            break;
        }
        i++;
    }
	return index;
}

//��ӡһ��
void disPlay(){
	int i;
    for(i=0;i<B;i++){
        printf("%d\t",block[i]);
    }
    printf("\n");
}

//�ҵ�ʱ�������������±�
int findMaxTime(){
    int i=0;
    int index=0;//Ĭ�ϵ�һ��ʱ������
    for(i=1;i<B;i++){
        if(myflag.fblock[index]<myflag.fblock[i])
            index=i;
    }
	return index;
}