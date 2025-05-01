#include<iostream> 
#include<fstream> 
using namespace std; 

struct Node { 
    int val; 
    Node* next; 
    Node* prev;
};

void addToTheEnd(Node*& t, int val) {
    Node* newNode = new Node {val, nullptr}; 
    if (t == nullptr) { 
        t = newNode; 
        t->next = t; 


        return; 
    }
    newNode->next = t->next; // (*newNode).next = (*t).next;
    t->next = newNode;       // (*t).next = newNode; 
    t = newNode;             // t = newNode; 
}

void addToTheBeg(Node*& t, int val) {
    Node* newNode = new Node {val, nullptr}; 
    if (t == nullptr) { 
        t = newNode; 
        t->next = t;         // (*t).next = t; 
        return; 
    }
    newNode->next = t->next; // (*newNode).next = (*t).next;
    t->next = newNode;       // (*t).next = newNode; 
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
    if (tail == nullptr) { return ; }
    Node* p = tail->next; 
    while(p != tail) { 
        cout << p->val << " "; 
        p = p->next;  // p = (*p).next
    }
    cout << p->val << " ";
    cout << endl; 
}

void checkCycle(Node* head){
 
}

void addRandomCycle(Node* head){
 Node* p = head;
 int count = 0;
 while(p->next != nullptr) {
    p = p->next;
    count++;
 }
 srand(time(0));
 int x = rand() % count;
 Node* h = head;
 while(p->next != nullptr && x > 0) {
    p = p->next;
    x--;

 }
 p->next = p;
}


int main() { 
    Node* tail = nullptr; 
    Node* head = nullptr;
    tail = readListFromFile();
    printList(tail);
    checkCycle(head);
    cout <<"checking if cycle";
    addRandomCycle(head);
    cout <<"check again";
    checkCycle(head);

    
}