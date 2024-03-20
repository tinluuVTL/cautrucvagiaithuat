#include<iostream>
#define m 11
#include <windows.h>
using namespace std;
struct Dienthoai
{
	int ma;
	char ten[20];
	char dv[10];
	float gia;
	int soluong;
};
struct Bangbam
{
	Dienthoai data[m];
	int sopt;
};
int hf(int key)
{
	return key%m;
}
int hf2(int key)
{
	return(m-2-key%(m-2));
}

void init(Bangbam &b)
{
	b.sopt=0;
	for(int i=0;i<m;i++)
		b.data[i].ma=0;
}
void Inhangton(Dienthoai x)
{
	cout<<"\n"<<x.ma<<"\t"<<x.ten<<"\t"<<x.dv<<"\t"<<x.soluong<<"\t"<<x.gia;
}

void Inputhangton(Dienthoai &x)
{
	cout<<"\n nhap ma: "; cin>>x.ma;
	cin.ignore();
	cout<<"\n Nhap Ten hang:";cin.getline(x.ten,20);
	cout<<"\n Nhap don vi:";cin.getline(x.dv,10);
	cout<<"\n SO luong: ";cin>>x.soluong;
	cout<<"\n Don gia:"; cin>>x.gia;
	
}
void Input(Bangbam &b,Dienthoai x)
{
	int i;
	i=hf(x.ma);
	int j=hf2(x.ma); //voi ma dt là khoá
	while(b.data[i].ma!=0 && b.sopt<m-1) i = (i + j) % m;
	if(b.sopt<m-1)
	{
		b.data[i]=x;
		b.sopt++;
	}
	else
	cout<<"\n Bang bam day";
}
void Print(Bangbam b)
{
	for(int i=0;i<m;i++)
	{
		if(b.data[i].ma!=0)
			Inhangton(b.data[i]);
	}
}

void Delb(Bangbam &b, int x)
{
	int i;
	i=hf(x);
	int j=hf2(x);
	while (b.data[i].ma != x && b.data[i].ma != 0)
	{
		i = (i + j) % m;
	}
	if (b.data[i].ma == x)
	{
		cout << "\n Tim thay gia tri " << x << " tai vi tri " << i << " Bat dau xoa";
		b.data[i].ma = 0;
		b.sopt--;
	}
	else
		cout << "\n khong tim thay x";
}
int main()
{
	system("color 0A");
	Dienthoai x;
	Bangbam b;
	init(b);
	
	int chon;
	do{
		cout<<"\n 1. Nhap";
		cout<<"\n 2. Xuat";
		cout<<"\n 3. TIM va XOA phan tu trong bang bam";
		cout<<"\n 4. thoat";
		cout<<"\n ban chon:";
		cin>>chon;
		switch(chon)
		{
			case 1:
					init(b);
					cout<<"\n nhap dien thoai: ";
					int n;
					cout<<"\n nhap so luong dien thoai can luu:";
					cin>>n;
					for(int i=0;i<n;i++)
					{
						Inputhangton(x);
						Input(b,x);
					}
					if(b.sopt>0)cout<<"\n Da nhap xong dien thoai";
					break;
			case 2:
					cout<<"\n cac dien thoai luu trong kho: "<<endl;
					Print(b);
					break;
			case 3:
			
					cout << "\n Nhap gia tri can xoa: ";
					int x;cin >> x;
					Delb(b, x);
					cout << "\n Du lieu trong bang bam sau khi xoa:" << endl;
					Print(b);		 	 
		}
	
	}while (chon!=4);
	return 0;
}
