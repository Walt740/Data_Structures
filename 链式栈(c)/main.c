#include <stdio.h>
#include <stdlib.h>

typedef struct SNODE
{
    int data;
    struct SNode *next;

}SNode,*LinkStack;

int InitStack(LinkStack *S); //初始化堆栈
void Push_L(LinkStack *S,int e); //压栈
int Pop_L(LinkStack *S,int* e); //弹栈
void Traversal_L(LinkStack S); //遍历堆栈
int StackLength_L(LinkStack S);//栈长
void ClearStack_L(LinkStack *S); //清空堆栈内容，不含头结点
void StackEmpty_L(LinkStack S); //判断栈是否为空
void DestroyStack_L(LinkStack *S); //销毁堆栈
void GetTop_L(LinkStack S,int *e); //获取栈顶元素




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
	LinkStack pS; //堆栈指针

    for(n=0;n<15;n++)
    {
        printf("请选择0-8:  ");
        scanf("%d",&k);
        if(k==0)
        {
            DestroyStack_L(&pS);
            n=15;
        }
        if(k==1)
        {
            if(InitStack(&pS))
                printf("创建成功!\n");
            else
                printf("创建失败!\n");
        }
        if(k==2)
        {
            int a;
            printf("输入栈S的元素为: ");
            scanf("%d",&a);
            Push_L(&pS,a);
            Traversal_L(pS);
        }
        if(k==3)
            Traversal_L(pS);

        if(k==4) printf("栈的长度为:%d \n ",StackLength_L(pS));
        if(k==5) {int c;GetTop_L(pS,c);}
        if(k==6)
        {
            int *b;
            if(!(pS))
            {
                printf("栈为空!\n");
                break;
            }
            if(Pop_L(&pS,b))
            {
                printf("出栈的元素为%d\n",*b);
                Traversal_L(pS);
            }
        }
        if(k==7) ClearStack_L(&pS);
        if(k==8) StackEmpty_L(pS);

    }
    return 0;
}



/**********************************************
    名称：InitStack(LinkStack S)
    输入：堆栈指针
    返回：状态
***********************************************/
int InitStack(LinkStack* S)
{
    *S = (LinkStack)malloc(sizeof(SNode));
    if(NULL == *S) return 0; //表示分配失败
    *S = NULL; //
    return 1;
}

/**********************************************
    名称：Push_L(LinkStack S,int e)
    输入：堆栈指针，压栈元素
    返回：无
***********************************************/
void Push_L(LinkStack *S,int e)//压栈
{
    LinkStack p;
    p = (LinkStack)malloc(sizeof(SNode));
    if(NULL == p)
        printf("申请空间失败！\n");
    else
    {
        p->data = e;
        p->next = *S;
        *S = p;
    }
}
/**********************************************
    名称：Pop_L(LinkStack S,int* e)
    输入：堆栈指针，压栈元素指针
    返回：状态
***********************************************/
int Pop_L(LinkStack *S,int *e)//弹栈
{
    LinkStack p;
    if(NULL == *S)
        return 0;
    else
    {
        *e = (*S)->data;
        printf("出栈的元素为：%d\n",*e);
        p = *S;
        *S = (*S)->next;
        free(p);
        return 1;
    }
}

/**********************************************
    名称：Traversal_L(LinkStack S)
    输入：堆栈指针
    返回：无
***********************************************/
void Traversal_L(LinkStack S)
{
    if(NULL == S)
        printf("当前堆栈为空！");
    else
    {
        printf("当前堆栈元素为：");
        while(S != NULL)
        {
            printf("%d  ",(S)->data);
            S = (S)->next;
        }
        printf("\n");
    }
}

/**********************************************
    名称：StackLength_L(LinkStack S)
    输入：堆栈指针
    返回：状态
***********************************************/
int StackLength_L(LinkStack S)//栈长
{
    int length = 0;
    if(S == NULL)
    {
        printf("当前堆栈为空！");
        return length;
    }
    else
    {
        while(S != NULL)
        {
            ++length;
            S = (S)->next;
        }
        printf("当前堆栈长度为：%d\n",length);
        return length;
    }
}

/**********************************************
    名称：ClearStack_L(LinkStack S)
    输入：堆栈指针
    返回：无
***********************************************/
void ClearStack_L(LinkStack *S)
{
    LinkStack p;
    while(NULL != *S)
    {
        p = *S;
        *S = (*S)->next;
        free(p);
       // p = NULL;
    }
    if(*S == NULL)
        printf("链式堆栈已清空！\n");
}
/**********************************************
    名称：StackEmpty_L(LinkStack S)
    输入：堆栈指针
    返回：无
***********************************************/
void StackEmpty_L(LinkStack S) //判断栈是否为空
{
    if(S == NULL)
        printf("当前堆栈为空！\n");
    else
        printf("当前堆栈不为空！\n");
}
/**********************************************
    名称：DestroyStack_L(LinkStack S)
    输入：堆栈指针
    返回：无
***********************************************/
void DestroyStack_L(LinkStack *S)//销毁堆栈
{
    LinkStack p;
    while(NULL != *S)
    {
        p = *S;
        *S = (*S)->next;
        free(p);
    }
    free(*S);
    printf("链式栈已销毁！\n");
}

/**********************************************
    名称：GetTop_L(LinkStack S,int *e)
    输入：堆栈指针
    返回：无
***********************************************/
void GetTop_L(LinkStack S,int *e) //获取栈顶元素
{
    if(S == NULL)
    {
        printf("当前栈为空\n");
    }
    else
    {
        printf("当前栈顶元素为：%d \n",(S)->data);
    }

}
