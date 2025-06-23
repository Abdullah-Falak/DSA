#include<iostream>
using namespace std;
int cq[6],f=0,r=0,n=5;
void ins();
void del();
void print();
int  main()
{
	int choice=0;
	while(choice!=4)
	{
		cout<<"1 :    insertion"<<endl;
		cout<<"2 :    deletion"<<endl;
		cout<<"3 :   print"<<endl;
		cout<<"4 :    exit"<<endl;
		cout<<"enter your choice"<<endl;
		cin>> choice;
		if(choice==1)
		ins();
		else if (choice==2)
		del();
		else if (choice==3)
		print();
		else if (choice!=4)
		cout<<"invalid choice";
	}
}
void ins()
{
	int no;
	if ((f==1 && r>=n ) || (f-r==1))
	cout<<"overflow";
	else {
		cout<<"enter a new element";
		cin>>no;
		if (f==0 && r==0)
		{
			f++;
			r++;
		}
		else if(r==n)
		{
			r=1;
		}
		else 
			r++;
			cq[r]=no;
	}	
}
void del()
{
	int temp=0;
	if (f==0 && r==0 )
	cout<<"underflow";
	else{
		temp=cq[f];
		cq[f]=0;
		if (f==r){
			f=0;
			r=0;
		}
		else if(f==n)
		f=1;
		else{
			f++;
		}
		cout<<"deleted element"<<temp<<endl;
	}
}
void print(){
	for(int i=0; i<=n; i++)
		cout<<"Values are"<<cq[i]<<" ";
		cout<<endl;
	cout<<"front= "<<f<<endl;
	cout<<"rear=  "<<r<<endl;
}