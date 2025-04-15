#include <iostream>
using namespace std;

int *getArray(int count){
 int *array = new int[count];
 cout << "Enter numbers to add to the array: ";
 for(int i = 0; i < count; i++){
    cin >> array[i];
 }
 return array;
}

void printArray(int* array, int count){
 for(int i = 0; i < count; i++){
    cout << array[i] << ". ";
 }
}

int main(){
 int* array = getArray(3);
 printArray(array, 3);
}