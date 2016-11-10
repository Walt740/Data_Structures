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
    if (!p) cout<<"申请空间失败!!!"<<endl;
	else
	{
		p->data=e;
		p->next=S;
		S=p;
	}
}

void DisplayStack_L(LinkStack S) //从栈顶到栈底逐次显示栈中的元素
{
	if(!S) cout<<"当前栈为空!"<<endl;
	else
	{
		cout<<"当前栈内元素为: ";
		while(S!=NULL)
		{
			cout<<(S->data)<<" ";
			S=S->next;
		}
		cout<<endl;
	}
}

int StackLength_L(LinkStack S) //求长度
{
	int i=0;
	while(S!=NULL) {i++;S=S->next;}
	return i;
}

int pop_L(LinkStack &S,int &e) //出栈
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

void ClearStack_L(LinkStack &S)//清空
{
	LinkStack p;
	while(S)
	{
		p=S;
		S=S->next;
	    free(p);
		//p=NULL;
	}
	if(!S) cout<<"链式栈已清空!!!"<<endl;
}

void StackEmpty_L(LinkStack S)//判空
{
	if(S==NULL) cout<<"链式栈为空!!!"<<endl<<endl;
	else        cout<<"链式栈不为空!!!"<<endl<<endl;
}

void DestroyStack_L(LinkStack &S)
{
	int e;
	while(S) {pop_L(S,e);S=S->next;}
	free(S);
	cout<<"顺序栈已销毁!!!"<<endl<<endl;
}

void GetTop_L(LinkStack S,int &e)//返回栈顶元素
{
	if(!S)
        cout<<"操作失败!!!"<<endl<<endl;
	else
	{
		cout<<"栈顶元素为: ";
		cout<<(S->data)<<endl<<endl;
	}
}



int main()
{
	cout<<"*  1、构造一个空链栈          *"<<endl;
	cout<<"*  2、输入链栈的元素          *"<<endl;
	cout<<"*  3、输出链栈的元素          *"<<endl;
	cout<<"*  4、求链栈的长度            *"<<endl;
	cout<<"*  5、求链栈顶元素            *"<<endl;
	cout<<"*  6、删除链栈顶元素          *"<<endl;
	cout<<"*  7、清空已存在的链栈        *"<<endl;
	cout<<"*  8、判断链栈是否为空        *"<<endl;
	cout<<"*  0、销毁链栈                *"<<endl;


	int n,k;
	LinkStack S;

    for(n=0;n<15;n++)
    {
        cout<<"请选择0-8:  ";
        cin>>k;
        if(k==0) {DestroyStack_L(S);n=15;}
        if(k==1)
        {
            if(InitStack(S)) cout<<"创建成功!"<<endl;
            else cout<<"创建失败!"<<endl;
        }
        if(k==2)
        {
            int a;
            cout<<"输入栈S的元素为: ";
            cin>>a;
            Push_L(S,a);
            DisplayStack_L(S);
        }
        if(k==3) DisplayStack_L(S);
        if(k==4) cout<<"栈的长度为: "<<StackLength_L(S)<<endl<<endl;
        if(k==5) {int c;GetTop_L(S,c);}
        if(k==6)
        {
            int b;
            if(!S){cout<<"栈为空!";break;}
            if(pop_L(S,b)){cout<<"出栈的元素为"<<b<<endl;DisplayStack_L(S);}
        }
        if(k==7) ClearStack_L(S);
        if(k==8) StackEmpty_L(S);

    }
    return 0;
}
