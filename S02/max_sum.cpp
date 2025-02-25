#include <iostream>
using namespace std;

int main(){
    int array[10] = {1, -4, -2, 2, 9, -5, 5, -3, 1, -1};
    int start;
    int end;
    int highestsum = array[0];
    int sum = 0;

    for(start = 0; start < 10; start++ ){
for(end = start; end < 10; end++){
    for(int i = start; i <= end; i ++){
        sum += array[i];
        
    }
    if (sum > highestsum) highestsum = sum;
}
} 
cout << highestsum;
}