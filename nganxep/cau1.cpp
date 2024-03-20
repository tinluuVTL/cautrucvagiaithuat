#include<iostream>
#define m 5
using namespace std;

struct Stack
{
	int top;
	int Data[m];
};
void Push(Stack &s,int x)
{
	if(s.top==m-1)
	{
		cout<<"\n ngan xep day";
	}
	else
	{
		s.top++;
		s.Data[s.top]=x;
	}
}
int Pop(Stack &s)
{
	int x;
	if(s.top==-1)
	{
		cout<<"\n ngan xep rong   \t";
		return -1;
	}
	else
		
		{
			x=s.Data[s.top];
			s.top--;
			return x;	
		}
}
void Init(Stack &s)
{
	s.top=-1;
	for(int i=0;i<m;i++)
		s.Data[i]=0;
}

void Intheoyeucau(Stack s)
{
	int t=Pop(s);
	while(t!=-1)
	{
		if (t>10 && t<20)
		{
		 if(t%2== 0) 
		cout<<t<<"\t";	
		} 
	t=Pop(s);		
	}
}
int main()
{
	Stack s;
	int x;
	Init(s);
	while(1)
	{
		cout<<"\n Nhap gia tri cho ngan xep, nhap -1 ket thuc :";
		cin>>x;
		if(x==-1)break;
		Push(s,x);
	}
	cout<<"\n danh sach cac so chan lon hon 10 nho hon 20 :";
	Intheoyeucau(s);
		
	return 0;
}