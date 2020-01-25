#include <stdio.h>
#include <stdlib.h>
#define N 12
#define B 3
int page[N]={1,2,3,4,1,2,5,1,2,3,4,5};//ҳ�����к�
int block[B]={0};//�����3��������ֵ��ҳ��
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
	printf("��ʼҳ������Ϊ:\n");
	for(i=0;i<N;i++)
		printf("%d ",page[i]);
	printf("\n");
	printf("�ڴ����Ϊ:\n");
	printf("%d\n",B);
		  printf("��ѣ�Optimal���û��㷨:\n");
		  opt(page,block);
		  printf("���㷨��ȱҳ����ȱҳ�ʷֱ�:\n");
		  printf("%d,%f\n",C,(float)C/N);
		  return 0;
}

void opt(int page[],int block[]){
    int getIndex;
	int i;
    for(i=0;i<N;i++){
        if(i<3){//ǰ3ҳ��#��ȱ#������
            block[i]=page[i];
            printf("ȱҳ��NULL->%d\n",page[i]);
			C++;
        }
        else {
            if(i==3){
                disPlay();
				
            }
            if(inBlock(page[i])!=-1){//��һ��ҳ��if��������з���index������,��-1
                disPlay();
				
                continue;
            }
            getIndex=findFar(i+1);//����һ��ҳ�ţ��ҵ���Զ���ֵ�ҳ��,�滻���±�
            if(getIndex==-1){
				printf("error,not replace obj!\t");
            }
            else{
                Replace(getIndex,page[i]);//���±��ҵ���һ���滻Ŀ�꣬�õڶ������滻
				C++;
                disPlay();
				
            }
        }
    }
	return;
}

//�滻block�е������
void Replace(int index,int value){
    printf("ȱҳ��%d->%d\n",block[index],value);
    block[index]=value;
	return;
}


//�ҵ���Զ���ֵ�ҳ��
int findFar(int next){
    int index=-1;//error��Ĭ�Ϸ��ز����ڵ�����
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
        else if(myflag.counts==B-1){//��2����ȱֵʱ
            break;
        }
    }
    for(index=0;index<B;index++){
        if(myflag.flags[index]==0)
            break;
    }
	return index;
}


//��һ��ҳ��if��������з���index,��-1
int inBlock(int which){
    int i=0;
    for(i=0;i<B;i++){
        if(block[i]==which)
            return i;
    }
	return -1;
}

//��ӡһԪ��
void disPlay(){
    int i=0;
    while(i<B){
        printf("%d\t",block[i++]);
    }
    printf("\n");
	return;
}