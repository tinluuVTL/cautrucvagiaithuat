#include<iostream>
using namespace std;
struct node{
	int data;
	struct node*pLeft;//node trái
	struct node*pRight;//node ph?i
};
typedef struct node NODE;
typedef NODE *TREE;
//kh?i t?o cây
void khoitaocay(TREE &t)
{
	t = NULL;//cây r?ng
}
//hàm thêm x vào cây
void themnodevaocay(TREE &t, int x)
{
	// cây r?ng
	if (t == NULL){
		NODE *p = new NODE;//kh?i t?o node d? thêm vào cây
		p->data = x;// thêm x vào data
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;//p là node g?c
	}
	else//cây có ph?n t?
	{
		if (t->data > x){// t nh? hon g?c thêm vào trái
			themnodevaocay(t->pLeft, x);//duy?t qua trái d? thêm x
		}
		else if (t->data < x)//t lon hon g?c thêm vào ph?i
		{
			themnodevaocay(t->pRight, x);//duy?t qua ph?i d? thêm x
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
		X->data = Y->data;//c?p nh?p data node c?n xóa thay thành data node th? m?ng
		X = Y;
		Y = Y->pRight;
	}
}
void xoa_node(TREE &t, int data){
	if (t == NULL)
	{
		return;//k?t thúc hàm
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
			cout << "\nSo Luong Só le : " << dem;

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