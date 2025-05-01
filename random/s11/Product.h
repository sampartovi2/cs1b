#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;

class Product{
private:
    int productID;
    string productName;
    double price;

public:
    Product();
    Product(int id, const string& name, double price);
    ~Product();

    void displayProduct() const;
    double getPrice() const;
};

#endif