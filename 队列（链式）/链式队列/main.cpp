#include<iostream>
using namespace std;

typedef  struct QNode 	//Ԫ�ؽ��
{
   int  data;
   struct QNode *next;
}QNode, *QueuePtr;

typedef struct    //������
{
   QueuePtr  front; //��ͷָ��
   QueuePtr  rear;	//��βָ��
 }LinkQueue;

void InitQueue (LinkQueue &Q)//��ʼ��
{
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) cout<<"��ʼ��ʧ��!!!"<<endl;
	else
	{
		Q.front->next=NULL;
		cout<<"�����г�ʼ���ɹ�!!!"<<endl;
	}
}

void DestroyQueue (LinkQueue &Q)//����
{
	while(Q.front)
    {
		Q.rear=Q.front->next;
		free(Q.front);
	    Q.front=Q.rear;
	}
	if(!Q.front) cout<<"������������!!!"<<endl;
}

void EnQueue (LinkQueue &Q,int e)//���
 {
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if (!p)  cout<<"����ʧ��!!!"<<endl;
	else
	{
		p->data = e;
		p->next = NULL;
		Q.rear->next = p;
		Q.rear = p;
	}
}

void PrintQueue(LinkQueue Q)
{
	QueuePtr p;
	p = Q.front->next;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

void DeQueue (LinkQueue &Q, int &e)
{
	QueuePtr p;
	if (Q.front==Q.rear) cout<<"����ʧ��!!!"<<endl;
	else
	{
		p=Q.front->next;
		e=p->data;
		Q.front->next=p->next;
		if (Q.rear==p) Q.rear=Q.front;
		free(p);
		cout<<"ɾ����������Ϊ: ";
		PrintQueue(Q);

	}
}

int QueueEmpty(LinkQueue Q)
{
	if (Q.front==Q.rear) {cout<<"������Ϊ��!!!"<<endl;return 0;}
	else {cout<<"�����в�Ϊ��!!!"<<endl;return 1;}
}

void ClearQueue(LinkQueue &Q)
{
	QueuePtr p;
	while(Q.front!=Q.rear)
	{
		p=Q.front->next;
		Q.front->next=p->next;
		if (Q.rear==p) Q.rear=Q.front;
		free(p);
	}
	if (Q.front==Q.rear) cout<<"�����������!!!"<<endl;
}

int GetHead(LinkQueue Q)
{
	int e;
	if (Q.front==Q.rear) {cout<<"����ʧ��!!!"<<endl; return 0;}
	else
	{
		e=Q.front->next->data;
		return e;
	}
}

int QueueLength(LinkQueue Q)
{
	QueuePtr p;
	int i=0;
	p=Q.front->next;
	while(p) {p=p->next;i++;}
	return i;
}

int main()
{
	cout<<"*   0�������е�����"<<endl;
	cout<<"*   1�������г�ʼ��"<<endl;
	cout<<"*   2�������еĲ���"<<endl;
	cout<<"*   3�����������"<<endl;
	cout<<"*   4�������е�ɾ��"<<endl;
	cout<<"*   5�������е����"<<endl;
	cout<<"*   6�������е��п�"<<endl;
	cout<<"*   7���������еĳ���"<<endl;
	cout<<"*   8�����������еĶ�ͷԪ��"<<endl;

	LinkQueue Q;
	int n,k;

for(n=0;n<100;n++)
{
	cout<<"��ѡ��0-8:  ";
	cin >> k;
	if(k==0) {DestroyQueue(Q);n=100;}
	if(k==1) InitQueue(Q);
	if(k==3) PrintQueue(Q);
	if(k==2)
	{
		int e;
		cout<<"��������Ԫ��: ";
		cin>>e;
		EnQueue (Q,e);
		cout<<"�����������Ϊ: ";
		PrintQueue(Q);
	}
	if(k==4)
	{
		int del;
		DeQueue (Q, del);
	}
	if(k==5) ClearQueue(Q);
	if(k==6) QueueEmpty(Q);
	if(k==7) cout<<"�����еĳ���Ϊ: "<<QueueLength(Q)<<endl;
	if(k==8) cout<<"��ͷԪ��Ϊ: "<<GetHead(Q)<<endl;


}
	return 0;

}

