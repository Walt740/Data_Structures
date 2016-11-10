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
////�����±�Ϊi��Ԫ�أ�L.Data[i]��PtrL->Data[i]
////���Ա�ĳ��ȣ�L.Last+1��PtrL->Last+1
//
//
////��ʼ���������յ�˳���
//List MakeEmpty()
//{
//    List PtrL;
//    PtrL = (List)malloc(sizeof(LNODE));
//    PtrL->Last = -1;
//    return PtrL;
//}
//
////����
//int Find(ElementType X, List PtrL)
//{
//    int i = 0;
//    //�������
//    while(i <= PtrL->Last && PtrL->Data[i] != X)
//        ++i;
//    if(i > PtrL->Last)
//        return -1;  //���û���ҵ�������-1
//    else
//        return i;   //�ҵ��󷵻ش洢λ��
//}
//
////�������ʵ��
//void Insert(ElementType X,int i,List PtrL)
//{
//    int j;
//    if(PtrL->Last == MAXSIZE -1) //��ռ����������ܲ���
//    {
//        printf("����");
//        return ;
//    }
//    if(i < 1 || i > PtrL->Last + 2) //������λ�õĺϷ���
//    {
//        printf("λ�ò��Ϸ�");
//        return ;
//    }
//    for(j = PtrL->Last;j >= i-1;j--)
//    {
//        PtrL->Data[j+1] = PtrL->Data[j]; //��ai~an��������ƶ�
//    }
//    PtrL->Data[i-1] = X;//��Ԫ�ز���
//    PtrL->Last++;   //last��ָ�����Ԫ��
//    return;
//}
//
////ɾ��
//void Delete(int i,List PtrL)
//{
//    int j;
//    if(i < 1 || i > PtrL->Last + 1) //���ձ�ɾ��λ�õĺϷ���
//    {
//        printf("�����ڵ�%d��Ԫ��",i);
//        return;
//    }
//    for(j = i; j <= PtrL->Last;j++)
//        PtrL->Data[j - 1] = PtrL->Data[j]; //��ai+1~an˳����ǰ�ƶ�
//    PtrL->Last--; //Last ��ָ�����Ԫ��
//    return ;
//}
////����˳���
//void Destroy(List PtrL)
//{
//    free(PtrL);
//    printf("ɾ���ɹ���\n");
//}
//
//
////����
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
//    printf("���������Ա��ȣ�\n");
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
////�½�˳���
//void createlist(Seqlist *l,int n)
//{
//    int i;
//    printf("������˳���Ԫ�أ�\n");
//    for(i = 0;i<n;++i)
//    {
//       scanf("%d",&l->data[i]);
//        l->length = n;
//    }
//}
////���˳���
//void printlist(Seqlist *l, int n)
//{
//    int i;
//    printf("˳���Ϊ��\n");
//    for(i = 0; i< n; i++)
//    {
//        printf("%d",l->data[i]);
//    }
//}
////����Ԫ��
//
//void locateElem(Seqlist *l,int n)
//{
//    int i=1,*p;
//    p=l->data;
//    printf("\n������Ҫ���ҵ�Ԫ��n:");
//    scanf("%d",&n);
//    while(i<=l->length&&(*p++!=n)) ++i;
//    if(i<=l->length)
//    printf("Ҫ���ҵ�����λ��Ϊ��%d",i);
//}
////����Ԫ��
//void listinsert(Seqlist *l,int i, int n)
//{
//    int *q,*p;
//    printf("\n������Ҫ���������");
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
//    printf("����±�:\n");
//    for(i = 0;i < l->length; ++i)
//    {
//        *(p + 1) = *p ;
//        *p = n;
//    }
//    printf("����±�\n");
//    for(i = 0 ; i < l->length; ++i)
//    {
//        printf("%d",l->data[i]);
//    }
//}
//
////ɾ��Ԫ��
//
//void listdelete(Seqlist *l, int i ,int n)
//{
//    int *p , *q;
//    printf("\n������Ҫɾ��������λ��:\n");
//    scanf("%d" , &i);
//    if(i < 1 || i > l->length)
//        printf("ɾ��Ԫ��ʧ��!");
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
//    printf("���������Ա���:");
//    scanf("%d",&n);
//    createlist(&l,n);
//    printlist(&l,n);
//    locateElem(&l,n);
//    listinsert(&l,i,n);
//    listdelete(&l,i,n);
//    printf("\n");
//}
//
////�½�˳���
//
//void createlist(Seqlist *l,int n)
//{
//    int i;
//    printf("������˳���Ԫ�أ�\n");
//    for(i=0;i<n;i++)
//    {
//        scanf("%d",&l->data[i]);
//        l->length=n;
//    }
//}
//
////���˳���
//
//void printlist(Seqlist *l,int n)
//{
//    int i;
//    printf("˳���Ϊ��");
//    for(i=0;i<n;i++)
//    {
//        printf("%d ",l->data[i]);
//    }
//}
//
////����Ԫ��
//
//void locateElem(Seqlist *l,int n)
//{
//    int i=1,*p;
//    p=l->data;
//    printf("\n������Ҫ���ҵ�Ԫ��n:");
//    scanf("%d",&n);
//    while(i<=l->length&&(*p++!=n)) ++i;
//    if(i<=l->length)
//    printf("Ҫ���ҵ�����λ��Ϊ��%d",i);
//}
//
////����Ԫ��
//
//void listinsert(Seqlist *l,int i,int n)
//{
//    int *q,*p;
//    printf("\n������Ҫ���������");
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
// printf("����±�:\n");
//        for(i=0;i<l->length;i++)
//     {
//        printf("%d ",l->data[i]);
//     }
//}
//
////ɾ��Ԫ��
//
//void listdelete(Seqlist *l,int i,int n)
//{
//    int *p,*q;
//    printf("\n������Ҫɾ��������λ�ã�");
//    scanf("%d",&i);
//
//    if(i<1||i>l->length)
//    printf("ɾ��Ԫ��ʧ��!");
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


