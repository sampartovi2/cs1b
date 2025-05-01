#include "Product.h"
#include <iostream>

using namespace std;

int main(){
    Product* product = new Product(12, "A great book", 20.0);
    product->displayProduct();
    delete product;  //destructor is called
    
    // int id;
    // string name;
    // double price;

    // cout << "\nEnter product ID: ";
    // cin >> id;
    // cout << "\nEnter name: ";
    // cin >> name;
    // cout << "\nEnter price:";
    // cin >> price;

    // Product product(id, name, price);
    // // product->displayProduct();

    // return 0;


}