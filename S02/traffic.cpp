#include <iostream>
#include <thread>
#include <chrono>
using namespace std;
using namespace chrono;
using namespace this_thread;

enum class TrafficLight{
    red,
    green,
    yellow
};

void printLight(TrafficLight light) {
    switch(light){
        case TrafficLight::red:
        cout << "Light is red\n";
        break;
    case TrafficLight::green:
    cout << "Light is green\n";
    break;
    case TrafficLight::yellow:
    cout << "Light is yellow\n";
    break;
    }
}

TrafficLight nextLight(TrafficLight light){
    switch(light)
    {
        case TrafficLight::red:
        return TrafficLight::green;
        case TrafficLight::green:
        return TrafficLight::yellow;
        case TrafficLight::yellow:
        return TrafficLight::red;
        default:
        return TrafficLight::green;
    }

}


int main(){

TrafficLight light = TrafficLight::green;

while(true){
    printLight(light);
    
    this_thread::sleep_for(chrono::seconds(15));
    light = nextLight(light);
}

return 0;
}