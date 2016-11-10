#include <stdio.h>
#include <stdlib.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

#define TURE 1
#define FALSE 0
#define OK 1
#define OVERFLOW -2
#define INFEASIBLE -1

typedef int ElemType;
typedef int Status;


//˳�������ṹ��
typedef struct
{
    ElemType *elem;
    int length;    //˳����Ԫ�ظ���
    int listsize;  //˳������󳤶�
}SqList;

//��ʼ��˳���
Status InitList_Sq(SqList *L)
{
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));  //�൱�ڶ�̬����
    if(L->elem == NULL) //����Ƿ����ɹ�
        return (OVERFLOW);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

//���˳���
Status CreateList_Sq(SqList *L,int n)
{
    int i;
    printf("����%d��������\n",n);
    L->length = n;
    for(i=0;i<n;i++)
        scanf("\n%d",&L->elem[i]);
    return OK;
}

//����˳���
Status ListInsert_Sq(SqList *L,int i ,ElemType e)
{
    //�����Ա�L�еĵ�i��λ��ǰ����һ��ֵΪe��Ԫ��
    //i��ȡֵ��Χ�� 1<= i <=ListLength_Sq(L)
    ElemType *newbase,*q,*p;
    if(i < 1 || i > L->length + 1)
        return FALSE; //�����ֵ���Ϸ�
    if(L->length >= L->listsize) //��ǰ�洢�ռ����������ӷ�����
    {
        newbase = (ElemType *)realloc(L->elem,(L->listsize + LISTINCREMENT)*sizeof(ElemType));

        if(NULL == newbase)
        {
            return OVERFLOW; //�洢����ʧ��
        }
        L->elem = newbase;
        L->length += LISTINCREMENT;
    }
    q = &(L->elem[i - 1]); //qΪ����λ��
    for( p  = &(L->elem[L->length - 1]); p >= q; --p)
        *(p + 1)  = *p;
    *q = e; //����e
    ++L->length; // ����1
    return OK;
}


//ɾ��˳���
Status ListDelete_Sq(SqList *L,int i)
{
    //ɾ�����Ա�L�еĵ�i��λ�õ�Ԫ��
    ElemType *p;
    if(i < 1 || i > L->length )
        return FALSE; //�����ֵ���Ϸ�

     //qΪɾ��λ��
    for( p = &(L->elem[i - 1]); p < &(L->elem[L->length - 1]); ++p)
        *p  = *(p + 1);
    --L->length; // ����1
    return OK;
}


//����˳���(��ֵ)
Status ListFind_Sq(SqList *L,ElemType e)
{
    int i = 0 ;
    while(i < L->length && e != L->elem[i])
        ++i;
    if(i >= L->length)
        return INFEASIBLE;
    else
        return i; //����Ԫ��λ��
}

//����˳���(��λ��)
Status ListFindPos_Sq(SqList *L,int pos)
{
    if(pos > L->length || pos < 1)
        return INFEASIBLE;
    else
        return L->elem[pos - 1]; //���ظ�λ�õ�ֵ
}
int main()
{
    int i, n ,x , y;
    SqList a;
    SqList *l = &a;
    if(InitList_Sq(l) == -2)
        printf("����ʧ�ܣ�\n");
    printf("\n������Ҫ�������Ա�ĳ���n��"); //
    scanf("%d",&n);
    CreateList_Sq(l,n); // ����˳���
    printf("���Ա�ĳ����ǣ�%d\n",l->length);
    printf("������Ա��е�Ԫ��ֵ��"); //������Ա��е�Ԫ��
    for(i = 0 ; i < l->length ; i++)
        printf("%7d",l->elem[i]);
    printf("\n����Ҫ����Ԫ�ص�λ�ã�");
    scanf("%d",&i);
    printf("\n������Ҫ����Ԫ�ص�ֵ��");
    scanf("\n%d",&x);
    if(ListInsert_Sq(l,i,x) > 0)
    {
        printf("\n����Ԫ��֮�����Ա�L�ĳ����ǣ�%d",l->length);
        printf("\n����Ԫ��֮�����Ա�L��Ԫ���ǣ�\n");
        for(i = 0; i < l->length ; ++i)
            printf("%5d",l->elem[i]);
    }
    else
    {
        printf("����Ԫ��ʧ�ܣ�\n");
    }

    printf("\n����Ҫɾ��Ԫ�ص�λ�ã�");
    scanf("%d",&i);
    if(ListDelete_Sq(l,i) > 0)
    {
        printf("\nɾ��Ԫ��֮�����Ա�L�ĳ����ǣ�%d",l->length);
        printf("\nɾ��Ԫ��֮�����Ա�L��Ԫ���ǣ�\n");
        for(i = 0; i < l->length;i++)
            printf("%5d",l->elem[i]);
    }
    else
    {
        printf("ɾ��Ԫ��ʧ�ܣ�\n");
    }

    printf("\n����Ҫ����Ԫ�أ�");
    scanf("%d",&n);
    y = ListFind_Sq(l,n) ;
    if(y == INFEASIBLE)
    {
        printf("��Ԫ�ز���˳����ڣ�\n");
    }
    else
    {
        printf("\n����Ԫ���� %d ����˳���� %d λ�á�\n",l->elem[y],y + 1);
    }

    printf("\n����Ҫ����Ԫ�أ���λ�ã���");
    scanf("%d",&n);
    y = ListFindPos_Sq(l,n) ;
    if(y == INFEASIBLE)
    {
        printf("��λ�ò��Ϸ���\n");
    }
    else
    {
        printf("\n����Ԫ���� %d ����˳���� %d λ�á�\n",y,n);
    }
    return 0;
}

