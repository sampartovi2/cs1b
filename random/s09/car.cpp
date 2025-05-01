#include <iostream>
#include <fstream>
using namespace std;

class Car{
    private:
     int year;
     string brand;

    public:
     Car (const string& brand, int year) {
        this->brand = brand;
        this->year = year;
     }
     void display(){
        cout << "Brand: " << this->brand << ", year: " << this->year;
     };
};

int main(){
    Car myCar("Honda", 2015);
    Car myCar2("Toyota", 2020);
    myCar.display();
    cout << endl;
    myCar2.display();
}
