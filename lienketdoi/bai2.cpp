#include<iostream>
#include<iomanip>

using namespace std;

struct mathang
{
	string ma;
	string loai;
	string ten;
	int soluong;
	float dongia;
	string quatang;
};
typedef struct Node
{
	mathang Data;
	Node *Next;
	Node *Prev;
}Nodetype;

typedef Nodetype *Nodeptr;

Nodeptr CreateNode(mathang x) 
{
	Nodeptr p;
	p=new Node;
	p->Data=x;
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
		p->Prev=Tail;
		Tail=p;
	}
}

void CreateList(Nodeptr &Head,Nodeptr &Tail)
{
	Head=Tail=NULL;
	Nodeptr p;
	mathang x[3]={
	{"MH01","Banh snack","snack cua",1000,10,"Co"},
	{"MH02","Keo","Keo mut",500,2.5,"Khong"},
	{"MH03","Banh Trang","BonBon",600,6,"Co"}
	};
	
		for(int i=0;i<3;i++)
		{
				p=CreateNode(x[i]);
				InsertLast(Head,Tail,p);	
		}
}


void Inmathang(mathang x)
{
	cout<<"\n "<<x.ma<<"\t"<<x.loai<<"\t"<<x.ten<<"\t"<<x.soluong;
	cout<<"\t"<<x.dongia<<"\t"<<x.quatang<<endl;
}
int Print(Nodeptr Head,Nodeptr Tail)
{
	int dem=0;
	Nodeptr p=Head;
	while(p!=NULL)
	{
		
		Inmathang(p->Data);		
		p=p->Next;
	}
	return dem;
}
int InTheoYeucau(Nodeptr Head,Nodeptr Tail)
{
	int dem=0;
	Nodeptr p=Head;
	while(p!=NULL)
	{
		if(p->Data.quatang=="Co")
			Inmathang(p->Data);		
		p=p->Next;
	}
	return dem;
}

void Intheoyeucau2(Nodeptr Head,Nodeptr Tail,Nodeptr &Head2,Nodeptr &Tail2)
{
	int dem=0;
	Nodeptr q;
	Nodeptr p=Head;
	while(p!=NULL)
	{
		if(p->Data.quatang=="Co")
			{	
				
				Inmathang(p->Data);	
		
			}	
			
		p=p->Next;
	}

}

int main()
{
	Nodeptr Head,Tail;
	Head=Tail=NULL;
	Nodeptr Head2,Tail2;
	Head2=Tail2=NULL;
	int chon;
	do{
		
		cout<<"\n 1. Nhap danh sach ";
		cout<<"\n 2. In danh sach cac mat hang ";
		cout<<"\n 3. In danh sach cac mat hang 2"; 
		cout<<"\n 4. Thoat ";
		cout<<"\n Ban chon: ";
		cin>>chon;
		switch(chon)
		{
			case 1:	
					CreateList(Head,Tail);
					cout<<"\n Danh sach vua nhap: ";
					Print(Head,Tail);
					break;
			case 2: cout<<"\n danh sach cac mat hang thoa dieu kien:"<<endl;
					InTheoYeucau(Head,Tail);
					break;	
			case 3: cout<<"\n danh sach cac mat hang 2:"<<endl;	
				Intheoyeucau2(Head,Tail,Head2,Tail2);
				Print(Head2,Tail2);	
				break;					
		}
	}while(chon!=4);
	
}
