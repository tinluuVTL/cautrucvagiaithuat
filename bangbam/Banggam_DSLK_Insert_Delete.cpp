#include<iostream>
#define m 5
using namespace std;

typedef struct Node
{
	int Data;
	Node *Next;
}Nodetype;

typedef  Nodetype *Bucketptr; 
struct BucketList
{
	Bucketptr Head;
	Bucketptr Tail;
};
Bucketptr CreateNode(int x)
{
	Bucketptr p;
	p=new Node;
	p->Data=x;
	p->Next=NULL;
	return p;
}

void InsertLast(BucketList &Bucket,Bucketptr p)
{
	if(Bucket.Head==NULL) Bucket.Head=Bucket.Tail=p;
	else 
		{
			Bucket.Tail->Next=p;
			Bucket.Tail=p;
		}		
}

int Hashf(int key)
{
	return key%m;	
}

void InitBuckets(BucketList Bucket[m])
{
	for(int b=0;b<m;b++)	
		Bucket[b].Head=Bucket[b].Tail=NULL;
}

void Insert(BucketList Bucket[m],int k)
{
	int b;Bucketptr p;
	b=Hashf(k); //b=Hash(6)->1
	p=CreateNode(k);// p=createNode(1)
	InsertLast(Bucket[b],p);// (Bucket[1],p)
}
void CreateBucket(BucketList Bucket[m])
{
	int a[]={10,5,2,1,3,4,6,11};
	int n=sizeof(a)/sizeof(int);
	for(int i=0;i<n;i++)
		Insert(Bucket,a[i]);
	
}
void Print(BucketList Bucket)
{
	Bucketptr p=Bucket.Head;
	while(p!=NULL)
	{
		cout<<p->Data<<"\t"	;
		p=p->Next;
	}
}
void PrintBucket(BucketList Bucket[m])
{
	for(int i=0;i<m;i++)
	{
		cout<<"\n Bucket thu "<<i<<"\t";
		if(Bucket[i].Head!=NULL)
		{
			Print(Bucket[i]);
		}

	}	
}
void DeleteAfter(Bucketptr q,BucketList Bucket)
{
	Bucketptr p;
	if(q!=NULL)
	{
		p=q->Next;
		q->Next=p->Next;
		if(p==Bucket.Tail)Bucket.Tail=q;
		delete p;
	}
}
void DeleteFirst(BucketList &Bucket)
{
	Bucketptr p;
	if(Bucket.Head!=NULL)
	{
		p=Bucket.Head;
		Bucket.Head=p->Next;
		if(Bucket.Head==NULL)Bucket.Tail=NULL;
		delete p;
	}
}
void DeleteX(BucketList Bucket[m],int key)
{
	Bucketptr p,q;
	int b;
	b=Hashf(key);
	p=Bucket[b].Head;
	while(p!=NULL)
	{
		if(p->Data==key)
		{
			if(p==Bucket[b].Head)DeleteFirst(Bucket[b]);
			else
				DeleteAfter(q,Bucket[b]);
			break;
		}
		
		q=p;
		p=p->Next;
	}
	
}
int main()
{
	BucketList Bucket[m];
	InitBuckets(Bucket);
	CreateBucket(Bucket);
	PrintBucket(Bucket);
	cout<<"\n Nhap gia tri can xoa ";
	int key;
	cin>>key;
	DeleteX(Bucket,key);
	PrintBucket(Bucket);
	return 0;
}
