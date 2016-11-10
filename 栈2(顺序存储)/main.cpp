#define STACK_INIT_SIZE  100//存储空间初始分配量
#define STACKINCREMENT    10//存储空间分配增量
typedef int SElemType;
typedef int Status;
#include<stdio.h>
#include<stdlib.h>

typedef struct{
	SElemType *base;//base的初值为NULL
	SElemType *top;//栈顶指针
	int stacksize;//当前已分配的存储空间以元素为单位
}SqStack;


void print(SqStack S)
{
	int *p=S.base;
	printf("输出栈：\n");
    if(S.base==S.top)
        printf("这是一个空栈！\n");
	for(p;p!=S.top;p++)
		printf("%3d",*p);
	printf("\n");
}

Status InitStack(SqStack &S)
{
	S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base)  return 0;
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	printf("空栈初始化成功！\n");
	return 1;
}//InitStack


Status Push(SqStack&S, SElemType e)
{
	if(S.top-S.base>=S.stacksize)
	{
		S.base=(SElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S.base) return 0;
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT;
	}
	*S.top++=e;
	return 1;
}//Push


Status CreateStack(SqStack &S)
{
	for(int i=0;i<5;i++)
	{
		int e=rand()%100+1;
		Push(S,e);
	}
	return 1;
}

Status Pop(SqStack&S)
{
	if(S.top==S.base)   return 0;
	int e=*--S.top;
	printf("弹出的栈顶元素是:%d\n",e);
    return 1;
}//Pop


Status StackLength(SqStack S)
{
	printf("栈长为：%d\n",S.top-S.base);
	return 1;
}
void menu()
{
	printf("1.初始化栈!\n");
	printf("2.创建含有5个元素的栈!\n");
	printf("3.建一个数插入栈顶 !\n");
	printf("4.删除栈顶元素 !\n");
	printf("5.输出栈中元素个数!\n");
	printf("6.输出栈中个元素!\n");
}

int main()
{
	SqStack S;
	int n,e;
	menu();
	while(1)
	{
		printf("请输入1~6:  ");
		scanf("%d",&n);getchar();
		switch( n)
		{
            case 1:InitStack(S);break;
            case 2:CreateStack(S);print(S);break;
            case 3:printf("请输入要插入的数：");
                   scanf("%d",&e);getchar();
                   Push(S,e);print(S);break;
            case 4:Pop(S);print(S);break;
            case 5:StackLength(S);print(S);break;
            case 6:print(S);break;
            default:printf("结束!\n");exit(0);
		}
	}
	return 0;
}


//#include <stdio.h>
//#include <malloc.h>
//#define TRUE 1
//#define OK 1
//#define ERROR 0
//#define FALSE 0
//#define STACK_INIT_SIZE 100
//#define STACKINCREMENT 10
//
//typedef int Status;
//typedef int SElemType;
//
//struct SqStack
//{
//    SElemType *base;
//    SElemType *top;
//    int stacksize;
//};
//
//Status InitStack(SqStack &S)
//{
//    S.base = (SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
//    if(!S.base) return ERROR;
//    S.top = S.base;
//    S.stacksize = STACK_INIT_SIZE;
//    return OK;
//}
//Status Push(SqStack &S,SElemType e)
//{
//    if(S.top-S.base>=S.stacksize)
//    {
//        S.base = (SElemType*)realloc(S.base,((S.stacksize + STACKINCREMENT)*sizeof(SElemType)));
//        if(!S.base) return ERROR;
//        S.top = S.base + S.stacksize;
///*
//这一个问题的关键在于 realloc 是怎么实现的，有两种情况：
//如果有足够空间用于扩大mem_address指向的内存块，则分配额外内存，
//并返回mem_address。这里说的是“扩大”，我们知道，realloc是从堆上分配内存的，
//当扩大一块内存空间时， realloc()试图直接从堆上现存的数据后面的那些字节中
//获得附加的字节，如果能够满足，自然天下太平。也就是说，如果原先的内存大小
//后面还有足够的空闲空间用来分配，加上原来的空间大小= newsize。那么就ok。
//得到的是一块连续的内存。如果原先的内存大小后面没有足够的空闲空间用来分配，
//那么从堆中另外找一块newsize大小的内存。并把原来大小内存空间中的内容复制到newsize中。
//返回新的mem_address指针。（数据被移动了）。老块被放回堆上。如果是第二种情况的话，
//s->top 就不是原来的 top 了。。
//所以结论就是，很有必要。
//*/
//
//        S.stacksize += STACKINCREMENT;
//    }
//    *S.top++ = e;
//    return OK;
//}
//
//Status Pop(SqStack &S,SElemType &e)
//{
//    if(S.top == S.base) return ERROR;
//    e = *--S.top;
//    return OK;
//}
//Status GetTop(SqStack &S,SElemType &e)
//{
//    if(S.top == S.base) return ERROR;
//    e = *(S.top - 1);
//    return OK;
//}
//
//int StackLength(SqStack S)
//{
//    int count = 0;
//    int i;
//    while(S.top != S.base)
//    {
//        count++;
//        S.top--;
//    }
//    return count;
//// 返回栈S的元素个数
//// 请补全代码
//
//}
//
//Status StackTraverse(SqStack S)
//{
//// 从栈顶到栈底依次输出栈中的每个元素
//    SElemType *p = (SElemType *)malloc(sizeof(SElemType));
//    p = S.top;       //请填空
//    if(S.top == S.base)printf("The Stack is Empty!"); //请填空
//    else
//    {
//        printf("The Stack is: ");
//        p--;
//        while(p >= S.base)        //请填空
//        {
//            printf("%d ", *p);
//            p--;               //请填空
//        }
//    }
//    printf("\n");
//    return OK;
//}
//
//int main()
//{
//     int a;
//     SqStack S;
//     SElemType x, e;
//     if(InitStack(S))    // 判断顺序表是否创建成功，请填空
//    {
//        printf("A Stack Has Created.\n");
//    }
//    while(1)
//    {
//        printf("1:Push \n2:Pop \n3:Get the Top \n4:Return the Length of the Stack\n5:Load the Stack\n0:Exit\nPlease choose:\n");
//        scanf("%d",&a);
//        switch(a)
//        {
//            case 1: scanf("%d", &x);
//              if(!Push(S,x)) printf("Push Error!\n"); // 判断Push是否合法，请填空
//              else printf("The Element %d is Successfully Pushed!\n", x);
//              break;
//            case 2: if(!Pop(S,e)) printf("Pop Error!\n"); // 判断Pop是否合法，请填空
//              else printf("The Element %d is Successfully Poped!\n", e);
//                break;
//            case 3: if(!GetTop(S,e))printf("Get Top Error!\n"); // 判断Get Top是否合法，请填空
//              else printf("The Top Element is %d!\n", e);
//                 break;
//            case 4: printf("The Length of the Stack is %d!\n",StackLength(S)); //请填空
//                  break;
//            case 5: StackTraverse(S);  //请填空
//                  break;
//            case 0: return 1;
//        }
//    }
//}
