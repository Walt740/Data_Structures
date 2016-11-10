//#include <stdio.h>
//#include <stdlib.h>
//
//#define ElementType int
//#define MAXSIZE 10
//typedef struct LNode
//{
//    ElementType Data[MAXSIZE];
//    int Last;
//}LNODE, *List;
//
//
//LNODE L;
//List PtrL;
//
////访问下标为i的元素：L.Data[i]或PtrL->Data[i]
////线性表的长度：L.Last+1或PtrL->Last+1
//
//
////初始化（建立空的顺序表）
//List MakeEmpty()
//{
//    List PtrL;
//    PtrL = (List)malloc(sizeof(LNODE));
//    PtrL->Last = -1;
//    return PtrL;
//}
//
////查找
//int Find(ElementType X, List PtrL)
//{
//    int i = 0;
//    //两种情况
//    while(i <= PtrL->Last && PtrL->Data[i] != X)
//        ++i;
//    if(i > PtrL->Last)
//        return -1;  //如果没有找到，返回-1
//    else
//        return i;   //找到后返回存储位置
//}
//
////插入操作实现
//void Insert(ElementType X,int i,List PtrL)
//{
//    int j;
//    if(PtrL->Last == MAXSIZE -1) //表空间已满，不能插入
//    {
//        printf("表满");
//        return ;
//    }
//    if(i < 1 || i > PtrL->Last + 2) //检查插入位置的合法性
//    {
//        printf("位置不合法");
//        return ;
//    }
//    for(j = PtrL->Last;j >= i-1;j--)
//    {
//        PtrL->Data[j+1] = PtrL->Data[j]; //将ai~an倒序向后移动
//    }
//    PtrL->Data[i-1] = X;//新元素插入
//    PtrL->Last++;   //last仍指向最后元素
//    return;
//}
//
////删除
//void Delete(int i,List PtrL)
//{
//    int j;
//    if(i < 1 || i > PtrL->Last + 1) //检查空表及删除位置的合法性
//    {
//        printf("不存在第%d个元素",i);
//        return;
//    }
//    for(j = i; j <= PtrL->Last;j++)
//        PtrL->Data[j - 1] = PtrL->Data[j]; //将ai+1~an顺序向前移动
//    PtrL->Last--; //Last 仍指向最后元素
//    return ;
//}
////销毁顺序表
//void Destroy(List PtrL)
//{
//    free(PtrL);
//    printf("删除成功！\n");
//}
//
//
////遍历
//void Traversal(List PtrL)
//{
//    for(int  i = 0; i < MAXSIZE -1 ; ++i)
//    {
//        printf("%d\t",PtrL->Data[i]);
//    }
//    printf("\n");
//}
//
//
//int main()
//{
//    PtrL = MakeEmpty();
//    for(int i = 0; i < 10 ; i++)
//        Insert(i,1,PtrL);
//
//    Traversal(PtrL);
//    printf("\n %d \n", Find(7, PtrL));
//    Destroy(PtrL);
//
//
//    return 0 ;
//}
//



