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
void InsertLast(Nodeptr &Head,Nodeptr &Tail,Nodeptr p)
{
	if(Head==NULL)Head=Tail=p;
	else
	{
		Tail->Next=p;
		Tail=p;
	}
}
void nhap(mathang &x)
{
	getline(cin,x.ma);
	getline(cin,x.loai);
	getline(cin,x.ten);
	cin>>x.soluong;
	cin>>x.dongia;
	getline(cin,x.quatang);
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
	cout<<"\t"<<x.dongia<<x.quatang<<endl;
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
int InDanhSachTheoYeucau(Nodeptr Head,Nodeptr Tail)
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

int main()
{
	Nodeptr Head,Tail;
	Head=NULL;
	Tail=NULL;
	
	int chon;
	do{
		
		cout<<"\n 1. Nhap danh sach ";
		cout<<"\n 2. In danh sach cac mat hang thoa dieu kien";
		cout<<"\n 3. Thoat ";
		cout<<"\n Ban chon: ";
		cin>>chon;
		switch(chon)
		{
			case 1:	
					CreateList(Head,Tail);
					cout<<"\n Danh sach vua nhap: ";
					Print(Head,Tail);
					break;
			case 2: cout<<"\n In danh sach cac mat hang thoa dieu kien:"<<endl;
					InDanhSachTheoYeucau(Head,Tail);
					break;					
		}
	}while(chon!=3);
	
}
