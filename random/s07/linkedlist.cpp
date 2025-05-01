#include<iostream> 
#include<fstream> 
using namespace std; 

struct Node { 
    int val; 
    Node* next; 
};

//circular linked list
void addToTheEnd(Node*& p, int val) {
    Node* newNode = new Node {val, nullptr}; 
    Node* last;
    if (p == nullptr) { 
        p = newNode;
        p->next = p; 
        return; 
    }
    newNode->next = p->next; 
    p->next = newNode;
    p=newNode;

}

void addToTheBeg(Node*& p, int val) {
    Node* newNode = new Node {val, nullptr}; 
    Node* last;
    if (p == nullptr) { 
        p = newNode;
        p->next = p; 
        return; 
    }
    newNode->next = p->next; 
    p->next = newNode;

}

Node* readListFromFile(string fn = "p0.txt") { 
    ifstream f(fn); 
    Node* t = nullptr; 
    while(!f.eof()) { 
        int x; 
        f >> x; 
        addToTheEnd(t, x); 
    }
    f.close();
    return t; 
}

void printList(Node* tail) { 
    Node* p = tail->next;
    while(p != tail) { 
        cout << p->val << " "; 
        p = p->next;  
    }
    cout << endl; 
}


int main() { 
    Node* tail = nullptr; 
    tail = readListFromFile();
    printList(tail);
}