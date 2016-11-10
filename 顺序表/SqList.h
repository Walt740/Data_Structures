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
typedef int ElemType;
typedef int Status;
typedef struct{
	ElemType *elem;
	int length;
	int listsize;
}SqList;
Status InitList_Sq(SqList *L)
{
	L->elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L->elem) return(OVERFLOW);
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
