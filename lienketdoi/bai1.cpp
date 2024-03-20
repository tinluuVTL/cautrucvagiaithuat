#include<iostream>
#include<iomanip>
#include<math.h> 
using namespace std;


typedef struct Node
{
	int data;
	Node *Next;

}Nodetype;

typedef Nodetype *Nodeptr;


Nodeptr CreateNode(int x)
{
	Nodeptr p;
	p=new Node;
	p->data=x;
	p->Next=NULL;
	return p;
}

void InsertLast(Nodeptr &Head,Nodeptr &Tail, Nodeptr p)
{
	if(Head==NULL)
	{
		Head=p;
		Tail=p;
	}
	else
	{
		Tail->Next=p;
		Tail=p;
	}
}

void CreateList(Nodeptr &Head,Nodeptr &Tail)
{
	int x;
	Nodeptr p;
	while(1)
	{
		cout<<"\n nhap x ";cin>>x;
		if(x==-1)break;
		p=CreateNode(x);
		InsertLast(Head,Tail,p);
	}
}

void Print(Nodeptr Head,Nodeptr Tail)
{
	Nodeptr p=Head;
	if(Head==NULL) cout<<"\n Danh sach rong";
	else 
		while(p!=NULL)
		{
			cout<<"\t"<<p->data;
			p=p->Next;
		}
}

bool scp(int n) 
{
	int i;
	i=sqrt(n);
	if (i==n )
	return true;
	else
	return false;
	  
}
void intheoyeucau(Nodeptr Head,Nodeptr Tail,Nodeptr &Head2,Nodeptr &Tail2)
{
	Nodeptr q;
	Nodeptr p=Head;
	if(Head==NULL) cout<<"\n Danh sach rong";
	else 
		while(p!=NULL)
		{
		if (scp (p->data)) 
					{
						q=CreateNode(p->data);
						InsertLast(Head2,Tail2,q);
					}
			p=p->Next;
		}
}
int main()
{
	Nodeptr Head,Tail;
	Nodeptr Head2,Tail2;
	Head=Tail=NULL;
	cout<<"nhap danh sach:" <<endl; 
	CreateList(Head,Tail);
	cout<<"\n Danh sach cac so vua nhap:"<<endl;
	Print(Head,Tail);
	
	Head2=Tail2=NULL;
	cout<<"\n danh sach so chinh phuong:"<<endl;
	intheoyeucau(Head,Tail,Head2,Tail2);
	Print(Head2,Tail2);
	return 0;
}
	