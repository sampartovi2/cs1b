#include <iostream>
using namespace std;

int* findMax(int* ptr){
    int *maxNum = ptr;
    for(int i = 0; i < 5; i++){
       if (*(ptr+i) > *maxNum) maxNum = (ptr+i);
    }
    return maxNum;
}
int main(){
    int* ptr = new int[5] {1,2,39,5,9};
    cout << findMax (ptr);
}