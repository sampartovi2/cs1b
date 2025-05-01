#include "Product.h"
#include <iostream>

using namespace std;

Product::Product(): productID(0), productName(""), price(0.0){}
Product::Product(int id, const string& name, double price) : productID(id), productName(name), price(price) {}
Product::~Product() {
    cout << "Product " << this->productName << " with id "
        << this-> productID << " destroyed\n";
}

void Product::displayProduct() const{
    cout << "\nID: " << productID;
    cout << "\nName: " << productName;
    cout << "\nPrice: $" << price << endl;
}

double Product::getPrice() const{
    return price;
}
