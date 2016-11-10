#include <stdio.h>
#include <stdlib.h>

typedef struct SNODE
{
    int data;
    struct SNode *next;

}SNode,*LinkStack;

int InitStack(LinkStack *S); //��ʼ����ջ
void Push_L(LinkStack *S,int e); //ѹջ
int Pop_L(LinkStack *S,int* e); //��ջ
void Traversal_L(LinkStack S); //������ջ
int StackLength_L(LinkStack S);//ջ��
void ClearStack_L(LinkStack *S); //��ն�ջ���ݣ�����ͷ���
void StackEmpty_L(LinkStack S); //�ж�ջ�Ƿ�Ϊ��
void DestroyStack_L(LinkStack *S); //���ٶ�ջ
void GetTop_L(LinkStack S,int *e); //��ȡջ��Ԫ��




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
	LinkStack pS; //��ջָ��

    for(n=0;n<15;n++)
    {
        printf("��ѡ��0-8:  ");
        scanf("%d",&k);
        if(k==0)
        {
            DestroyStack_L(&pS);
            n=15;
        }
        if(k==1)
        {
            if(InitStack(&pS))
                printf("�����ɹ�!\n");
            else
                printf("����ʧ��!\n");
        }
        if(k==2)
        {
            int a;
            printf("����ջS��Ԫ��Ϊ: ");
            scanf("%d",&a);
            Push_L(&pS,a);
            Traversal_L(pS);
        }
        if(k==3)
            Traversal_L(pS);

        if(k==4) printf("ջ�ĳ���Ϊ:%d \n ",StackLength_L(pS));
        if(k==5) {int c;GetTop_L(pS,c);}
        if(k==6)
        {
            int *b;
            if(!(pS))
            {
                printf("ջΪ��!\n");
                break;
            }
            if(Pop_L(&pS,b))
            {
                printf("��ջ��Ԫ��Ϊ%d\n",*b);
                Traversal_L(pS);
            }
        }
        if(k==7) ClearStack_L(&pS);
        if(k==8) StackEmpty_L(pS);

    }
    return 0;
}



/**********************************************
    ���ƣ�InitStack(LinkStack S)
    ���룺��ջָ��
    ���أ�״̬
***********************************************/
int InitStack(LinkStack* S)
{
    *S = (LinkStack)malloc(sizeof(SNode));
    if(NULL == *S) return 0; //��ʾ����ʧ��
    *S = NULL; //
    return 1;
}

/**********************************************
    ���ƣ�Push_L(LinkStack S,int e)
    ���룺��ջָ�룬ѹջԪ��
    ���أ���
***********************************************/
void Push_L(LinkStack *S,int e)//ѹջ
{
    LinkStack p;
    p = (LinkStack)malloc(sizeof(SNode));
    if(NULL == p)
        printf("����ռ�ʧ�ܣ�\n");
    else
    {
        p->data = e;
        p->next = *S;
        *S = p;
    }
}
/**********************************************
    ���ƣ�Pop_L(LinkStack S,int* e)
    ���룺��ջָ�룬ѹջԪ��ָ��
    ���أ�״̬
***********************************************/
int Pop_L(LinkStack *S,int *e)//��ջ
{
    LinkStack p;
    if(NULL == *S)
        return 0;
    else
    {
        *e = (*S)->data;
        printf("��ջ��Ԫ��Ϊ��%d\n",*e);
        p = *S;
        *S = (*S)->next;
        free(p);
        return 1;
    }
}

/**********************************************
    ���ƣ�Traversal_L(LinkStack S)
    ���룺��ջָ��
    ���أ���
***********************************************/
void Traversal_L(LinkStack S)
{
    if(NULL == S)
        printf("��ǰ��ջΪ�գ�");
    else
    {
        printf("��ǰ��ջԪ��Ϊ��");
        while(S != NULL)
        {
            printf("%d  ",(S)->data);
            S = (S)->next;
        }
        printf("\n");
    }
}

/**********************************************
    ���ƣ�StackLength_L(LinkStack S)
    ���룺��ջָ��
    ���أ�״̬
***********************************************/
int StackLength_L(LinkStack S)//ջ��
{
    int length = 0;
    if(S == NULL)
    {
        printf("��ǰ��ջΪ�գ�");
        return length;
    }
    else
    {
        while(S != NULL)
        {
            ++length;
            S = (S)->next;
        }
        printf("��ǰ��ջ����Ϊ��%d\n",length);
        return length;
    }
}

/**********************************************
    ���ƣ�ClearStack_L(LinkStack S)
    ���룺��ջָ��
    ���أ���
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
        printf("��ʽ��ջ����գ�\n");
}
/**********************************************
    ���ƣ�StackEmpty_L(LinkStack S)
    ���룺��ջָ��
    ���أ���
***********************************************/
void StackEmpty_L(LinkStack S) //�ж�ջ�Ƿ�Ϊ��
{
    if(S == NULL)
        printf("��ǰ��ջΪ�գ�\n");
    else
        printf("��ǰ��ջ��Ϊ�գ�\n");
}
/**********************************************
    ���ƣ�DestroyStack_L(LinkStack S)
    ���룺��ջָ��
    ���أ���
***********************************************/
void DestroyStack_L(LinkStack *S)//���ٶ�ջ
{
    LinkStack p;
    while(NULL != *S)
    {
        p = *S;
        *S = (*S)->next;
        free(p);
    }
    free(*S);
    printf("��ʽջ�����٣�\n");
}

/**********************************************
    ���ƣ�GetTop_L(LinkStack S,int *e)
    ���룺��ջָ��
    ���أ���
***********************************************/
void GetTop_L(LinkStack S,int *e) //��ȡջ��Ԫ��
{
    if(S == NULL)
    {
        printf("��ǰջΪ��\n");
    }
    else
    {
        printf("��ǰջ��Ԫ��Ϊ��%d \n",(S)->data);
    }

}
