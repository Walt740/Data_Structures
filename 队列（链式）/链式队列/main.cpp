#include<iostream>
using namespace std;

typedef  struct QNode 	//元素结点
{
   int  data;
   struct QNode *next;
}QNode, *QueuePtr;

typedef struct    //特殊结点
{
   QueuePtr  front; //队头指针
   QueuePtr  rear;	//队尾指针
 }LinkQueue;

void InitQueue (LinkQueue &Q)//初始化
{
	Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
	if (!Q.front) cout<<"初始化失败!!!"<<endl;
	else
	{
		Q.front->next=NULL;
		cout<<"链队列初始化成功!!!"<<endl;
	}
}

void DestroyQueue (LinkQueue &Q)//销毁
{
	while(Q.front)
    {
		Q.rear=Q.front->next;
		free(Q.front);
	    Q.front=Q.rear;
	}
	if(!Q.front) cout<<"链队列已销毁!!!"<<endl;
}

void EnQueue (LinkQueue &Q,int e)//入队
 {
	QueuePtr p;
	p=(QueuePtr)malloc(sizeof(QNode));
	if (!p)  cout<<"操作失败!!!"<<endl;
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
	if (Q.front==Q.rear) cout<<"操作失败!!!"<<endl;
	else
	{
		p=Q.front->next;
		e=p->data;
		Q.front->next=p->next;
		if (Q.rear==p) Q.rear=Q.front;
		free(p);
		cout<<"删除后链队列为: ";
		PrintQueue(Q);

	}
}

int QueueEmpty(LinkQueue Q)
{
	if (Q.front==Q.rear) {cout<<"链队列为空!!!"<<endl;return 0;}
	else {cout<<"链队列不为空!!!"<<endl;return 1;}
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
	if (Q.front==Q.rear) cout<<"链队列已清空!!!"<<endl;
}

int GetHead(LinkQueue Q)
{
	int e;
	if (Q.front==Q.rear) {cout<<"操作失败!!!"<<endl; return 0;}
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
	cout<<"*   0、链队列的销毁"<<endl;
	cout<<"*   1、链队列初始化"<<endl;
	cout<<"*   2、链队列的插入"<<endl;
	cout<<"*   3、输出链队列"<<endl;
	cout<<"*   4、链队列的删除"<<endl;
	cout<<"*   5、链队列的清空"<<endl;
	cout<<"*   6、链队列的判空"<<endl;
	cout<<"*   7、求链队列的长度"<<endl;
	cout<<"*   8、返回链队列的队头元素"<<endl;

	LinkQueue Q;
	int n,k;

for(n=0;n<100;n++)
{
	cout<<"请选择0-8:  ";
	cin >> k;
	if(k==0) {DestroyQueue(Q);n=100;}
	if(k==1) InitQueue(Q);
	if(k==3) PrintQueue(Q);
	if(k==2)
	{
		int e;
		cout<<"输入插入的元素: ";
		cin>>e;
		EnQueue (Q,e);
		cout<<"插入后链队列为: ";
		PrintQueue(Q);
	}
	if(k==4)
	{
		int del;
		DeQueue (Q, del);
	}
	if(k==5) ClearQueue(Q);
	if(k==6) QueueEmpty(Q);
	if(k==7) cout<<"链队列的长度为: "<<QueueLength(Q)<<endl;
	if(k==8) cout<<"队头元素为: "<<GetHead(Q)<<endl;


}
	return 0;

}

