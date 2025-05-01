#include <iostream>
#include "Passenger.h"
#include "Airport.h"
using namespace std;

Passenger* getPassenger(){
    //dont need to ask for id
    string name;
    string contactEmail;

    cout << "\nEnter name: ";
    cin >> name;
    cout << "\nEnter email: ";
    cin >> contactEmail;
    cout << endl;

    return new Passenger(1, name, contactEmail);
}

Airport* getAirport(){
    //dont need to ask for id
    string city;
    string code;

    cout << "\nEnter city name: ";
    cin >> city;
    cout << "\nEnter airport code: ";
    cin >> code;
    cout << endl;

    return new Airport(code, city);
}

int main(){
    Passenger* p = getPassenger();

    p->displayPassenger();
}