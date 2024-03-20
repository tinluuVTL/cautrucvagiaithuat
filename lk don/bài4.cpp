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

typedef struct Node2 
{
	mathang Data2;
	Node2 *Next2;
}Nodetype2;

typedef Nodetype *Nodeptr;
typedef Nodetype2 *Nodeptr2;

Nodeptr CreateNode(mathang x) 
{
	Nodeptr p;
	p=new Node;
	p->Data=x;
	p->Next=NULL;
	return p;
}

Nodeptr2 CreateNode2(mathang x) 
{
	Nodeptr2 p2;
	p2=new Node2;
	p2->Data2=x;
	p2->Next2=NULL;
	return p2;
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
void InsertLast2(Nodeptr2 &Head2,Nodeptr2 &Tail2,Nodeptr2 p2)
{
	if(Head2==NULL)Head2=Tail2=p2;
	else
	{
		Tail2->Next2=p2;
		Tail2=p2;
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

void CreateList(Nodeptr &Head,Nodeptr &Tail, Nodeptr2 &Head2,Nodeptr2 &Tail2)
{
	
	Head=Tail=NULL;
	Head2=Tail2=NULL;
	Nodeptr p;
	Nodeptr2 p2; 
	mathang x[3]={
	{"MH01","Banh snack","snack cua",1000,10,"Co"},
	{"MH02","Keo","Keo mut",500,2.5,"Khong"},
	{"MH03","Banh Trang","BonBon",600,6,"Co"}
	};
	
		for(int i=0;i<3;i++)
		{	p2=CreateNode2(x[i]);
				p=CreateNode(x[i]);
				InsertLast(Head,Tail,p);
				
				if(x[i].quatang=="co")
				{
			
				InsertLast2(Head2,Tail2,p2);	
				}	
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
int InDanhSachTheoYeucau(Nodeptr2 Head2,Nodeptr2 Tail2)
{

	int dem=0;
	Nodeptr2 p2=Head2;
	while(p2!=NULL)
	{
		
		Inmathang(p2->Data2);		
		p2=p2->Next2;
	}
	return dem;
}

int main()
{
		Nodeptr2 Head2,Tail2;
	Nodeptr Head,Tail;
	Head=NULL;
	Tail=NULL;
	Head2=NULL;
	Tail2=NULL; 
	
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
					CreateList(Head,Tail,Head2,Tail2);
					cout<<"\n Danh sach vua nhap: ";
					Print(Head,Tail);
					break;
			case 2: cout<<"\n In danh sach cac mat hang thoa dieu kien:"<<endl;
					InDanhSachTheoYeucau(Head2,Tail2);
					break;					
		}
	}while(chon!=3);
	
}
