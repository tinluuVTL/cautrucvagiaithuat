#include<iostream>
#include<iomanip>
#include<math.h>
#define m 10
using namespace std;


typedef struct bangbam
{
	int Data[m];
	int sopt;
}hashtable;

int hash(int x) 
{
	return x%m;
}


void insert(bangbam &b, int x)
{
	int i = hash(x);
	while (b.Data[i] != 0 && b.sopt<m - 1)i = (++i) % m;
	if (b.sopt<m - 1)
	{
		b.Data[i] = x;
		b.sopt++;
	}
	else
		cout << "\n bang bam da day";
}

void xoa(bangbam &b, int x)
{
	int i = hash(x);
	while (b.Data[i] != x && b.Data[i] != 0)
	{
		i = (++i) % m;
	}
	if (b.Data[i] == x)
	{
		cout << "\n Tim thay gia tri " << x << " tai vi tri " << i << " Bat dau xoa";
		b.Data[i] = 0;
		b.sopt--;
	}
	else
		cout << "\n khong tim thay x";
}
void init(bangbam &b)
{
	b.sopt = 0;
	for (int i = 0; i<m; i++)
		b.Data[i] = 0;
}
void Print(bangbam b)
{
	bool f = false;
	for (int i = 0; i<m; i++)
	{
		if (b.Data[i] != 0)
			cout << setw(5) << b.Data[i] << " luu tru tai vi tri thu " << i << endl;
	}
}
void intheoyeucau(bangbam b)
{
	bool f = false;
	for (int i = 0; i<m; i++)
	{
		if (b.Data[i] != 0)
		if (b.Data[i]%2== 0)
		if (b.Data[i] > 10 && b.Data[i] < 20 ) 
			cout << setw(5) << b.Data[i] << " luu tru tai vi tri thu " << i << endl;
	}
}
int main()
{
	bangbam b;
	init(b); 
	int x;
	cout << "\n Nhap lieu cho bang bam:";
	do{
		 cout << "\n Nhap x, x=-1 ket thuc";
		 cin >> x;
		 if (x == -1)break;
		 insert(b, x);
	  } while (1);
	cout << "\n Du lieu trong bang bam:"<<endl;
	Print(b);
	cout<<" so chan lon hon 10 nho hon 20:"<<endl;
	intheoyeucau(b); 
	cout << "\n Nhap gia tri can xoa: ";
	cin >> x;
	xoa(b, x);
	cout << "\n Du lieu trong bang bam sau khi xoa:" << endl;
	Print(b);
	system("pause");
	return 0;

}

