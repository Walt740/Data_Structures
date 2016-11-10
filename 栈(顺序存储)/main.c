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

//顺序栈结构体
typedef struct Stack
{
    ElemType *base;
    int *top;      //栈顶指针，始终指向堆栈的顶部
    int stacksize; //堆栈的大小

}SqStack;

int InitStack(SqStack *S); //初始化堆栈
void Push_L(SqStack *S,int e); //压栈
int Pop_L(SqStack *S,int* e); //弹栈
void Traversal_L(SqStack S); //遍历堆栈
int StackLength_L(SqStack S);//栈长
void ClearStack_L(SqStack *S); //清空堆栈内容，不含头结点
void StackEmpty_L(SqStack S); //判断栈是否为空
void DestroyStack_L(SqStack *S); //销毁堆栈
void GetTop_L(SqStack S,int *e); //获取栈顶元素

int main()
{
    printf("*  1、构造一个空链栈          *\n");
	printf("*  2、输入链栈的元素          *\n");
	printf("*  3、输出链栈的元素          *\n");
	printf("*  4、求链栈的长度            *\n");
	printf("*  5、求链栈顶元素            *\n");
	printf("*  6、删除链栈顶元素          *\n");
	printf("*  7、清空已存在的链栈        *\n");
	printf("*  8、判断链栈是否为空        *\n");
	printf("*  0、销毁链栈                *\n");

    int n,k;
	SqStack S; //堆栈指针

    for(n=0;n<15;n++)
    {
        printf("请选择0-8:  ");
        scanf("%d",&k);
        if(k==0)
        {
            DestroyStack_L(&S);
            n=15;
        }
        if(k==1)
        {
            if(InitStack(&S))
                printf("创建成功!\n");
            else
                printf("创建失败!\n");
        }
        if(k==2)
        {
            int a;
            printf("输入栈S的元素为: ");
            scanf("%d",&a);
            Push_L(&S,a);
            Traversal_L(S);
        }
        if(k==3)
            Traversal_L(S);

        if(k==4) printf("栈的长度为:%d \n ",StackLength_L(S));
        if(k==5) {int c;GetTop_L(S,&c);}
        if(k==6)
        {
            int b;
            if((S.top == S.base))
            {
                printf("栈为空!\n");
                break;
            }
            if(Pop_L(&S,&b))
            {
                printf("出栈的元素为%d\n",b);
                Traversal_L(S);
            }
        }
        if(k==7) ClearStack_L(&S);
        if(k==8) StackEmpty_L(S);

    }
    return 0;




}

/**********************************************
    名称：InitStack(SqStack S)
    输入：堆栈指针
    返回：状态
***********************************************/
int InitStack(SqStack* S)
{
    S->base = (ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
    if(NULL == S->base)
        return 0;
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    printf("堆栈初始化成功！\n");
    return 1;

}

/**********************************************
    名称：Push_L(SqStack S,int e)
    输入：堆栈指针，压栈元素
    返回：无
***********************************************/
void Push_L(SqStack *S,int e)//压栈
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
    名称：Pop_L(SqStack S,int* e)
    输入：堆栈指针，压栈元素指针
    返回：状态
***********************************************/
int Pop_L(SqStack *S,int *e)//弹栈
{
    if(S->top == S->base)
    {
        return 0 ;
    }
    *e =  *(S->top--);
    return 1;
}

/**********************************************
    名称：Traversal_L(SqStack S)
    输入：堆栈指针
    返回：无
***********************************************/
void Traversal_L(SqStack S)
{
    if(S.top == S.base)
    {
        puts("栈为空！\n");
        return 0;
    }
    while(S.top != S.base)
    {
        printf("%3d",*(S.top--));
    }
    printf("\n");

}

/**********************************************
    名称：StackLength_L(SqStack S)
    输入：堆栈指针
    返回：状态
***********************************************/
int StackLength_L(SqStack S)//栈长
{
    return S.top - S.base;
}

/**********************************************
    名称：ClearStack_L(SqStack S)
    输入：堆栈指针
    返回：无
***********************************************/
void ClearStack_L(SqStack *S)
{
   S->top = S->base;
   printf("堆栈元素已清空！\n");
}
/**********************************************
    名称：StackEmpty_L(SqStack S)
    输入：堆栈指针
    返回：无
***********************************************/
void StackEmpty_L(SqStack S) //判断栈是否为空
{
    if(S.top == S.base)
        printf("堆栈为空！\n");
    else
        puts("堆栈不为空！\n");
}
/**********************************************
    名称：DestroyStack_L(SqStack *S)
    输入：堆栈指针
    返回：无
***********************************************/
void DestroyStack_L(SqStack *S)//销毁堆栈
{
    free(S->base);
    S->base = S->top = NULL;
    S->stacksize = 0;
    puts("堆栈已销毁！\n");
}

/**********************************************
    名称：GetTop_L(SqStack S,int *e)
    输入：堆栈指针
    返回：无
***********************************************/
void GetTop_L(SqStack S,int *e) //获取栈顶元素
{
    *e = *S.top;
    printf("栈顶元素为：%d \n",*e);
}
