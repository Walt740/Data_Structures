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


//顺序表数组结构体
typedef struct
{
    ElemType *elem;
    int length;    //顺序表的元素个数
    int listsize;  //顺序表的最大长度
}SqList;

//初始化顺序表
Status InitList_Sq(SqList *L)
{
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));  //相当于动态数组
    if(L->elem == NULL) //检测是否分配成功
        return (OVERFLOW);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

//填充顺序表
Status CreateList_Sq(SqList *L,int n)
{
    int i;
    printf("输入%d个整数：\n",n);
    L->length = n;
    for(i=0;i<n;i++)
        scanf("\n%d",&L->elem[i]);
    return OK;
}

//插入顺序表
Status ListInsert_Sq(SqList *L,int i ,ElemType e)
{
    //在线性表L中的第i个位置前插入一个值为e的元素
    //i的取值范围： 1<= i <=ListLength_Sq(L)
    ElemType *newbase,*q,*p;
    if(i < 1 || i > L->length + 1)
        return FALSE; //输入的值不合法
    if(L->length >= L->listsize) //当前存储空间已满，增加分配量
    {
        newbase = (ElemType *)realloc(L->elem,(L->listsize + LISTINCREMENT)*sizeof(ElemType));

        if(NULL == newbase)
        {
            return OVERFLOW; //存储分配失败
        }
        L->elem = newbase;
        L->length += LISTINCREMENT;
    }
    q = &(L->elem[i - 1]); //q为插入位置
    for( p  = &(L->elem[L->length - 1]); p >= q; --p)
        *(p + 1)  = *p;
    *q = e; //插入e
    ++L->length; // 表长增1
    return OK;
}


//删除顺序表
Status ListDelete_Sq(SqList *L,int i)
{
    //删除线性表L中的第i个位置的元素
    ElemType *p;
    if(i < 1 || i > L->length )
        return FALSE; //输入的值不合法

     //q为删除位置
    for( p = &(L->elem[i - 1]); p < &(L->elem[L->length - 1]); ++p)
        *p  = *(p + 1);
    --L->length; // 表长增1
    return OK;
}


//搜索顺序表(按值)
Status ListFind_Sq(SqList *L,ElemType e)
{
    int i = 0 ;
    while(i < L->length && e != L->elem[i])
        ++i;
    if(i >= L->length)
        return INFEASIBLE;
    else
        return i; //返回元素位置
}

//搜索顺序表(按位置)
Status ListFindPos_Sq(SqList *L,int pos)
{
    if(pos > L->length || pos < 1)
        return INFEASIBLE;
    else
        return L->elem[pos - 1]; //返回该位置的值
}
int main()
{
    int i, n ,x , y;
    SqList a;
    SqList *l = &a;
    if(InitList_Sq(l) == -2)
        printf("分配失败！\n");
    printf("\n请输入要建立线性表的长度n："); //
    scanf("%d",&n);
    CreateList_Sq(l,n); // 生成顺序表
    printf("线性表的长度是：%d\n",l->length);
    printf("输出线性表中的元素值："); //输出线性表中的元素
    for(i = 0 ; i < l->length ; i++)
        printf("%7d",l->elem[i]);
    printf("\n输入要插入元素的位置：");
    scanf("%d",&i);
    printf("\n请输入要插入元素的值：");
    scanf("\n%d",&x);
    if(ListInsert_Sq(l,i,x) > 0)
    {
        printf("\n插入元素之后线性表L的长度是：%d",l->length);
        printf("\n插入元素之后线性表L的元素是：\n");
        for(i = 0; i < l->length ; ++i)
            printf("%5d",l->elem[i]);
    }
    else
    {
        printf("插入元素失败！\n");
    }

    printf("\n输入要删除元素的位置：");
    scanf("%d",&i);
    if(ListDelete_Sq(l,i) > 0)
    {
        printf("\n删除元素之后线性表L的长度是：%d",l->length);
        printf("\n删除元素之后线性表L的元素是：\n");
        for(i = 0; i < l->length;i++)
            printf("%5d",l->elem[i]);
    }
    else
    {
        printf("删除元素失败！\n");
    }

    printf("\n输入要查找元素：");
    scanf("%d",&n);
    y = ListFind_Sq(l,n) ;
    if(y == INFEASIBLE)
    {
        printf("该元素不在顺序表内！\n");
    }
    else
    {
        printf("\n查找元素是 %d ，在顺序表的 %d 位置。\n",l->elem[y],y + 1);
    }

    printf("\n输入要查找元素（按位置）：");
    scanf("%d",&n);
    y = ListFindPos_Sq(l,n) ;
    if(y == INFEASIBLE)
    {
        printf("该位置不合法！\n");
    }
    else
    {
        printf("\n查找元素是 %d ，在顺序表的 %d 位置。\n",y,n);
    }
    return 0;
}

