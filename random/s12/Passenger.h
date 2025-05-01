#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
using namespace std;

class Passenger{
private:
    int passengerID;
    string name;
    string contactEmail;

public:
    Passenger();
    Passenger(int id, const string& name, const string& email);
    ~Passenger();

    void displayPassenger() const;
    int getID() const;
    string getName() const;
    string getEmail() const;

};

#endif