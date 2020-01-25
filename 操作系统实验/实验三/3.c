#include <stdlib.h>
#include <stdio.h>
#define N 12
#define B 3
typedef struct flag{
    int fblock[B];//记录各个物理块时间戳
    int pflag;//指针
}FLAG;

//全局变量（共享）
int page[N]={1,2,3,4,1,2,5,1,2,3,4,5};//页面走向
int block[B]={0};//物理块3个，其数值是页号
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
	printf("初始页面序列为:\n");
	for(i=0;i<N;i++)
		printf("%d ",page[i]);
	printf("\n");
	printf("内存块数为:\n");
	printf("%d\n",B);
	printf("LRU（Least Recently Used）置换算法:\n");
	lru();
	printf("该算法的缺页数和缺页率分别是:\n");
	printf("%d,%f\n",C,(float)C/N);
	return 0;
}

void lru(){
    int i;
    int getIndex;
    int maxOfIndex;
    for(i=0;i<N;i++){
        if(i<B){//前三个页
            block[i]=page[i];
            myflag.fblock[i]=B-i;
			printf("缺页：%d\n",page[i]);
			C++;
        }
        else{
            getIndex=inBlock(page[i]);
            if(getIndex==-1){//缺页
                maxOfIndex=findMaxTime();
                block[maxOfIndex]=page[i];
                myflag.pflag=maxOfIndex;
				printf("缺页：%d\n",page[i]);
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

//给其他加时间戳
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

//在物理块中就返回索引，否则返回-1
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

//打印一组
void disPlay(){
	int i;
    for(i=0;i<B;i++){
        printf("%d\t",block[i]);
    }
    printf("\n");
}

//找到时间戳最大的物理块下标
int findMaxTime(){
    int i=0;
    int index=0;//默认第一个时间戳最大
    for(i=1;i<B;i++){
        if(myflag.fblock[index]<myflag.fblock[i])
            index=i;
    }
	return index;
}