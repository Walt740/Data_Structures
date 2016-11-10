#include<iostream>
using namespace std;

typedef struct SNode
{
	int  data;
	struct SNode  *next;
}SNode, *LinkStack;


int InitStack(LinkStack &S)
{
	S=(LinkStack)malloc(sizeof(SNode));
	if(!S)return 0;
	S=NULL;
	return 1;
}

void Push_L (LinkStack &S,int e)
{
	LinkStack p;
	p=(LinkStack)malloc(sizeof(SNode));
    if (!p) cout<<"����ռ�ʧ��!!!"<<endl;
	else
	{
		p->data=e;
		p->next=S;
		S=p;
	}
}

void DisplayStack_L(LinkStack S) //��ջ����ջ�������ʾջ�е�Ԫ��
{
	if(!S) cout<<"��ǰջΪ��!"<<endl;
	else
	{
		cout<<"��ǰջ��Ԫ��Ϊ: ";
		while(S!=NULL)
		{
			cout<<(S->data)<<" ";
			S=S->next;
		}
		cout<<endl;
	}
}

int StackLength_L(LinkStack S) //�󳤶�
{
	int i=0;
	while(S!=NULL) {i++;S=S->next;}
	return i;
}

int pop_L(LinkStack &S,int &e) //��ջ
{
	LinkStack p;
	if(!S)	return 0;
    else
	{
		e=S->data;
		p=S;
		S=S->next;
        free(p);
		return 1;
     }
}

void ClearStack_L(LinkStack &S)//���
{
	LinkStack p;
	while(S)
	{
		p=S;
		S=S->next;
	    free(p);
		//p=NULL;
	}
	if(!S) cout<<"��ʽջ�����!!!"<<endl;
}

void StackEmpty_L(LinkStack S)//�п�
{
	if(S==NULL) cout<<"��ʽջΪ��!!!"<<endl<<endl;
	else        cout<<"��ʽջ��Ϊ��!!!"<<endl<<endl;
}

void DestroyStack_L(LinkStack &S)
{
	int e;
	while(S) {pop_L(S,e);S=S->next;}
	free(S);
	cout<<"˳��ջ������!!!"<<endl<<endl;
}

void GetTop_L(LinkStack S,int &e)//����ջ��Ԫ��
{
	if(!S)
        cout<<"����ʧ��!!!"<<endl<<endl;
	else
	{
		cout<<"ջ��Ԫ��Ϊ: ";
		cout<<(S->data)<<endl<<endl;
	}
}



int main()
{
	cout<<"*  1������һ������ջ          *"<<endl;
	cout<<"*  2��������ջ��Ԫ��          *"<<endl;
	cout<<"*  3�������ջ��Ԫ��          *"<<endl;
	cout<<"*  4������ջ�ĳ���            *"<<endl;
	cout<<"*  5������ջ��Ԫ��            *"<<endl;
	cout<<"*  6��ɾ����ջ��Ԫ��          *"<<endl;
	cout<<"*  7������Ѵ��ڵ���ջ        *"<<endl;
	cout<<"*  8���ж���ջ�Ƿ�Ϊ��        *"<<endl;
	cout<<"*  0��������ջ                *"<<endl;


	int n,k;
	LinkStack S;

    for(n=0;n<15;n++)
    {
        cout<<"��ѡ��0-8:  ";
        cin>>k;
        if(k==0) {DestroyStack_L(S);n=15;}
        if(k==1)
        {
            if(InitStack(S)) cout<<"�����ɹ�!"<<endl;
            else cout<<"����ʧ��!"<<endl;
        }
        if(k==2)
        {
            int a;
            cout<<"����ջS��Ԫ��Ϊ: ";
            cin>>a;
            Push_L(S,a);
            DisplayStack_L(S);
        }
        if(k==3) DisplayStack_L(S);
        if(k==4) cout<<"ջ�ĳ���Ϊ: "<<StackLength_L(S)<<endl<<endl;
        if(k==5) {int c;GetTop_L(S,c);}
        if(k==6)
        {
            int b;
            if(!S){cout<<"ջΪ��!";break;}
            if(pop_L(S,b)){cout<<"��ջ��Ԫ��Ϊ"<<b<<endl;DisplayStack_L(S);}
        }
        if(k==7) ClearStack_L(S);
        if(k==8) StackEmpty_L(S);

    }
    return 0;
}
