#include<iostream>
using namespace std;
int LQ[6];
int FE=0;
int RE=0;
int N=5;
void EnQuene();
void DeQuene();
void Print();

int main() {
    int choice=0;
    while(choice!=4) {
        cout<<"Enter 1 to EnQuene"<<endl;
        cout<<"Enter 2 to DeQuene"<<endl;
        cout<<"Enter 3 to Print Quene"<<endl;
        cout<<"Enter 4 to Exit Program"<<endl;
        cout<<"Enter Choice"<<endl;
        cin>>choice;
        if(choice==1)
            EnQuene();
        else if(choice==2)
            DeQuene();
        else if(choice ==3)
            Print();
        else if(choice!=4)
            cout<<"Invalid Choice"<<endl;
    }


}


void EnQuene() {
    int val;
    if(RE>=N) {
        cout<<"OverFlow"<<endl;
    }
    else {
        cout<<"Enter the value to Insert"<<endl;
        cin>>val;
        //Increment the values of FR & RE


        LQ[RE]=val;
        RE=RE+1;
    }
}

void Print() {
    if(FE==RE) {
        cout<<"Quene is already Empty"<<endl;
    }
    else {

        for(int a=FE; a<RE; a++) {
            cout<<"Value in Quene "<< a+1 <<" is "<<LQ[a]<<endl;
        }
    }


}
void DeQuene() {
    int temp=0;
    //check UnderFlow
    if(FE==RE) {
        cout<<"UnderFlow"<<endl;
    }
    else {
        temp=LQ[FE];
        for(int i=FE; i<RE-1; i++) {
            LQ[i]=LQ[i+1];
        }
        RE--;
        cout<<"The value is deleted from Quene = "<<temp<<endl;
    }
}

    