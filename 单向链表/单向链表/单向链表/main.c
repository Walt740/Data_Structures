#include <stdio.h>
#include <stdlib.h>

typedef struct NODE STU,*pSTU;
struct NODE
{
    int num;
    pSTU next;
};

//创建链表，返回头指针
pSTU Create()
{
    pSTU head;
    head = (pSTU)malloc(sizeof(STU));
    if(NULL == head)
    {
        printf("申请头结点失败！\n");
        return ;
    }
    head->next = NULL;
    return head;
}

//插入元素
pSTU Insert( pSTU head,int pos,int num)
{
	int j = 0;
	pSTU  pnew, p;
	p = head;
	while (NULL != p && j < pos - 1 ) //当头指针不为NULL且
	{
		p = p->next;
		++j; 
	}
	if (NULL == p || j > pos - 1)//NULL == p是防止整个链表的长度都还没有pos长，即不存在pos这个位置可以插入。
								 //i > pos -1是防止别人输入的pos参数为0或者负数。
	{
		printf("输入的位置不合法！\n");
		return head;
	}
	pnew = (pSTU)malloc(sizeof(STU));
	pnew->num = num;
	pnew->next = p->next;
	p->next = pnew;
	
	return head;
}

//删除结点
pSTU DelNode(pSTU head, int pos)
{
	pSTU p = head, cur = NULL;
	int j = 0;
	while (NULL != p->next && j < pos - 1)
	{
		p = p->next;
		j++;
	}
	if (NULL == p->next || j > pos - 1)//->next//NULL == p->next是防止整个链表的长度都还没有pos长，即不存在pos这个位置可以插入。
								      //i > pos -1是防止别人输入的pos参数为0或者负数。 
	{
		printf("输入的位置不合法！\n");
		return head;
	}
	cur = p->next;
	p->next = cur->next;
	printf("删除结点成员  %d\n", cur->num);
	free(cur);
	printf("删除结点成功\n" );
	return head;
}


//删除操作
void del(pSTU head)
{
	pSTU p = head;
	printf("删除链表\n");
	while(NULL != p)
	{ 
		head = head->next;
		free(p);
		p = head;
	}
	printf("删除链表成功\n");
}

//打印链表
void Traversal(pSTU head)
{
	pSTU p = head;
	printf("链表如下：\n");
	p = head->next; 
	while (p != NULL)
	{
		printf("%d\t",p->num);
		p = p->next;
	}
	printf("\n");
}

//查找链表


int main()
{
	pSTU *head = NULL;
	//获取头结点
	head = Create();
	int num;
	printf("请输入一个整数\n");
	scanf("%d",&num);
	Insert(head, 1, num);
	scanf("%d", &num);
	Insert(head, 2, num);
	scanf("%d", &num);
	Insert(head, 3, num);
	//scanf("%d", &num);
	//Insert(head, 4, num);
	DelNode(head,4);
	Traversal(head);
	del(head);
    return 0 ;
}




