#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef int Status;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

#define OK 1
#define TURE 1
#define FALSE -1
#define OVERFLOW -2
#define INFEASIBLE -1

//˳��ջ�ṹ��
typedef struct Stack
{
    ElemType *base;
    int *top;      //ջ��ָ�룬ʼ��ָ���ջ�Ķ���
    int stacksize; //��ջ�Ĵ�С

}SqStack;

int InitStack(SqStack *S); //��ʼ����ջ
void Push_L(SqStack *S,int e); //ѹջ
int Pop_L(SqStack *S,int* e); //��ջ
void Traversal_L(SqStack S); //������ջ
int StackLength_L(SqStack S);//ջ��
void ClearStack_L(SqStack *S); //��ն�ջ���ݣ�����ͷ���
void StackEmpty_L(SqStack S); //�ж�ջ�Ƿ�Ϊ��
void DestroyStack_L(SqStack *S); //���ٶ�ջ
void GetTop_L(SqStack S,int *e); //��ȡջ��Ԫ��

int main()
{
    printf("*  1������һ������ջ          *\n");
	printf("*  2��������ջ��Ԫ��          *\n");
	printf("*  3�������ջ��Ԫ��          *\n");
	printf("*  4������ջ�ĳ���            *\n");
	printf("*  5������ջ��Ԫ��            *\n");
	printf("*  6��ɾ����ջ��Ԫ��          *\n");
	printf("*  7������Ѵ��ڵ���ջ        *\n");
	printf("*  8���ж���ջ�Ƿ�Ϊ��        *\n");
	printf("*  0��������ջ                *\n");

    int n,k;
	SqStack S; //��ջָ��

    for(n=0;n<15;n++)
    {
        printf("��ѡ��0-8:  ");
        scanf("%d",&k);
        if(k==0)
        {
            DestroyStack_L(&S);
            n=15;
        }
        if(k==1)
        {
            if(InitStack(&S))
                printf("�����ɹ�!\n");
            else
                printf("����ʧ��!\n");
        }
        if(k==2)
        {
            int a;
            printf("����ջS��Ԫ��Ϊ: ");
            scanf("%d",&a);
            Push_L(&S,a);
            Traversal_L(S);
        }
        if(k==3)
            Traversal_L(S);

        if(k==4) printf("ջ�ĳ���Ϊ:%d \n ",StackLength_L(S));
        if(k==5) {int c;GetTop_L(S,&c);}
        if(k==6)
        {
            int b;
            if((S.top == S.base))
            {
                printf("ջΪ��!\n");
                break;
            }
            if(Pop_L(&S,&b))
            {
                printf("��ջ��Ԫ��Ϊ%d\n",b);
                Traversal_L(S);
            }
        }
        if(k==7) ClearStack_L(&S);
        if(k==8) StackEmpty_L(S);

    }
    return 0;




}

/**********************************************
    ���ƣ�InitStack(SqStack S)
    ���룺��ջָ��
    ���أ�״̬
***********************************************/
int InitStack(SqStack* S)
{
    S->base = (ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
    if(NULL == S->base)
        return 0;
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    printf("��ջ��ʼ���ɹ���\n");
    return 1;

}

/**********************************************
    ���ƣ�Push_L(SqStack S,int e)
    ���룺��ջָ�룬ѹջԪ��
    ���أ���
***********************************************/
void Push_L(SqStack *S,int e)//ѹջ
{
    if(S->top - S->base >= S->stacksize)
    {
        S->base = (ElemType*)realloc(S->base,(S->stacksize+STACKINCREMENT)*sizeof(ElemType));
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *(++S->top) = e;
    return 1;
}
/**********************************************
    ���ƣ�Pop_L(SqStack S,int* e)
    ���룺��ջָ�룬ѹջԪ��ָ��
    ���أ�״̬
***********************************************/
int Pop_L(SqStack *S,int *e)//��ջ
{
    if(S->top == S->base)
    {
        return 0 ;
    }
    *e =  *(S->top--);
    return 1;
}

/**********************************************
    ���ƣ�Traversal_L(SqStack S)
    ���룺��ջָ��
    ���أ���
***********************************************/
void Traversal_L(SqStack S)
{
    if(S.top == S.base)
    {
        puts("ջΪ�գ�\n");
        return 0;
    }
    while(S.top != S.base)
    {
        printf("%3d",*(S.top--));
    }
    printf("\n");

}

/**********************************************
    ���ƣ�StackLength_L(SqStack S)
    ���룺��ջָ��
    ���أ�״̬
***********************************************/
int StackLength_L(SqStack S)//ջ��
{
    return S.top - S.base;
}

/**********************************************
    ���ƣ�ClearStack_L(SqStack S)
    ���룺��ջָ��
    ���أ���
***********************************************/
void ClearStack_L(SqStack *S)
{
   S->top = S->base;
   printf("��ջԪ������գ�\n");
}
/**********************************************
    ���ƣ�StackEmpty_L(SqStack S)
    ���룺��ջָ��
    ���أ���
***********************************************/
void StackEmpty_L(SqStack S) //�ж�ջ�Ƿ�Ϊ��
{
    if(S.top == S.base)
        printf("��ջΪ�գ�\n");
    else
        puts("��ջ��Ϊ�գ�\n");
}
/**********************************************
    ���ƣ�DestroyStack_L(SqStack *S)
    ���룺��ջָ��
    ���أ���
***********************************************/
void DestroyStack_L(SqStack *S)//���ٶ�ջ
{
    free(S->base);
    S->base = S->top = NULL;
    S->stacksize = 0;
    puts("��ջ�����٣�\n");
}

/**********************************************
    ���ƣ�GetTop_L(SqStack S,int *e)
    ���룺��ջָ��
    ���أ���
***********************************************/
void GetTop_L(SqStack S,int *e) //��ȡջ��Ԫ��
{
    *e = *S.top;
    printf("ջ��Ԫ��Ϊ��%d \n",*e);
}
