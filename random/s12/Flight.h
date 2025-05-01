#ifndef FLIGHT_H
#define FLIGHT_H
#include "Airport.h"
#include "Passenger.h"

using namespace std;
#include <string>

class Flight{
    private:
        string flightNumber;
        Airport* originAirport;
        Airport* destinationAirport;
        string departureTime;
        int capacity;
        Passenger** bookedPassengers;
        int passengerCount;
    
    public:
        Flight();
        Flight(const string& fn, Airport* origin, Airport* dest, 
        const string& time, int cap);
        ~Flight();
    
        void displayFlight() const;
 
    };
    
    #endif