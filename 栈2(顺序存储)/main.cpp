#define STACK_INIT_SIZE  100//�洢�ռ��ʼ������
#define STACKINCREMENT    10//�洢�ռ��������
typedef int SElemType;
typedef int Status;
#include<stdio.h>
#include<stdlib.h>

typedef struct{
	SElemType *base;//base�ĳ�ֵΪNULL
	SElemType *top;//ջ��ָ��
	int stacksize;//��ǰ�ѷ���Ĵ洢�ռ���Ԫ��Ϊ��λ
}SqStack;


void print(SqStack S)
{
	int *p=S.base;
	printf("���ջ��\n");
    if(S.base==S.top)
        printf("����һ����ջ��\n");
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
	printf("��ջ��ʼ���ɹ���\n");
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
	printf("������ջ��Ԫ����:%d\n",e);
    return 1;
}//Pop


Status StackLength(SqStack S)
{
	printf("ջ��Ϊ��%d\n",S.top-S.base);
	return 1;
}
void menu()
{
	printf("1.��ʼ��ջ!\n");
	printf("2.��������5��Ԫ�ص�ջ!\n");
	printf("3.��һ��������ջ�� !\n");
	printf("4.ɾ��ջ��Ԫ�� !\n");
	printf("5.���ջ��Ԫ�ظ���!\n");
	printf("6.���ջ�и�Ԫ��!\n");
}

int main()
{
	SqStack S;
	int n,e;
	menu();
	while(1)
	{
		printf("������1~6:  ");
		scanf("%d",&n);getchar();
		switch( n)
		{
            case 1:InitStack(S);break;
            case 2:CreateStack(S);print(S);break;
            case 3:printf("������Ҫ���������");
                   scanf("%d",&e);getchar();
                   Push(S,e);print(S);break;
            case 4:Pop(S);print(S);break;
            case 5:StackLength(S);print(S);break;
            case 6:print(S);break;
            default:printf("����!\n");exit(0);
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
//��һ������Ĺؼ����� realloc ����ôʵ�ֵģ������������
//������㹻�ռ���������mem_addressָ����ڴ�飬���������ڴ棬
//������mem_address������˵���ǡ����󡱣�����֪����realloc�ǴӶ��Ϸ����ڴ�ģ�
//������һ���ڴ�ռ�ʱ�� realloc()��ͼֱ�ӴӶ����ִ�����ݺ������Щ�ֽ���
//��ø��ӵ��ֽڣ�����ܹ����㣬��Ȼ����̫ƽ��Ҳ����˵�����ԭ�ȵ��ڴ��С
//���滹���㹻�Ŀ��пռ��������䣬����ԭ���Ŀռ��С= newsize����ô��ok��
//�õ�����һ���������ڴ档���ԭ�ȵ��ڴ��С����û���㹻�Ŀ��пռ��������䣬
//��ô�Ӷ���������һ��newsize��С���ڴ档����ԭ����С�ڴ�ռ��е����ݸ��Ƶ�newsize�С�
//�����µ�mem_addressָ�롣�����ݱ��ƶ��ˣ����Ͽ鱻�Żض��ϡ�����ǵڶ�������Ļ���
//s->top �Ͳ���ԭ���� top �ˡ���
//���Խ��۾��ǣ����б�Ҫ��
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
//// ����ջS��Ԫ�ظ���
//// �벹ȫ����
//
//}
//
//Status StackTraverse(SqStack S)
//{
//// ��ջ����ջ���������ջ�е�ÿ��Ԫ��
//    SElemType *p = (SElemType *)malloc(sizeof(SElemType));
//    p = S.top;       //�����
//    if(S.top == S.base)printf("The Stack is Empty!"); //�����
//    else
//    {
//        printf("The Stack is: ");
//        p--;
//        while(p >= S.base)        //�����
//        {
//            printf("%d ", *p);
//            p--;               //�����
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
//     if(InitStack(S))    // �ж�˳����Ƿ񴴽��ɹ��������
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
//              if(!Push(S,x)) printf("Push Error!\n"); // �ж�Push�Ƿ�Ϸ��������
//              else printf("The Element %d is Successfully Pushed!\n", x);
//              break;
//            case 2: if(!Pop(S,e)) printf("Pop Error!\n"); // �ж�Pop�Ƿ�Ϸ��������
//              else printf("The Element %d is Successfully Poped!\n", e);
//                break;
//            case 3: if(!GetTop(S,e))printf("Get Top Error!\n"); // �ж�Get Top�Ƿ�Ϸ��������
//              else printf("The Top Element is %d!\n", e);
//                 break;
//            case 4: printf("The Length of the Stack is %d!\n",StackLength(S)); //�����
//                  break;
//            case 5: StackTraverse(S);  //�����
//                  break;
//            case 0: return 1;
//        }
//    }
//}
