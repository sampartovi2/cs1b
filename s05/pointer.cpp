#include <iostream>
using namespace std;

int main(){
    int size = 5;
    int a[size] = {1, 2, 9, 8, 5};
    int *ptr = a;

    for(int i=0; i< size; i++) {
        cout << *(ptr+i) << ". ";
    }
}