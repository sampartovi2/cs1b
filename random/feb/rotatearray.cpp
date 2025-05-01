#include <iostream>
using namespace std;

void rotate_array_right(int array[]){
    int last_index = 6;
    for(int i = 0; i < last_index; i++) {
        array[i] = array[i+1];
        array[0] = array[last_index];
        cout << array[i];
    }
    
}

int main(){
 int array[] = {3, 5, 3, 7, 9, 5, 9};
 rotate_array_right(array);
}