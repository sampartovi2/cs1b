#include "Passenger.h"
#include <iostream>

using namespace std;

Passenger::Passenger(): passengerID(0), name(""), contactEmail(""){}
Passenger::Passenger(int id, const string& name, const string& email) : passengerID(id), name(name), contactEmail(email) {
    //no code
}
Passenger::~Passenger() {
    cout << "Passenger " << this->name << " with id "
        << this-> passengerID << " destroyed\n";
}

void Passenger::displayPassenger() const{
    cout << "\nID: " << passengerID;
    cout << "\nName: " << name;
    cout << "\nEmail: " << contactEmail << endl;
}

int Passenger::getID() const{
    return passengerID;
}


