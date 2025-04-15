#include <iostream>
using namespace std;

void pointerSwap(int *a, int *b){
 
 int temp = *a;
 *a = *b;
 *b = temp;


}
int main(){
 int a[] = {1, 2, 3};
 pointerSwap(&a[1], &a[2]);
 }
