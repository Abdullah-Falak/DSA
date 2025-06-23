#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
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
    
    if(fir == NULL) {
        fir = temp;
        temp->next = fir;
    } else {
        temp->next = fir->next;
        fir->next = temp;
        // Swap data to make it appear at beginning
        int t = fir->data;
        fir->data = temp->data;
        temp->data = t;
    }
}

void InsBW() {
    if(fir == NULL) {
        cout << "List is empty!\n";
        return;
    }
    temp = new Node;
    cout << "Enter data for new Node: ";
    cin >> temp->data;
    
    pre = fir;
    cur = fir->next;
    while(cur != fir && temp->data > cur->data) {
        pre = cur;
        cur = cur->next;
    }
    pre->next = temp;
    temp->next = cur;
}

void InsLast() {
    temp = new Node;
    cout << "Enter data for Last Node: ";
    cin >> temp->data;
    temp->next = fir;
    
    if(fir == NULL) {
        fir = temp;
    } else {
        cur = fir;
        while(cur->next != fir)
            cur = cur->next;
        cur->next = temp;
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
    
    if(fir->data == val) {
        temp = fir;
        if(fir->next == fir) {
            fir = NULL;
        } else {
            cur = fir;
            while(cur->next != fir)
                cur = cur->next;
            cur->next = fir->next;
            fir = fir->next;
        }
        delete temp;
        return;
    }
    
    pre = fir;
    cur = fir->next;
    while(cur != fir && cur->data != val) {
        pre = cur;
        cur = cur->next;
    }
    
    if(cur == fir) {
        cout << "Value not found!\n";
    } else {
        pre->next = cur->next;
        delete cur;
    }
}

void Print() {
    if(fir == NULL) {
        cout << "List is empty!\n";
        return;
    }
    
    cout << "List elements: ";
    cur = fir;
    do {
        cout << cur->data << " ";
        cur = cur->next;
    } while(cur != fir);
    cout << endl;
}