//#include <stdio.h>
//#include <stdlib.h>
//
//#define listsize 100
//
//typedef struct
//{
//    int data[listsize];
//    int length;
//}Seqlist;
//
//void main()
//{
//    void createlist(Seqlist *l,int n);
//    void printlist(Seqlist *l,int n);
//    void locateElem(Seqlist *l,int n);
//    void listinsert(Seqlist *l,int i,int n);
//    void listdelete(Seqlist *l,int i,int n);
//    int n ;
//
//    int i = 0;
//    Seqlist l;
//    l.length = 0;
//
//    printf("请输入线性表长度：\n");
//    scanf("%d",&n);
//    createlist(&l,n);
//    printlist(&l,n);
//
//    locateElem(&l,n);
//    listinsert(&l,i,n);
//    listdelete(&l,i,n);
//    printf("\n");
//}
//
////新建顺序表
//void createlist(Seqlist *l,int n)
//{
//    int i;
//    printf("请输入顺序表元素：\n");
//    for(i = 0;i<n;++i)
//    {
//       scanf("%d",&l->data[i]);
//        l->length = n;
//    }
//}
////输出顺序表
//void printlist(Seqlist *l, int n)
//{
//    int i;
//    printf("顺序表为：\n");
//    for(i = 0; i< n; i++)
//    {
//        printf("%d",l->data[i]);
//    }
//}
////查找元素
//
//void locateElem(Seqlist *l,int n)
//{
//    int i=1,*p;
//    p=l->data;
//    printf("\n请输入要查找的元素n:");
//    scanf("%d",&n);
//    while(i<=l->length&&(*p++!=n)) ++i;
//    if(i<=l->length)
//    printf("要查找的数的位置为：%d",i);
//}
////插入元素
//void listinsert(Seqlist *l,int i, int n)
//{
//    int *q,*p;
//    printf("\n请输入要插入的数：");
//    scanf("%d",&n);
//    if(l->length == 0)
//    {
//        l->data[0] = n;
//        ++l->length;
//    }
//    q = &(l->data[0]);
//    while((*q <= n)&&(q <= &(l->data[l->length - 1])))
//    {
//        ++q;
//    }
//    ++l->length;
//    for(p = &(l->data[l->length -1]); p >= q; --p)
//    {
//        *(p + 1) = *p;
//        *p = n;
//    }
//    printf("输出新表:\n");
//    for(i = 0;i < l->length; ++i)
//    {
//        *(p + 1) = *p ;
//        *p = n;
//    }
//    printf("输出新表：\n");
//    for(i = 0 ; i < l->length; ++i)
//    {
//        printf("%d",l->data[i]);
//    }
//}
//
////删除元素
//
//void listdelete(Seqlist *l, int i ,int n)
//{
//    int *p , *q;
//    printf("\n请输入要删除的数的位置:\n");
//    scanf("%d" , &i);
//    if(i < 1 || i > l->length)
//        printf("删除元素失败!");
//    p = &l->data[i-1];
//    n = *p;
//    q = l->data + l->length -1;
//    for(++p; p <= q; ++p)
//    {
//        *(p - 1) = *p;
//        --l->length;
//    }
//    for(i = 0;i < l->length + 1 ;i++)
//    {
//        printf("%d",l->data[i]);
//    }
//}


//#include "stdio.h"
//#include "stdlib.h"
//
//#define listsize 100
//
//typedef struct{
//    int data[listsize];
//    int length;
//}Seqlist;
//
//void createlist(Seqlist *l,int n);
//void printlist (Seqlist *l,int n);
//void locateElem(Seqlist *l,int n);
//void listinsert(Seqlist *l,int i,int n);
//void listdelete(Seqlist *l,int i,int n);
//
//void main()
//{
//
//    int n;
//
//    int i=0;
//    Seqlist l;
//    l.length=0;
//
//    printf("请输入线性表长度:");
//    scanf("%d",&n);
//    createlist(&l,n);
//    printlist(&l,n);
//    locateElem(&l,n);
//    listinsert(&l,i,n);
//    listdelete(&l,i,n);
//    printf("\n");
//}
//
////新建顺序表
//
//void createlist(Seqlist *l,int n)
//{
//    int i;
//    printf("请输入顺序表元素：\n");
//    for(i=0;i<n;i++)
//    {
//        scanf("%d",&l->data[i]);
//        l->length=n;
//    }
//}
//
////输出顺序表
//
//void printlist(Seqlist *l,int n)
//{
//    int i;
//    printf("顺序表为：");
//    for(i=0;i<n;i++)
//    {
//        printf("%d ",l->data[i]);
//    }
//}
//
////查找元素
//
//void locateElem(Seqlist *l,int n)
//{
//    int i=1,*p;
//    p=l->data;
//    printf("\n请输入要查找的元素n:");
//    scanf("%d",&n);
//    while(i<=l->length&&(*p++!=n)) ++i;
//    if(i<=l->length)
//    printf("要查找的数的位置为：%d",i);
//}
//
////插入元素
//
//void listinsert(Seqlist *l,int i,int n)
//{
//    int *q,*p;
//    printf("\n请输入要插入的数：");
//    scanf("%d",&n);
//
//    if(l->length==0)
//    {
//        l->data[0]=n;
//        ++l->length;
//
//    }
//    q=&(l->data[0]);
//    while((*q<=n)&&(q<=&(l->data[l->length-1])))
//    {
//        ++q;
//    }
//    ++l->length;
//    for(p=&(l->data[l->length-1]);p>=q;--p)
//    {
//    *(p+1)=*p;
//    *p=n;
//    }
//
// printf("输出新表:\n");
//        for(i=0;i<l->length;i++)
//     {
//        printf("%d ",l->data[i]);
//     }
//}
//
////删除元素
//
//void listdelete(Seqlist *l,int i,int n)
//{
//    int *p,*q;
//    printf("\n请输入要删除的数的位置：");
//    scanf("%d",&i);
//
//    if(i<1||i>l->length)
//    printf("删除元素失败!");
//
//    p=&l->data[i-1];
//    n=*p;
//    q=l->data+l->length-1;
//    for(++p;p<=q;++p)
//    {
//         *(p-1)=*p;
//         --l->length;
//
//    }
//
//    for(i=0;i<l->length+1;i++)
//    {
//        printf("%d ",l->data[i]);
//    }
//}


