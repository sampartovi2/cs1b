#include <iostream>
#include <fstream>
using namespace std;

class Car{
    private:
     int year;
     string brand;

    public:
     Car (string b, int y) : brand(b), year(y){}
     void display(){
        cout << "Brand: " << this->brand << ", year: " << this->year;
     };
};

int main(){
    Car myCar("Honda", 2015);
    Car myCar2("Toyota", 2020);
    myCar.display();
    myCar2.display();
}
