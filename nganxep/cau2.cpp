#include<iostream>
using namespace std;
#define m 5
typedef int item;
 
struct Queue{ // hang doi 
    int Front, rear; // giong head teil 
    item Data[m];
    int count;
};
Queue Q;
 
void Make_Q(Queue & Q){
    Q.Front=0;
    Q.rear = -1;
    Q.count=0;
     
}
int rong(Queue & Q){
    if(Q.count==0)
        return 1;
    return 0;
}
 
int day(Queue & Q){
    if(Q.count==m)
        return 1;
    return 0;
}

 
void Insertlast(Queue & Q, item x){
    if(day(Q))
        cout<<"\n Hang doi da day"<<endl;
    else{
        if(Q.rear==(m-1))
            Q.rear=0;
        else
            Q.rear++; 
        Q.Data[Q.rear]=x;
        Q.count++;
    }
}
 
void taodanhsach(Queue & Q){
    item x=0;
    while(x!=-1){
    cout<<"\n Nhap phan tu can them, nhap -1 de ket thuc : "; cin>>x;
    if(x!=-1)
    Insertlast(Q,x);
    }
}
void Print(Queue Q){
      if ( (Q.Front + Q.count ) <= m){
    for(int i=Q.Front; i<(Q.count+Q.Front);i++){
        cout<<"\t"<<Q.Data[i];
    }
      }
}
 void intheoyeucau(Queue &Q, int k){
 	int max=Q.Data[0];
    for(int i=Q.Front; i<(Q.count+Q.Front);i++){
    if(Q.Data[i]>=max)
		max=Q.Data[i];  
    }
    cout<<"So lon nhat la:"<<max<<endl;
      
}
main(){
    Make_Q(Q);
    taodanhsach(Q);
    int k;
  	cout<<"Danh sach cac gia tri da nhap:"; 
    Print(Q);
	cout<<endl;
	intheoyeucau(Q, k);
    return 0;
}