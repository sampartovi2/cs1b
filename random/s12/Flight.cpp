#include <iostream>
#include "Flight.h"

using namespace std;
Flight::Flight(): flightNumber(""), originAirport(""), destinationAirport(""), departureTime(""), 
capacity(0), bookedPassengers(0), passengerCount(0) {}

 Flight::Flight(const string& flightNumber, Airport* originAirport, Airport* destinationAirport,
     const string& departureTime, const int capacity, Passenger** bookedPassengers, 
     const int passengerCount) : flightNumber(num), originAirport(origin), destinationAirport(dest),
     departureTime(time), capacity(cap), bookedPassengers(booked), passengerCount(count) {
    //no code
 }
  
 Flight::~Flight(){
    //no code
 }

 void Flight::displayFlight() const{
    cout << "\nFlight number: " << flightNumber;
    cout << "\nOrigin airport: " << originAirport;
    cout << "\nDestination airport: " << destinationAirport;
    cout << "\nDeparture time: " << departureTime;
    cout << "\nCapacity: " << capacity;
    cout << "\nBooked passengers: " << bookedPassengers;
    cout << "\nPassenge count: " << passengerCount;

 }