#include<iostream>
using namespace std;
struct Node {
    int data ;
    Node* next;
};
Node *temp,*pre,*fir=NULL,*cur;

void InsBF1();
void InsBW();
void InsLast();
void Print();
void Delete();

int main() {

    int ch=0;
    cout<<"Enter 1 for Ins Bf 1 Node"<<endl;
    cout<<"Enter 2 for Ins B/W two nodes"<<endl;
    cout<<"Enter 3 for Ins at last"<<endl;
    cout<<"Enter 4 to Print"<<endl;
    cout<<"Enter 5 for deletion"<<endl;
    cout<<"Enter 6 to exit "<<endl;
    while(ch!=6) {
        cout<<"Enter Choice "<<endl;
        cin>>ch;
        if(ch==1)
            InsBF1();
        else if(ch==2)
            InsBW();
        else if(ch==3)
            InsLast();
        else if(ch==4)
            Print();
        else if(ch==5)
            Delete();
        else
            cout<<"Invalid choice! Try Again"<<endl;
    }
}

void InsBF1() {
    temp=new Node;
    cout<<"Now Enter data for First Node "<<endl;
    cin>>temp->data;
    temp->next=fir;
    fir=temp;
}

void InsBW() {
    if(fir==NULL) {
        cout<<"The list is empty! Ins not possible"<<endl;
        return;
    }
    temp=new Node;
    cout<<"Enter data for new Node"<<endl;
    cin>>temp->data;
    pre=fir;
    cur=fir->next;
    while(cur!=NULL && temp->data>cur->data) {
        pre=cur;
        cur=cur->next;
    }
    pre->next=temp;
    temp->next=cur;
}

void InsLast() {
    temp=new Node;
    cout<<"Enter data for Last Node"<<endl;
    cin>>temp->data;
    temp->next=NULL;
    if(fir==NULL)
        fir=temp;
    else {
        cur=fir;
        while(cur->next!=NULL) {
            cur=cur->next;
        }
        cur->next=temp;
    }
}

void Delete() {
    if(fir==NULL) {
        cout<<"List is already Empty."<<endl;
        return;
    }
    int val;
    cout<<"Enter the value to be delete"<<endl;
    cin>>val;
    if(val==fir->data) {
        temp=fir;
        fir=fir->next;
        delete(temp);
    }
    pre=fir;
    cur=fir->next;
    while(cur->data!=val && cur!=NULL) {
        pre=cur;
        cur=cur->next;
    }
    if(cur==NULL) {
        cout<<"Value not found in List"<<endl;
        return;
    }
    pre->next=cur->next;
    delete(cur);
}

void Print() {
    cur=fir;
    cout<<"The nodes are "<<endl;
    while(cur!=NULL) {
        cout<<cur->data<<"\t"<<cur<<endl;
        cur=cur->next;
    }
}