////线性顺序表
//#include <stdio.h>
//#include <stdlib.h>
//#define LIST_INIT_SIZE 1000 //线性表存储空间的初始分配量
//#define LISTINCRESEMENT 100 //线性表存储空间的分配增量
//#define OK 1
//#define ERROR 0
//#define OVERFLOW -2
//typedef int elemType;//元素类型
//typedef struct
//{
//    elemType *List;//线性表首地址
//    int length;//当前的长度
//    int listsize;//当前分配的存储容量，以elemType为单位
//} SqList;
//
//void AgainMalloc(SqList *L)//空间不够时重新分配空间的函数
//{
//    elemType *newbase;//分配一个临时基址
//    newbase=(elemType *)realloc(L->List,(L->listsize+LISTINCRESEMENT)*sizeof(elemType));
//    if(!newbase) exit(OVERFLOW);
//    L->List=newbase;
//    L->listsize+=LISTINCRESEMENT;
//}
//
////初始化一个空的线性表
//int InitList_Sq(SqList *L)
//{
//    L->List=(elemType *)malloc(LIST_INIT_SIZE*sizeof(elemType));
//    if(!L->List)exit(OVERFLOW);//overflow
//    L->length=0;//初始表为空表
//    L->listsize=LIST_INIT_SIZE;//初始表的存储容量，为LIST_INIT_SIZE个elemType单位
//    return OK;
//}
////求表中元素的个数
//int ListLength(SqList *L)
//{
//    return L->length;
//}
//
////遍历顺序表
//void TraverseList(SqList *L)
//{
//    int i;
//    for(i=0; i<L->length; i++)
//    {
//        printf("%d ",L->List[i]);
//    }
//    printf("\n");
//    return;
//}
////向表头插入元素
//void InsertFirst(SqList *L,elemType e)
//{
//    int i;
//    if(L->length>=L->listsize)
//        AgainMalloc(L);
//    for(i=L->length-1; i>=0; i--)
//        L->List[i+1]=L->List[i];
//    L->List[0]=e;
//    L->length++;
//    return;
//}
//
////向表尾插入元素
//void InsertLast(SqList *L,elemType e)
//{
//
//    if(L->length>=L->listsize)
//        AgainMalloc(L);
//    L->List[L->length]=e;
//    L->length++;
//    return;
//}
////在表中第pos个位置之前插入新元素e
//int Insert_Sq(SqList *L,elemType e,int pos)
//{
//    int i;
//    if(pos<1||pos>L->length+1) return ERROR;
//    if(L->length>=L->listsize)//存储空间不够，要分配新的空间
//        AgainMalloc(L);
//    for(i=L->length-1; i>=pos-1; i--)
//        L->List[i+1]=L->List[i];
//    L->List[pos-1]=e;
//    L->length++;
//    return OK;
//}
////查找给出元素的位置，若存在，给出位置(从1开始算)；若不存在，返回-1
//void Search(SqList *L,elemType e)
//{
//    int i;
//    for(i=0; i<L->length; i++)
//    {
//        if(L->List[i]==e)
//        {
//            printf("找到，%d在第%d个位置\n",e,i+1);
//            return;
//        }
//    }
//    printf("没找到\n");
//    return;
//}
////删除第pos个元素，并返回其值
//elemType DeleteElem(SqList *L,int pos)
//{
//    int i;
//    elemType temp;
//    if(pos<1||pos>L->length)
//    {
//        printf("pos值越界\n");
//        exit(1);
//    }
//    temp=L->List[pos-1];
//    for(i=pos; i<L->length; i++)
//        L->List[i-1]=L->List[i];
//    L->length--;
//    return temp;
//}
////判断线性表是否为空，为空返回1，不为空返回0
//int isEmpty(SqList *L)
//{
//    if(L->length==0)
//        return 1;
//    else
//        return 0;
//}
//
////顺序表的逆置
//void Inverse(SqList *L)
//{
//    int low=0,high=L->length-1;
//    elemType temp;
//    int i;
//    for(i=0; i<L->length/2; i++)
//    {
//        temp=L->List[low];
//        L->List[low++]=L->List[high];
//        L->List[high--]=temp;
//    }
//}
//
//void MergeList(SqList *La,SqList *Lb,SqList *Lc)
//{
//    //elemType *pa=La->List;elemType *pb=Lb->List;
//    Lc->listsize=Lc->length=La->length+Lb->length;
//    Lc->List=(elemType *)malloc(sizeof(elemType));
//    if(!Lc->List) exit(OVERFLOW);
//    int i=0,j=0,k=0;
//    while(i<La->length&&j<Lb->length)
//    {
//        if(La->List[i]<=Lb->List[j])
//        {
//            Lc->List[k++]=La->List[i++];
//        }
//        else
//        {
//            Lc->List[k++]=Lb->List[j++];
//        }
//    }
//    while(i<La->length)
//    {
//        Lc->List[k++]=La->List[i++];
//    }
//    while(j<Lb->length)
//    {
//        Lc->List[k++]=Lb->List[j++];
//    }
//}
//int main()
//{
//    SqList list1;
//    InitList_Sq(&list1);
//    int length;
//    scanf("%d",&length);
//    int i;
//    elemType temp;
//    for(i=0; i<length; i++)
//    {
//        scanf("%d",&temp);
//        InsertLast(&list1,temp);
//    }
//    printf("创建好的线性表La=");
//    TraverseList(&list1);//创建好的顺序表
//    int pos;
//    scanf("%d%d",&temp,&pos);
//    Insert_Sq(&list1,temp,pos);
//    printf("插入一个元素后的线性表La=");
//    TraverseList(&list1);//插入一个数字后的线性表
//    scanf("%d",&pos);
//    DeleteElem(&list1,pos);
//    printf("删除一个元素后的线性表La=");
//    TraverseList(&list1);
//    scanf("%d",&temp);
//    Search(&list1,temp);//查找元素
//    printf("逆置后的线性表La=");
//    Inverse(&list1);
//    TraverseList(&list1);
//    SqList list2;
//    InitList_Sq(&list2);
//    scanf("%d",&length);
//    for(i=0; i<length; i++)
//    {
//        scanf("%d",&temp);
//        InsertLast(&list2,temp);
//    }
//
//    SqList list3;
//    MergeList(&list1,&list2,&list3);
//    printf("合并La和Lb后的线性表=");
//    TraverseList(&list3);
//    return 0;
//}


#include<stdio.h>
#include<malloc.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

#define TRUE  1
#define FALSE 0
#define OK    1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW   -2

typedef int ElemType; //元素类型
typedef int Status; //状态

typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

Status InitList_Sq(SqList *L)
{
	L->elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L->elem)
        return(OVERFLOW);
	L->length=0;
	L->listsize=LIST_INIT_SIZE;
	return OK;
}
Status CreatList_Sq(SqList *L,int n)
{
	int i;
	printf("输入%d个整数:\n",n);
	for(i=0;i<n;i++)
		scanf("\n%d",&L->elem[i]);
	return OK;
}


int main()
{
	int i,n;
	SqList a;
	SqList *l = &a;
	if(InitList_Sq(l) == -2)
        printf("分配失败");
	printf("\n输入要建立的线性表l的长度n:");//输入线性表得长度
	scanf("%d",&n);
	l->length = n;
	printf("线性表的长度是:%d\n",l->length);
	CreatList_Sq(l,n);//生成线性表
	printf("输出线性表l中的元素值：");//输出线性表中的元素
	for(i = 0;i < l->length; i++)
		printf("%7d",l->elem[i]);
	return 0;
}
