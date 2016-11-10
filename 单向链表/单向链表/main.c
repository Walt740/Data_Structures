#include <stdio.h>
#include <stdlib.h>

typedef struct NODE STU, *pSTU;
struct NODE
{
	int num;  // 数据域
	pSTU next; //指针域
};

//创建链表，返回头指针
pSTU Create()
{
	pSTU head;
	head = (pSTU)malloc(sizeof(STU));
	if (NULL == head)
	{
		printf("申请头结点失败！\n");
		exit(-1);
	}
	head->next = NULL;
	return head;
}

//插入元素,插在第pos个元素之前
pSTU Insert(pSTU head, int pos, int elem)
{
	pSTU p = NULL, pnew = NULL;
	p = head;
	int j = 0;
	while (NULL != p && j < pos - 1)
	{
		p = p->next;
		++j;
	}
	if (NULL == p || j > pos - 1)  //NULL == p是防止插入到不存在的结点前 || j > pos -1 是防止出现pos小于0
	{
		printf("插入的位置不合法！\n");
		return;
	}
	pnew = (pSTU)malloc(sizeof(STU));
	pnew->num = elem;
	pnew->next = p->next;
	p->next = pnew;
	return head;
}


//遍历链表
void Traversal(pSTU head)
{
	pSTU p = NULL;
	printf("链表如下： \n");
	p = head->next;
	while (NULL != p)
	{
		printf("%d -> ", p->num);
		p = p->next;
	}
	printf("\n");
}

//删除操作
void DelNode(pSTU head, int pos )
{
    pSTU p ,cur = NULL;
    p = head ;
    int j = 0 ;
    while(NULL != p->next && j < pos - 1)
    {
        p = p->next;
        ++j ;
    }
    if(NULL == p->next || j > pos -1)
    {
        printf("删除的结点不存在！\n");
        return ;
    }
    //找到结点之后的处理
    cur = p->next;
    p->next = cur->next;
    printf("删除的结点是:%d \n", cur->num);
    free(cur);
    printf("删除成功！！\n");


}

//销毁链表，从头结点开始删除
void DelList(pSTU head)
{
    pSTU p = NULL,del = head;
    while(NULL != del)
    {
        p = del->next;
        free(del);
        del = p;
    }
    printf("销毁链表成功！\n");
}

//查询链表中的一个结点
void SearchNode(pSTU head,int elem)
{
    pSTU p = head->next ;
    while(p != NULL && p->num != elem)
    {
        p = p->next;
    }
    if(p == NULL)
    {
        printf("查询的数字不在链表内！\n");
        return;
    }
    if(p->num == elem)
    {
        printf("存在！\n");
    }
}


int main()
{
	pSTU head = NULL;
	int num;
	head = Create();
	printf("请输入一个整数\n");
	scanf("%d", &num);
	Insert(head, 1, num);
	printf("请输入一个整数\n");
	scanf("%d", &num);
	Insert(head, 2, num);
	printf("请输入一个整数\n");
	scanf("%d", &num);
	Insert(head, 3, num);
	printf("请输入一个整数\n");
	scanf("%d", &num);
	Insert(head, 5, num);

//    DelNode(head ,2 );
    printf("开始遍历链表\n");
	Traversal(head);
	printf("开始查询\n");
	scanf("%d", &num);
	SearchNode(head,num);
    DelList(head);
	return 0;
}
