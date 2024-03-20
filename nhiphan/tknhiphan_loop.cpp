#include<iostream>

using namespace std;

int timkiemtuantu(int a[],int n, int x)
{
	for(int i=0;i<n;i++)
	 	if(a[i]==x) return i;
 	return -1;
}
int timkiemnhiphan(int a[],int n, int x, int left,int right)
{
	int mid;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(a[mid]==x)return mid;
		else if(a[mid]>x)right=mid-1;
		else left=mid+1;
	}
	return -1;
}
int main()
{
	// thuat toan tim kiem tuan tu(tuyen tinh)
	
	int a[]={3,7,15,55,99};
	int n=sizeof(a)/sizeof(int);
	int x=100;
	//cout<<timkiemtuantu(a,n,x);
	cout<<timkiemnhiphan(a,n,x,0,n-1);
	return 0;
}