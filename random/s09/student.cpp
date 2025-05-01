#include <iostream>
#include <fstream>
using namespace std;

class Student{
    private:
     int age;
     string name;

    public:

     void setDetails(int a, string n){
        age = a;
        name = n;
     };

     void getDetails(){
        cout << "Name: "<<  name;
        cout << endl;
        cout << "Age: "<< age;
     };
};

int main(){
    Student student;
    student.setDetails(17, "Jack");
    student.getDetails();
}
