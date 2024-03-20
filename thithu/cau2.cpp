#include<iostream>
using namespace std;
struct node{
	int data;
	struct node*pLeft;
	struct node*pRight;
};
typedef struct node NODE;
typedef NODE *TREE;

void khoitaocay(TREE &t)
{
	t = NULL;
}

void themnodevaocay(TREE &t, int x)
{
	
	if (t == NULL){
		NODE *p = new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}
	else
	{
		if (t->data > x){
			themnodevaocay(t->pLeft, x);
		}
		else if (t->data < x)/
		{
			themnodevaocay(t->pRight, x);
		}
	}
}

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
		X->data = Y->data;
		X = Y;
		Y = Y->pRight;
	}
}
void xoa_node(TREE &t, int data){
	if (t == NULL)
	{
		return;//ket thúc hàm
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

	

int main()
{
	TREE t;
	khoitaocay(t);
	t=NULL;
	int chon;
	do{
		system("CLS");
		cout<<"\n 1.Nhap cay nhi phan:";
		cout<<"\n 2. In day so giam dan:";
		cout<<"\n 3. Huy node: ";
		cout<<"\n 4. Thoat";	
		cout<<"\n Ban chon:";cin>>chon;
	 
		switch(chon)
		{
			case 1:{
					int n;
			cout << "nhap gia tri n ";
			cin >> n;
			for (int i = 1; i <= n; i++){
				int x;
				cout << "nhap gia tri x ";
				cin >> x;
				themnodevaocay(t, x);
			}
					}break;
			case 2:
					{
					cout << "=====Duyet cay theo RNL=======\n";
			{
				cout<<"\n cac gia tri trong cay giam dan la: "<<endl;
						RNL(t);
						system("pause");
					}
				}break;
			case 3:
					{
							int dem = 0;
			Soluongsole(t, dem);
			cout << "\n So Luong Só le : " << dem;

			system("pause");
					}break;
		case 4: {
			int x;
			cout << "Nhap node can xoa ";
			cin >> x;
			xoa_node(t, x);
			cout << "===== cay sau khi xoa=======\n";
			RNL(t);
			system("pause");
		} 
		}
	}while(chon!=0);
	return 0;
}