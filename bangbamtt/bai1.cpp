#include<iostream>
#include<iomanip>
#include<math.h>
#define m 101

using namespace std;
typedef struct Bangbam
{
	int Data[m];
	int sopt;
}Bambinhphuong;

int hash(int k)
{
	return k%m; 
}

int Insert(Bangbam &b,int x)
{
	int t=0;
	int i=hash(x);
	while(b.Data[i]!=0 && b.sopt<m-1)i=(i++ *i)%m;
	if(b.sopt<m-1)
	{
		b.Data[i]=x;
		b.sopt++;
		t=1;
	}
	else
		cout<<"\n bang bam day";
	if(t!=0)return 1;
	return 0;
}
void init(Bangbam &b)
{
	b.sopt=0;
	for(int i=0;i<m;i++)
		b.Data[i]=0;
}
bool Print(Bangbam b)
{
	bool f=false;
	for(int i=0;i<m;i++)
	{
		if(b.Data[i]!=0)
			cout<<setw(5)<<b.Data[i]<<" luu tru tai vi tri thu "<<i<<endl;
		if(i==m-1)return true;
	}
	return false;
}
int main()
{
	int chon;
	Bangbam b;
	init(b);
	int x;
	do{
		cout<<"\n 1. Nhap du lieu bang bam:";
		cout<<"\n 2. Xuat tat ca du lieu trong bang bam";
		cout<<"\n 3. Thoat";
		cout<<"\n Ban chon:";cin>>chon;
		switch(chon)
		{
			case 1: 
					{
						init(b);int t;
						cout<<"\n Chuong trinh nhap lieu cho bang bam:";
						do{
							cout<<"\n Nhap x, x=-1 ket thuc";
							cin>>x; 
							if(x==-1)break;
							 t=Insert(b,x);
						}while(1);				
						if(t!=0)cout<<"\n \a Nhap lieu thanh cong";
						else cout<<"\n co loi khi nhap";
					}break;
			case 2:
					cout<<"\n Cac phan tu trong bang bam la:"<<endl;
					bool f=Print(b);
					if(f==false)cout<<"\n khong co du lieu trong bang bam";
					break;	
		}
	}while(chon!=3);
	
}

