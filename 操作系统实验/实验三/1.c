#include <stdio.h>
#include <stdlib.h>
#define N 12
#define B 3
int page[N]={1,2,3,4,1,2,5,1,2,3,4,5};//页面序列号
int block[B]={0};//物理块3个，其数值是页号
int C=0;
typedef struct FLAG {
    int flags[B];
    int counts;
} FLAG;

void opt(int page[],int block[]);
int inBlock(int which);
int findFar(int next);
void Replace(int index,int value);
void disPlay();

int main(void){
	int i;
	printf("初始页面序列为:\n");
	for(i=0;i<N;i++)
		printf("%d ",page[i]);
	printf("\n");
	printf("内存块数为:\n");
	printf("%d\n",B);
		  printf("最佳（Optimal）置换算法:\n");
		  opt(page,block);
		  printf("该算法的缺页数和缺页率分别:\n");
		  printf("%d,%f\n",C,(float)C/N);
		  return 0;
}

void opt(int page[],int block[]){
    int getIndex;
	int i;
    for(i=0;i<N;i++){
        if(i<3){//前3页号#短缺#进队列
            block[i]=page[i];
            printf("缺页：NULL->%d\n",page[i]);
			C++;
        }
        else {
            if(i==3){
                disPlay();
				
            }
            if(inBlock(page[i])!=-1){//下一个页面if在物理块中返回index并跳过,反-1
                disPlay();
				
                continue;
            }
            getIndex=findFar(i+1);//从下一个页号，找到最远出现的页面,替换的下标
            if(getIndex==-1){
				printf("error,not replace obj!\t");
            }
            else{
                Replace(getIndex,page[i]);//由下标找到上一组替换目标，用第二参数替换
				C++;
                disPlay();
				
            }
        }
    }
	return;
}

//替换block中的物理块
void Replace(int index,int value){
    printf("缺页：%d->%d\n",block[index],value);
    block[index]=value;
	return;
}


//找到最远出现的页面
int findFar(int next){
    int index=-1;//error，默认返回不存在的索引
	int stop;
    FLAG myflag;
    myflag.flags[0]=0;
    myflag.flags[1]=0;
    myflag.flags[2]=0;
    myflag.counts=0;
    stop = N-next;
    while(stop--){
        index=inBlock(page[next++]);
        if(index!=-1){
            myflag.flags[index]=1;
            myflag.counts++;
        }
        else if(myflag.counts==B-1){//有2个不缺值时
            break;
        }
    }
    for(index=0;index<B;index++){
        if(myflag.flags[index]==0)
            break;
    }
	return index;
}


//下一个页面if在物理块中返回index,反-1
int inBlock(int which){
    int i=0;
    for(i=0;i<B;i++){
        if(block[i]==which)
            return i;
    }
	return -1;
}

//打印一元组
void disPlay(){
    int i=0;
    while(i<B){
        printf("%d\t",block[i++]);
    }
    printf("\n");
	return;
}