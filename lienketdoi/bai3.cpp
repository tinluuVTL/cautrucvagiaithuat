#include<iostream>
using namespace std;

typedef struct Node
{
	int data;
	Node *Next;	//*link;
	Node *Prev;
}Nodetype;
typedef Nodetype *Nodeptr;//typedef Node *Nodeptr ;

Nodeptr CreateNode(int x)
{
	Nodeptr p;
	p=new Node;
	p->data=x;
	p->Next=NULL;
	p->Prev=NULL;
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
		p->Prev=Tail;
		Tail=p;
	}
}
void InsertFirst(Nodeptr &Head,Nodeptr &Tail,Nodeptr p)
{

	if(Head==NULL)
	{
		Head=p;
		Tail=p;
	}
	else
	{
		p->Next=Head;
		Head=p;
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
void Print(Nodeptr &Head,Nodeptr &Tail)
{
	Nodeptr p=Head;
	if(Head==NULL) cout<<"\n Danh sach rong";
	while(p!=NULL)
	{
		cout<<"\t"<<p->data;
		p=p->Next;
	}
}
void DeleteAfter(Nodeptr q,Nodeptr &Tail)
{
	Nodeptr p;
	if(q!=NULL)
	{
		p=q->Next;
		q->Next=p->Next;
		if(p==Tail)Tail=q;
		delete p;
	}
}
void DeleteFirst(Nodeptr &Head,Nodeptr &Tail)
{
	Nodeptr p;
	if(Head!=NULL)
	{
		p=Head;
		Head=p->Next;
		if(Head==NULL)Tail=NULL;
		delete p;
	}
}
void DeleteX(Nodeptr &Head,Nodeptr &Tail)
{
	int x;
	Nodeptr p,q;
	cout<<"\n nhap gia tri can xoa ";
	cin>>x;
	p=Head;
	q=p;
	
	while(p!=NULL)
	{
		if(p->data==x)
		{
			if(p==Head)DeleteFirst(Head,Tail);
			else
				DeleteAfter(q,Tail);
			break;
		}
		q=p;
		p=p->Next;
	}
	
}
int main()
{
	Nodeptr Head,Tail;
	Head=Tail=NULL;
	int chon;
	do{
		cout<<"\n 1. Tao Danh sach";
		cout<<"\n 2. Xoa gia tri x  ";
		cout<<"\n 3. Ket thuc";
		cout<<"\n Ban chon: ";cin>>chon;
		switch(chon)
		{
			case 1: CreateList(Head,Tail);
			 		Print(Head,Tail);break;	
			case 2: 	
				{
						DeleteX(Head,Tail);
						cout<<"\n danh sach sau khi xoa x: ";
						Print(Head,Tail);	
					}break;	
		}
	}while(chon!=3);	
	delete Head;
	delete Tail;
	return 0;
}