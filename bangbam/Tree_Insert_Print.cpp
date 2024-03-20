#include<iostream>
#include<iomanip>
using namespace std;

typedef struct Node
{
	int data;
	Node *Left;
	Node *Right;
}Nodetype;

typedef Nodetype *Nodeptr;

Nodeptr CreateNode(int x)
{
	Nodeptr p;
	p=new Node;
	p->data=x;
	p->Left=NULL;
	p->Right=NULL;
	return p;
}
void insert(Nodeptr &Root,Nodeptr p)
{
	if(Root==NULL)Root=p;
	else
	{
		if(Root->data>p->data)
			insert(Root->Left,p);
		else if(Root->data<p->data)
			insert(Root->Right,p);
		else
			cout<<"\n Gia tri da co trong cay, Nhap gia tri khac";
	}
}
void LNR(Nodeptr Root)
{
	if(Root!=NULL)
	{
		LNR(Root->Left);
		cout<<"\t"<<Root->data;
		LNR(Root->Right);
	}
}
void NLR(Nodeptr Root)
{
	if(Root!=NULL)
	{
		cout<<"\t"<<Root->data;
		NLR(Root->Left);
		NLR(Root->Right);
	}
}
void LRN(Nodeptr Root)
{
	if(Root!=NULL)
	{
		LRN(Root->Left);
		LRN(Root->Right);
		cout<<"\t"<<Root->data;		
	}
}

int main()
{
	Nodeptr Root;
	Root=NULL;
	Nodeptr p;
	int chon;
	int x;
	do{
		system("CLS");
		cout<<"\n 1.Nhap cay nhi phan:";
		cout<<"\n 2. Duyet cay nhi phan:";
		cout<<"\n Ban chon:";cin>>chon;
		switch(chon)
		{
			case 1:{
					Root=NULL;
					cout<<"\n Nhap cac gia tri cho cay nhi phan:";
					do{
						cout<<"\n nhap gia tri, nhap -1 ket thuc:";
						cin>>x;
						if(x==-1)
							break;
						p=CreateNode(x);
						insert(Root,p);
						}while(1);
					}break;
			case 2:
					{
						cout<<"\n Tien Thu Tu: "<<endl;
						NLR(Root);
						cout<<"\n Trung thu tu: "<<endl;
						LNR(Root);
						cout<<"\n Hau thu tu: "<<endl;
						LRN(Root);
						system("pause");
					}break;
		
		}
	}while(chon!=5);

}