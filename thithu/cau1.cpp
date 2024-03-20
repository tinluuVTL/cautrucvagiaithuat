#include<iostream>
#define m 10 //hang so
using namespace std;

// dinh nghia cau truc ngan xep
struct Stack
{
	int top;
	int Data[m];
};

// Buoc 2 thiet ke ham dua du lieu vao ngan xep
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

// Buoc 3 lay du lieu ra khoi ngan xep\

int Pop(Stack &s)
{
	int x;
	if(s.top==-1)
	{
		cout<<"\n ngan xep rong";
		return -1;
	}
	else
		//return s.Data[s.top--];
		{
			x=s.Data[s.top];
			s.top--;
			return x;	
		}
}

void Init(Stack &s)
{
	s.top=-1;//dinh nghia ngan xep rong
	for(int i=0;i<m;i++)
		s.Data[i]=0;
}
int timkiem(Stack &s,int a[],int n,int x)

{	int k;
	int mid=0, l, r;
	l=0;
	r=n-1;
	cout<<"so x "<<x<<endl;
	cout<<"so n "<<n<<endl;
	
	Push(s,l);//vao
	Push(s,r);
	
	while(l<=r)
			{
			r=Pop(s);//ra
			l=Pop(s);
			mid=(l+r)/2;
		
		
			if(s.Data[mid]==x)return mid;
			else if(s.Data[mid]>x) 
				{
			Push(s,l);
			Push(s,mid-1);
				}
			else 
				{
			Push(s,mid+1);
			Push(s,r);
				}
			}
		if(l>r)
		return -1;
}
void Print(Stack s)
{
	int t=Pop(s);
	while(t!=-1)
	{
		cout<<t<<"\t";
		t=Pop(s);
	}
}
int main()
{
	Stack s;
	int x,n=0;
	int a[10];
	
	//khoi tao ngan xep rong
	Init(s);
	//nhap du lieu cho ngan xep
	while(1)
	{
		cout<<"\n Nhap gia tri cho ngan xep, nhap -1 ket thuc";
		cin>>x;
		if(x==-1)break;
		Push(s,x);
		n++;
	;
	}
	cout<<"\n cac gia tri luu tru trong ngan xep la:";
	Print(s);
	
	cout<<" thao tac tim kiem nhi phan "<<endl;
	cout<<"nhap x can tim trong ngan xep ";
	cin>>x;
	timkiem(s,a,n,x);
		
	return 0;
}