#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node *temp, *pre, *fir = NULL, *cur;

void InsBF1();
void InsBW();
void InsLast();
void Print();
void Delete();

int main() {
    int ch = 0;
    cout << "Enter 1 for Ins Bf 1 Node\n";
    cout << "Enter 2 for Ins B/W two nodes\n";
    cout << "Enter 3 for Ins at last\n";
    cout << "Enter 4 to Print\n";
    cout << "Enter 5 for deletion\n";
    cout << "Enter 6 to exit\n";
    
    while(ch != 6) {
        cout << "Enter Choice: ";
        cin >> ch;
        switch(ch) {
            case 1: InsBF1(); break;
            case 2: InsBW(); break;
            case 3: InsLast(); break;
            case 4: Print(); break;
            case 5: Delete(); break;
            case 6: break;
            default: cout << "Invalid choice!\n";
        }
    }
}

void InsBF1() {
    temp = new Node;
    cout << "Enter data for First Node: ";
    cin >> temp->data;
    
    temp->prev = NULL;
    temp->next = fir;
    
    if(fir != NULL)
        fir->prev = temp;
        
    fir = temp;
}

void InsBW() {
    if(fir == NULL) {
        cout << "List is empty!\n";
        return;
    }
    
    temp = new Node;
    cout << "Enter data for new Node: ";
    cin >> temp->data;
    
    int pos;
    cout << "After which value? ";
    cin >> pos;
    
    cur = fir;
    while(cur != NULL && cur->data != pos)
        cur = cur->next;
        
    if(cur == NULL) {
        cout << "Value not found!\n";
        delete temp;
        return;
    }
    
    temp->next = cur->next;
    temp->prev = cur;
    
    if(cur->next != NULL)
        cur->next->prev = temp;
        
    cur->next = temp;
}

void InsLast() {
    temp = new Node;
    cout << "Enter data for Last Node: ";
    cin >> temp->data;
    temp->next = NULL;
    
    if(fir == NULL) {
        temp->prev = NULL;
        fir = temp;
    } else {
        cur = fir;
        while(cur->next != NULL)
            cur = cur->next;
            
        cur->next = temp;
        temp->prev = cur;
    }
}

void Delete() {
    if(fir == NULL) {
        cout << "List is empty!\n";
        return;
    }
    
    int val;
    cout << "Enter value to delete: ";
    cin >> val;
    
    cur = fir;
    while(cur != NULL && cur->data != val)
        cur = cur->next;
        
    if(cur == NULL) {
        cout << "Value not found!\n";
        return;
    }
    
    if(cur->prev != NULL)
        cur->prev->next = cur->next;
    else
        fir = cur->next;
        
    if(cur->next != NULL)
        cur->next->prev = cur->prev;
        
    delete cur;
}

void Print() {
    if(fir == NULL) {
        cout << "List is empty!\n";
        return;
    }
    
    cout << "Forward: ";
    cur = fir;
    while(cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    
    cout << "\nBackward: ";
    cur = fir;
    while(cur->next != NULL)
        cur = cur->next;
        
    while(cur != NULL) {
        cout << cur->data << " ";
        cur = cur->prev;
    }
    cout << endl;
}
