#include <iostream>
using namespace std;



int main(){

    int a[] = {3, 5, 2, 9, 1, 3};
    int firstLine = 0;
    int secondLine = 0;
    int lowest = 0;
    int highest = 0;
    int capacity = 0;
    int maxCapacity = 0;


    for(int i = 0; i <6; i++){
       if(a[i] < a[i+1]) {
        lowest = a[i];
        highest = a[i+1]; }
       else if(a[i] >= a[i+1]) {
        lowest = a[i+1];
        highest = a[i];
       }
        capacity = lowest;
        if(capacity > maxCapacity) {
            maxCapacity = capacity;
            cout << lowest+1 << ", " << highest+1 << ". max capacity: " << maxCapacity  << endl;
 }
 
 

    }
}