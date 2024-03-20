#include<iostream>
#define m 11
using namespace std;

struct Hangton
{
	int ma;
	char ten[20];// string
	int soluong;
	float gia;
};
struct Bangbam
{
	Hangton data[m];
	int sopt;
};
int hf(int key)
{
	return key%m;
}
int hf2(int key)
{
	return key%m;
}
void Input(Bangbam &b,Hangton x)
{
	int i;
	i=hf(x.ma);
	while(b.data[i].ma!=0 && b.sopt<m-1)i=(++i)%m;
	if(b.sopt<m-1)
	{
		b.data[i]=x;
		b.sopt++;
	}
	else
	cout<<"\n Bang bam day";
}
void init(Bangbam &b)
{
	b.sopt=0;
	for(int i=0;i<m;i++)
		b.data[i].ma=0;
}
void Inhangton(Hangton x)
{
	cout<<"\n"<<x.ma<<"\t"<<x.ten<<"\t"<<x.soluong<<"\t"<<x.gia;
}

void Inputhangton(Hangton &x)
{
	cout<<"\n nhap ma: "; cin>>x.ma;
	cin.ignore();
	cout<<"\n Nhap Ten hang:";cin.getline(x.ten,20);
	cout<<"\n SO luong: ";cin>>x.soluong;
	cout<<"\n Don gia:"; cin>>x.gia;
	
}
void Print(Bangbam b)
{
	for(int i=0;i<m;i++)
	{
		if(b.data[i].ma!=0)
			Inhangton(b.data[i]);
	}
}

int Search(Bangbam b,int x)
{
	int i=hf(x);
	while(b.data[i].ma!=0)
	{
		if(b.data[i].ma==x)
		{
			Inhangton(b.data[i]);
			return 1;
		}
		i=(++i)%m;
	}
		
	
	return 0;
	

}
int main()
{
	Hangton x;
	Bangbam b;
	init(b);
	Hangton a[]={
		{1,"Ao",30,20},
		{2,"Quan",35,25},
		{3,"Non",40,30},
		{4,"thun",40,30},
		{5,"jean",45,35}};
	int n=sizeof(a)/sizeof(Hangton);
	int chon;
	do{
		cout<<"\n 1. Nhap";
		cout<<"\n 2. Xuat";
		cout<<"\n 3. Tim kiem";
		cout<<"\n 4. thoat";
		cout<<"\n ban chon:";
		cin>>chon;
		switch(chon)
		{
			case 1:
					init(b);
					cout<<"\n nhap hang ton: ";
					//int n;
					//cout<<"\n nhap so luong hang ton can luu:";
				//	cin>>n;
					for(int i=0;i<n;i++)
					{
					//	Inputhangton(x);
						Input(b,a[i]);
					}
					if(b.sopt>0)cout<<"\n Da nhap xong hang ton";
					break;
			case 2:
					cout<<"\n cac mat hang trong bang bam: "<<endl;
					Print(b);
					break;
			case 3:
					
					cout<<"\n nhap ma hang can tim: ";
					int maso;
					cin>>maso;
					int t=Search(b,maso);
					if(t==0)	
					cout<<"\n khong co mat hang co ma "<<maso<<" trong kho";
					break;		 	 
		}
	
	}while (chon!=4);
	return 0;
}
