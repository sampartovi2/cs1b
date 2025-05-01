#include <iostream>
#include <fstream>
using namespace std;

struct Address {
        string city;
        string state;
};

struct Employee {
    int id;
    string name;
    float salary;
    struct Address addr; 
};

void readEmployee(Employee &e1) {
    ifstream f("employees.txt");


}

void displayMenu(Employee &e1){

}


void printEmployee(Employee &e1){
    cout << "\nID: " << e1.id << " , Name: " << e1.name << " , salary: $" << e1.salary << endl;
    cout << "address : " << e1.addr.city << ", " << e1.addr.state;

}

int main(){


    Employee e1;
readEmployee(e1);
printEmployee(e1);
  

}