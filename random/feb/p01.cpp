#include <iostream>
using namespace std;

bool isPrime(int n)
{
    int counter = 0;
    if (n <= 1)
        return false;

    else {
        for (int i = 1; i < n; i++)
        {
            if(n % i == 0) {
                counter++;
        }
        if (counter <= 2) return true;
        else return false;
    }
}

int main()
{
    int n;
    cin >> n;
    if (isPrime(n)) {
        cout << "\n"
             << n << " is prime"};
    else {
        cout << "\n"
             << n << " is not prime"};

    return 0;
}