#ifndef AIRPORT_H
#define AIRPORT_H

using namespace std;
#include <string>

class Airport{
    private:
        string airportCode;
        string cityName;
    
    public:
        Airport();
        Airport(const string& airportCode, const string& cityName);
        ~Airport();
    
        void displayAirport() const;
 
    };
    
    #endif