#include<iostream>
using namespace std;

typedef struct Node
{
	int data;
	Node *Next;	//*link;
}Nodetype;

typedef struct Node2 
{
	int  data2;
	Node2 *Next2;	//*link;
}Nodetype2;

typedef Nodetype *Nodeptr;//typedef Node *Nodeptr ;
typedef Nodetype2 *Nodeptr2;
Nodeptr CreateNode(int x)
{
	Nodeptr p;
	p=new Node;
	p->data=x;
	p->Next=NULL;
	return p;
}
Nodeptr2 CreateNode2(int x)
{
	Nodeptr2 p2;
	p2=new Node2;
	p2->data2=x;
	p2->Next2=NULL;
	return p2;
}
void InsertLast(Nodeptr &Head,Nodeptr &Tail,Nodeptr p)
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
void InsertLast2 (Nodeptr2 &Head2,Nodeptr2 &Tail2,Nodeptr2 p2)
{

	if(Head2==NULL)
	{
		Head2=p2;
		Tail2=p2;
	}
	else
	{
		Tail2->Next2=p2;
		Tail2=p2;
	}
}

void CreateList(Nodeptr &Head,Nodeptr &Tail, Nodeptr2 &Head2,Nodeptr2 &Tail2)
{
	int x;
	Nodeptr p;
	Nodeptr2 p2;
	while(1)//0 false 1 true
	{
		cout<<"\n nhap x, Nhap -1 de ket thuc ";cin>>x;
		if(x==-1)break;
		p=CreateNode(x);
		p2=CreateNode2(x);
		InsertLast(Head,Tail,p);
		if (x%2 == 0)
		if (x>10 && x<20) 
		InsertLast2(Head2,Tail2,p2);
	}
}
void Print(Nodeptr &Head,Nodeptr &Tail)
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
void InTheoYeucau(Nodeptr2 &Head2,Nodeptr2 &Tail2)
{
	
	Nodeptr2 p2=Head2;
	if(Head2==NULL) cout<<"\n Danh sach rong";
	else 
		while(p2!=NULL)
		{
			cout<<"\t"<<p2->data2;
			p2=p2->Next2;
		}

}

int main()
{
	Nodeptr Head, Tail; 
	Nodeptr2 Head2,Tail2;
	Head2=Tail2=NULL;
	Head=Tail=NULL; 
	int chon;
	do{
		cout<<"\n 1. Nhap N phan tu:";
		cout<<"\n 2. Xuat ra man hình cac so chan lon hon 10 va nho hon 20 ";
		cout<<"\n 3. Ket thuc";
		cout<<"\n Ban chon: ";cin>>chon;
		switch(chon)
		{
			case 1: 
					CreateList(Head,Tail,Head2,Tail2);
					cout<<"\n Danh sach da nhap "<<endl;
					Print(Head,Tail);
					break;
			case 2:  
					cout<<"\n Danh sach cac gia tri lon hon 10 nho hon 20:"<<endl;
					InTheoYeucau(Head2,Tail2);break;			
		}
	}while(chon!=3);

	
	
	delete Head2,Tail2;
	return 0;
}