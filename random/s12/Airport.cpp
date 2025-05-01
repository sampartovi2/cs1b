#include <iostream>
#include "Airport.h"

using namespace std;
Airport::Airport(): airportCode(""), cityName(""){}

 Airport::Airport(const string& code, const string& city) : airportCode(code), cityName(city) {
    //no code
 }
  
 Airport::~Airport(){
    //no code
 }

 void Airport::displayAirport() const{
    cout << "Airport code: " << airportCode;
    cout << "City name: " << cityName;
 }