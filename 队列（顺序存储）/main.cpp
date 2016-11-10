#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
#define NULL 0
#define OK 1
#define OVERFLOW 0
#define ERROR 0
#define MAX_QSIZE 10

typedef int ElemType;
typedef int Status;

struct SqQueue
{
    ElemType *base;//初始化的动态存储空间
    int front;//头指针
    int rear;//尾指针
};

//函数声明
void InitQueue(SqQueue &Q);//初始化一个空队列
void DestroyQueue(SqQueue &Q);//销毁队列
void ClearQueue(SqQueue &Q);//清空队列
Status QueueEmpty(SqQueue Q);//判断队列是否为空
Status GetHead(SqQueue Q,ElemType &e);//用e返回队列的头元素
Status EnQueue(SqQueue &Q,ElemType e);//插入e为队列的新的头元素
int QueueLength(SqQueue Q);//返回队列的长度
Status DeQueue(SqQueue &Q,ElemType &e);//删除队头元素并用e返回其值
void QueueTraverse(SqQueue Q,void(*visit)(ElemType));
void print(ElemType e);


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InitQueue(SqQueue &Q)
{
     //构造一个空队列
     Q.base=(ElemType*)malloc(MAX_QSIZE*sizeof(ElemType));
     if(!Q.base)//存储分配失败
      exit(OVERFLOW);
     Q.front=Q.rear=0;
}
void DestoryQueue(SqQueue &Q)
{    //销毁队列
     if(Q.base)//队列Q存在
      free(Q.base);
     Q.base=NULL;
     Q.front=Q.rear=0;
}
void ClearQueue(SqQueue &Q)
{
     //将队列Q清空为队列
     Q.front=Q.rear=0;
}
Status QueueEmpty(SqQueue Q)
{
     //判断队列是否为空
     if(Q.front==Q.rear)
      return TRUE;
     else return FALSE;
}
Status GetHead(SqQueue Q,ElemType &e)
{
      //如果队列不空，用e返回Q的队头元素
     if(Q.front==Q.rear)
      return ERROR;
     e=Q.base[Q.front];//将队头元素的值赋给e
     return OK;
}
Status EnQueue(SqQueue &Q,ElemType e)
{ //插入元素e为队列新的队尾元素
 if((Q.rear+1)==Q.front)//队列满
  return ERROR;
 Q.base[Q.rear]=e;//将e插在队尾
 Q.rear=Q.rear+1;//队尾指针加1
 return OK;
}
int QueueLength(SqQueue Q)
{ //返回队列元素的个数
 return(Q.rear-Q.front);
}
Status DeQueue(SqQueue &Q,ElemType &e)
{//若队列不空，则删除Q的队头元素，有e返回其值
 if(Q.front==Q.rear)return ERROR;
 e=Q.base[Q.front];//将队头元素的值赋给e
 Q.front=Q.front+1;
 return OK;
}
void QueueTraverse(SqQueue Q,void(*visit)(ElemType))
{//从队头到队尾对队列Q中的每个元素调用函数visit()
 int i=Q.front;//i最初指向队头元素
 while(i!=Q.rear)
 {  visit(Q.base[i]);
    i=i+1;
    }
 printf("\n");
}
void print(ElemType e)
{ printf("%2d",e);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//主函数文件

void main()
{ int i,j,m,k,n;
ElemType d;
SqQueue Q;
InitQueue(Q);
printf("输入队列中的元素");
for(i=1;i<=MAX_QSIZE;i++)
{
  scanf("%d",&d);
  if(d==0)break;
  EnQueue(Q,d);
}
printf("队列为:");
QueueTraverse(Q,print);
printf("判断队列长度:%d\n",QueueLength(Q));
k=QueueLength(Q);
printf("连续%d次由队头删除元素，由队尾插入元素:\n",k);
for(m=1;m<=k;m++)
{  DeQueue(Q,d);//删除队头元素，其值赋给d
   printf("删除的元素是%d,请输入要插入的元素:",d);
   scanf("%d",&d);
   EnQueue(Q,d);//将d插入队列
}
printf("新队列为:");
QueueTraverse(Q,print);
n=GetHead(Q,d);
if(n)
printf("提取队头元素的值%d\n",d);
printf("清空队列\n");
ClearQueue(Q);
printf("清空队列后,队列是否为空n=%d(1,为空;0,不为空)",QueueEmpty(Q));
}
