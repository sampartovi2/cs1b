#include <iostream>
using namespace std;

void remove_duplicates(int array[]){
   
for(int i = 0; i < 7; i++){
    for(int j = 0; j < 7; j++) {
        if(array[j] == array[i]) {
            array[i] == 0;
        }
       
    } 
     cout << array[i] << " ";
}
}

int main(){
 int array[] = {1, 2, 3, 3, 5, 5, 5};
 remove_duplicates(array);

}