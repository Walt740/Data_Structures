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
    ElemType *base;//��ʼ���Ķ�̬�洢�ռ�
    int front;//ͷָ��
    int rear;//βָ��
};

//��������
void InitQueue(SqQueue &Q);//��ʼ��һ���ն���
void DestroyQueue(SqQueue &Q);//���ٶ���
void ClearQueue(SqQueue &Q);//��ն���
Status QueueEmpty(SqQueue Q);//�ж϶����Ƿ�Ϊ��
Status GetHead(SqQueue Q,ElemType &e);//��e���ض��е�ͷԪ��
Status EnQueue(SqQueue &Q,ElemType e);//����eΪ���е��µ�ͷԪ��
int QueueLength(SqQueue Q);//���ض��еĳ���
Status DeQueue(SqQueue &Q,ElemType &e);//ɾ����ͷԪ�ز���e������ֵ
void QueueTraverse(SqQueue Q,void(*visit)(ElemType));
void print(ElemType e);


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void InitQueue(SqQueue &Q)
{
     //����һ���ն���
     Q.base=(ElemType*)malloc(MAX_QSIZE*sizeof(ElemType));
     if(!Q.base)//�洢����ʧ��
      exit(OVERFLOW);
     Q.front=Q.rear=0;
}
void DestoryQueue(SqQueue &Q)
{    //���ٶ���
     if(Q.base)//����Q����
      free(Q.base);
     Q.base=NULL;
     Q.front=Q.rear=0;
}
void ClearQueue(SqQueue &Q)
{
     //������Q���Ϊ����
     Q.front=Q.rear=0;
}
Status QueueEmpty(SqQueue Q)
{
     //�ж϶����Ƿ�Ϊ��
     if(Q.front==Q.rear)
      return TRUE;
     else return FALSE;
}
Status GetHead(SqQueue Q,ElemType &e)
{
      //������в��գ���e����Q�Ķ�ͷԪ��
     if(Q.front==Q.rear)
      return ERROR;
     e=Q.base[Q.front];//����ͷԪ�ص�ֵ����e
     return OK;
}
Status EnQueue(SqQueue &Q,ElemType e)
{ //����Ԫ��eΪ�����µĶ�βԪ��
 if((Q.rear+1)==Q.front)//������
  return ERROR;
 Q.base[Q.rear]=e;//��e���ڶ�β
 Q.rear=Q.rear+1;//��βָ���1
 return OK;
}
int QueueLength(SqQueue Q)
{ //���ض���Ԫ�صĸ���
 return(Q.rear-Q.front);
}
Status DeQueue(SqQueue &Q,ElemType &e)
{//�����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ
 if(Q.front==Q.rear)return ERROR;
 e=Q.base[Q.front];//����ͷԪ�ص�ֵ����e
 Q.front=Q.front+1;
 return OK;
}
void QueueTraverse(SqQueue Q,void(*visit)(ElemType))
{//�Ӷ�ͷ����β�Զ���Q�е�ÿ��Ԫ�ص��ú���visit()
 int i=Q.front;//i���ָ���ͷԪ��
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

//�������ļ�

void main()
{ int i,j,m,k,n;
ElemType d;
SqQueue Q;
InitQueue(Q);
printf("��������е�Ԫ��");
for(i=1;i<=MAX_QSIZE;i++)
{
  scanf("%d",&d);
  if(d==0)break;
  EnQueue(Q,d);
}
printf("����Ϊ:");
QueueTraverse(Q,print);
printf("�ж϶��г���:%d\n",QueueLength(Q));
k=QueueLength(Q);
printf("����%d���ɶ�ͷɾ��Ԫ�أ��ɶ�β����Ԫ��:\n",k);
for(m=1;m<=k;m++)
{  DeQueue(Q,d);//ɾ����ͷԪ�أ���ֵ����d
   printf("ɾ����Ԫ����%d,������Ҫ�����Ԫ��:",d);
   scanf("%d",&d);
   EnQueue(Q,d);//��d�������
}
printf("�¶���Ϊ:");
QueueTraverse(Q,print);
n=GetHead(Q,d);
if(n)
printf("��ȡ��ͷԪ�ص�ֵ%d\n",d);
printf("��ն���\n");
ClearQueue(Q);
printf("��ն��к�,�����Ƿ�Ϊ��n=%d(1,Ϊ��;0,��Ϊ��)",QueueEmpty(Q));
}