////����˳���
//#include <stdio.h>
//#include <stdlib.h>
//#define LIST_INIT_SIZE 1000 //���Ա�洢�ռ�ĳ�ʼ������
//#define LISTINCRESEMENT 100 //���Ա�洢�ռ�ķ�������
//#define OK 1
//#define ERROR 0
//#define OVERFLOW -2
//typedef int elemType;//Ԫ������
//typedef struct
//{
//    elemType *List;//���Ա��׵�ַ
//    int length;//��ǰ�ĳ���
//    int listsize;//��ǰ����Ĵ洢��������elemTypeΪ��λ
//} SqList;
//
//void AgainMalloc(SqList *L)//�ռ䲻��ʱ���·���ռ�ĺ���
//{
//    elemType *newbase;//����һ����ʱ��ַ
//    newbase=(elemType *)realloc(L->List,(L->listsize+LISTINCRESEMENT)*sizeof(elemType));
//    if(!newbase) exit(OVERFLOW);
//    L->List=newbase;
//    L->listsize+=LISTINCRESEMENT;
//}
//
////��ʼ��һ���յ����Ա�
//int InitList_Sq(SqList *L)
//{
//    L->List=(elemType *)malloc(LIST_INIT_SIZE*sizeof(elemType));
//    if(!L->List)exit(OVERFLOW);//overflow
//    L->length=0;//��ʼ��Ϊ�ձ�
//    L->listsize=LIST_INIT_SIZE;//��ʼ��Ĵ洢������ΪLIST_INIT_SIZE��elemType��λ
//    return OK;
//}
////�����Ԫ�صĸ���
//int ListLength(SqList *L)
//{
//    return L->length;
//}
//
////����˳���
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
////���ͷ����Ԫ��
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
////���β����Ԫ��
//void InsertLast(SqList *L,elemType e)
//{
//
//    if(L->length>=L->listsize)
//        AgainMalloc(L);
//    L->List[L->length]=e;
//    L->length++;
//    return;
//}
////�ڱ��е�pos��λ��֮ǰ������Ԫ��e
//int Insert_Sq(SqList *L,elemType e,int pos)
//{
//    int i;
//    if(pos<1||pos>L->length+1) return ERROR;
//    if(L->length>=L->listsize)//�洢�ռ䲻����Ҫ�����µĿռ�
//        AgainMalloc(L);
//    for(i=L->length-1; i>=pos-1; i--)
//        L->List[i+1]=L->List[i];
//    L->List[pos-1]=e;
//    L->length++;
//    return OK;
//}
////���Ҹ���Ԫ�ص�λ�ã������ڣ�����λ��(��1��ʼ��)���������ڣ�����-1
//void Search(SqList *L,elemType e)
//{
//    int i;
//    for(i=0; i<L->length; i++)
//    {
//        if(L->List[i]==e)
//        {
//            printf("�ҵ���%d�ڵ�%d��λ��\n",e,i+1);
//            return;
//        }
//    }
//    printf("û�ҵ�\n");
//    return;
//}
////ɾ����pos��Ԫ�أ���������ֵ
//elemType DeleteElem(SqList *L,int pos)
//{
//    int i;
//    elemType temp;
//    if(pos<1||pos>L->length)
//    {
//        printf("posֵԽ��\n");
//        exit(1);
//    }
//    temp=L->List[pos-1];
//    for(i=pos; i<L->length; i++)
//        L->List[i-1]=L->List[i];
//    L->length--;
//    return temp;
//}
////�ж����Ա��Ƿ�Ϊ�գ�Ϊ�շ���1����Ϊ�շ���0
//int isEmpty(SqList *L)
//{
//    if(L->length==0)
//        return 1;
//    else
//        return 0;
//}
//
////˳��������
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
//    printf("�����õ����Ա�La=");
//    TraverseList(&list1);//�����õ�˳���
//    int pos;
//    scanf("%d%d",&temp,&pos);
//    Insert_Sq(&list1,temp,pos);
//    printf("����һ��Ԫ�غ�����Ա�La=");
//    TraverseList(&list1);//����һ�����ֺ�����Ա�
//    scanf("%d",&pos);
//    DeleteElem(&list1,pos);
//    printf("ɾ��һ��Ԫ�غ�����Ա�La=");
//    TraverseList(&list1);
//    scanf("%d",&temp);
//    Search(&list1,temp);//����Ԫ��
//    printf("���ú�����Ա�La=");
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
//    printf("�ϲ�La��Lb������Ա�=");
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

typedef int ElemType; //Ԫ������
typedef int Status; //״̬

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
	printf("����%d������:\n",n);
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
        printf("����ʧ��");
	printf("\n����Ҫ���������Ա�l�ĳ���n:");//�������Ա�ó���
	scanf("%d",&n);
	l->length = n;
	printf("���Ա�ĳ�����:%d\n",l->length);
	CreatList_Sq(l,n);//�������Ա�
	printf("������Ա�l�е�Ԫ��ֵ��");//������Ա��е�Ԫ��
	for(i = 0;i < l->length; i++)
		printf("%7d",l->elem[i]);
	return 0;
}
