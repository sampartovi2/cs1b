#include <iostream>
using namespace std;

int primeFactors(int num, int factors[100]) {
 if(num < 2) {
    return -1;
 }
 int count = 0;
 int orig_num = num;

    for (int i = 2; i <= orig_num; i++) {
        while(num % i == 0) {  //check if divisible by current i value
            factors[count++] = i;  //make note of the factor
            num /= i;
        }
    }
 return count;
}

int main() {
    for(;;){ //inf loop
        cout << "Enter a number (-1 to exit): ";
        int x;
        cin >> x;
        if (x == -1) {
            break;
        }
        int factors[100];
        int count = primeFactors(x, factors);
        for(int i = 0; i < count; i++) {
             cout << factors[i] << ", ";
        }
        cout << endl;
    }
    
}