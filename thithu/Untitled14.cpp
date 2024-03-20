#include<iostream>
using namespace std;
struct node{
	int data;
	struct node*pLeft;//node tr�i
	struct node*pRight;//node ph?i
};
typedef struct node NODE;
typedef NODE *TREE;
//kh?i t?o c�y
void khoitaocay(TREE &t)
{
	t = NULL;//c�y r?ng
}
//h�m th�m x v�o c�y
void themnodevaocay(TREE &t, int x)
{
	// c�y r?ng
	if (t == NULL){
		NODE *p = new NODE;//kh?i t?o node d? th�m v�o c�y
		p->data = x;// th�m x v�o data
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;//p l� node g?c
	}
	else//c�y c� ph?n t?
	{
		if (t->data > x){// t nh? hon g?c th�m v�o tr�i
			themnodevaocay(t->pLeft, x);//duy?t qua tr�i d? th�m x
		}
		else if (t->data < x)//t lon hon g?c th�m v�o ph?i
		{
			themnodevaocay(t->pRight, x);//duy?t qua ph?i d? th�m x
		}
	}
}
/*void duyet_RNL(TREE t)
{

		duyet_RNL(t->pLeft);
		cout << t->data << " ";
		duyet_RNL(t->pRight);
	}
}*/
void RNL(TREE t) //giam dan
{
	if(t!=NULL)
	{
		RNL(t->pRight);
		cout << t->data << " ";
		RNL(t->pLeft);
	}
}
bool KiemSoLe(int x){
	if (x % 2 == 0){
		return 0;
	}
	return 1;
}
void Soluongsole(TREE t, int &dem){
	if (t != NULL)
	{
		if (KiemSoLe(t->data) == true)
		{
			dem++;
		}
		Soluongsole(t->pLeft, dem);
		Soluongsole(t->pRight, dem);
	}
}
void NodeTheMang(TREE &X, TREE &Y){
	if (Y->pLeft != NULL){
		NodeTheMang(X, Y->pLeft);
	}
	else
	{
		X->data = Y->data;//c?p nh?p data node c?n x�a thay th�nh data node th? m?ng
		X = Y;
		Y = Y->pRight;
	}
}
void xoa_node(TREE &t, int data){
	if (t == NULL)
	{
		return;//k?t th�c h�m
	}
	else
	{
		if (data < t->data){
			xoa_node(t->pLeft, data);
		}
		else if (data > t->data){
			xoa_node(t->pRight, data);
		}
		else{
			NODE *X = t;
			if (t->pLeft == NULL){
				t = t->pRight;
			}
			else if (t->pRight == NULL){
				t = t->pLeft;
			}
			else{
				NODE *Y = t->pRight;
				NodeTheMang(X, Y);
			}
			delete X;
		}
	}
}
void MENU(TREE &t){
	while (true)
	{
		system("cls");
		cout << "\n\n\t==============MENU==================";
		cout << "\n\n\t1.Them Cay";
		cout << "\n\n\t2.Xuat cay RNL";
		cout << "\n\n\t3.Dem So le";
		cout << "\n\n\t4.Xoa node khoi cay";

		cout << "\n\n\t0.Thoat";
		cout << "\n\n\t==============END==================";
		int luachon;
		cout << "\n\tNhap lua chon ";
		cin >> luachon;
		if (luachon<0 || luachon>4){
			cout << "lua chon k hop le";
			system("pause");
		}
		else if (luachon == 1)
		{
			int n;
			cout << "nhap gia tri n ";
			cin >> n;
			for (int i = 1; i <= n; i++){
				int x;
				cout << "nhap gia tri x ";
				cin >> x;
				themnodevaocay(t, x);
			}
		}
		else if (luachon == 2)
		{
			cout << "=====Duyet cay theo RNL=======\n";
			{
						cout<<"\n cac gia tri trong cay giam dan la: "<<endl;
						RNL(t);
						system("pause");
					}break;
		}
		else if (luachon == 3)
		{
			int dem = 0;
			Soluongsole(t, dem);
			cout << "\nSo Luong S� le : " << dem;

			system("pause");
		}
		else if (luachon==4)
		{
			int x;
			cout << "Nhap node can xoa ";
			cin >> x;
			xoa_node(t, x);
			cout << "===== cay sau khi xoa=======\n";
			RNL(t);
			system("pause");
		}
		else{
			break;
		}
	}
}
int main()
{
	TREE t;
	khoitaocay(t);
	MENU(t);
	system("pause");
	return 0;
}