#include <stdio.h>
#include <stdlib.h>

typedef struct NODE STU, *pSTU;
struct NODE
{
	int num;  // ������
	pSTU next; //ָ����
};

//������������ͷָ��
pSTU Create()
{
	pSTU head;
	head = (pSTU)malloc(sizeof(STU));
	if (NULL == head)
	{
		printf("����ͷ���ʧ�ܣ�\n");
		exit(-1);
	}
	head->next = NULL;
	return head;
}

//����Ԫ��,���ڵ�pos��Ԫ��֮ǰ
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
	if (NULL == p || j > pos - 1)  //NULL == p�Ƿ�ֹ���뵽�����ڵĽ��ǰ || j > pos -1 �Ƿ�ֹ����posС��0
	{
		printf("�����λ�ò��Ϸ���\n");
		return;
	}
	pnew = (pSTU)malloc(sizeof(STU));
	pnew->num = elem;
	pnew->next = p->next;
	p->next = pnew;
	return head;
}


//��������
void Traversal(pSTU head)
{
	pSTU p = NULL;
	printf("�������£� \n");
	p = head->next;
	while (NULL != p)
	{
		printf("%d -> ", p->num);
		p = p->next;
	}
	printf("\n");
}

//ɾ������
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
        printf("ɾ���Ľ�㲻���ڣ�\n");
        return ;
    }
    //�ҵ����֮��Ĵ���
    cur = p->next;
    p->next = cur->next;
    printf("ɾ���Ľ����:%d \n", cur->num);
    free(cur);
    printf("ɾ���ɹ�����\n");


}

//����������ͷ��㿪ʼɾ��
void DelList(pSTU head)
{
    pSTU p = NULL,del = head;
    while(NULL != del)
    {
        p = del->next;
        free(del);
        del = p;
    }
    printf("��������ɹ���\n");
}

//��ѯ�����е�һ�����
void SearchNode(pSTU head,int elem)
{
    pSTU p = head->next ;
    while(p != NULL && p->num != elem)
    {
        p = p->next;
    }
    if(p == NULL)
    {
        printf("��ѯ�����ֲ��������ڣ�\n");
        return;
    }
    if(p->num == elem)
    {
        printf("���ڣ�\n");
    }
}


int main()
{
	pSTU head = NULL;
	int num;
	head = Create();
	printf("������һ������\n");
	scanf("%d", &num);
	Insert(head, 1, num);
	printf("������һ������\n");
	scanf("%d", &num);
	Insert(head, 2, num);
	printf("������һ������\n");
	scanf("%d", &num);
	Insert(head, 3, num);
	printf("������һ������\n");
	scanf("%d", &num);
	Insert(head, 5, num);

//    DelNode(head ,2 );
    printf("��ʼ��������\n");
	Traversal(head);
	printf("��ʼ��ѯ\n");
	scanf("%d", &num);
	SearchNode(head,num);
    DelList(head);
	return 0;
}
