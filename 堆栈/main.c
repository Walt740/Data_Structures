#include <stdio.h>
#include <stdlib.h>


//数组实现
#define MAXSIZE 100

typedef int ElemType;
typedef int Status;


typedef struct SNode
{
    ElemType Data[MAXSIZE];
    int Top ;
}*Stack;


//压栈操作
void Push(Stack PtrS,ElemType item)
{
    if(PtrS->Top == MAXSIZE - 1)
    {
        printf("堆栈满\n");
        return ;
    }
    else
    {
        PtrS->Data[++(PtrS->Top)] = item;
        return;
    }
}

//弹栈操作
ElemType Pop(Stack PtrS)
{
    if(PtrS->Top == -1)
    {
        printf("堆栈空");
        return -1;
    }
    else
    {
        return (PtrS->Data[PtrS->Top--]);
    }
}

int main()
{
    int n ,i;
    struct SNode S;
    Stack pS = &S ;
    pS->Top = -1;

    printf("输入一个数 ：\n");
    scanf("%d" ,&n);
    Push(pS,n);
    printf("输入一个数 ：\n");
    scanf("%d" ,&n);
    printf("入栈：\n");
    Push(pS,n);
    for(i = 0; i <= pS->Top ; i++)
        printf("%d\t",pS->Data[i]);
    printf("\n");
    printf("出栈：\n");
    Pop(pS);
    for(i = 0; i <= pS->Top ; i++)
        printf("%d\t",pS->Data[i]);
    printf("\n");
    return 0;
}


