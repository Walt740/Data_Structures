#include <stdio.h>
#include <stdlib.h>


//����ʵ��
#define MAXSIZE 100

typedef int ElemType;
typedef int Status;


typedef struct SNode
{
    ElemType Data[MAXSIZE];
    int Top ;
}*Stack;


//ѹջ����
void Push(Stack PtrS,ElemType item)
{
    if(PtrS->Top == MAXSIZE - 1)
    {
        printf("��ջ��\n");
        return ;
    }
    else
    {
        PtrS->Data[++(PtrS->Top)] = item;
        return;
    }
}

//��ջ����
ElemType Pop(Stack PtrS)
{
    if(PtrS->Top == -1)
    {
        printf("��ջ��");
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

    printf("����һ���� ��\n");
    scanf("%d" ,&n);
    Push(pS,n);
    printf("����һ���� ��\n");
    scanf("%d" ,&n);
    printf("��ջ��\n");
    Push(pS,n);
    for(i = 0; i <= pS->Top ; i++)
        printf("%d\t",pS->Data[i]);
    printf("\n");
    printf("��ջ��\n");
    Pop(pS);
    for(i = 0; i <= pS->Top ; i++)
        printf("%d\t",pS->Data[i]);
    printf("\n");
    return 0;
}


