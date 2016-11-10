#include <stdio.h>
#include <stdlib.h>

typedef struct NODE STU,*pSTU;
struct NODE
{
    int num;
    pSTU next;
};

//������������ͷָ��
pSTU Create()
{
    pSTU head;
    head = (pSTU)malloc(sizeof(STU));
    if(NULL == head)
    {
        printf("����ͷ���ʧ�ܣ�\n");
        return ;
    }
    head->next = NULL;
    return head;
}

//����Ԫ��
pSTU Insert( pSTU head,int pos,int num)
{
	int j = 0;
	pSTU  pnew, p;
	p = head;
	while (NULL != p && j < pos - 1 ) //��ͷָ�벻ΪNULL��
	{
		p = p->next;
		++j; 
	}
	if (NULL == p || j > pos - 1)//NULL == p�Ƿ�ֹ��������ĳ��ȶ���û��pos������������pos���λ�ÿ��Բ��롣
								 //i > pos -1�Ƿ�ֹ���������pos����Ϊ0���߸�����
	{
		printf("�����λ�ò��Ϸ���\n");
		return head;
	}
	pnew = (pSTU)malloc(sizeof(STU));
	pnew->num = num;
	pnew->next = p->next;
	p->next = pnew;
	
	return head;
}

//ɾ�����
pSTU DelNode(pSTU head, int pos)
{
	pSTU p = head, cur = NULL;
	int j = 0;
	while (NULL != p->next && j < pos - 1)
	{
		p = p->next;
		j++;
	}
	if (NULL == p->next || j > pos - 1)//->next//NULL == p->next�Ƿ�ֹ��������ĳ��ȶ���û��pos������������pos���λ�ÿ��Բ��롣
								      //i > pos -1�Ƿ�ֹ���������pos����Ϊ0���߸����� 
	{
		printf("�����λ�ò��Ϸ���\n");
		return head;
	}
	cur = p->next;
	p->next = cur->next;
	printf("ɾ������Ա  %d\n", cur->num);
	free(cur);
	printf("ɾ�����ɹ�\n" );
	return head;
}


//ɾ������
void del(pSTU head)
{
	pSTU p = head;
	printf("ɾ������\n");
	while(NULL != p)
	{ 
		head = head->next;
		free(p);
		p = head;
	}
	printf("ɾ������ɹ�\n");
}

//��ӡ����
void Traversal(pSTU head)
{
	pSTU p = head;
	printf("�������£�\n");
	p = head->next; 
	while (p != NULL)
	{
		printf("%d\t",p->num);
		p = p->next;
	}
	printf("\n");
}

//��������


int main()
{
	pSTU *head = NULL;
	//��ȡͷ���
	head = Create();
	int num;
	printf("������һ������\n");
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




