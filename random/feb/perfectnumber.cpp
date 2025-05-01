#include <iostream>
using namespace std;

bool isPerfectNumber(int n)
{
    int sum = 1; // start with 1 because it's a divisor for all numbers

    for (int i = 2; i * i <= n; i++) // i is for divisors, start at 2 because of 1 and the input number
    {
        if (n % i == 0) // find divisors
        {
            sum += i; // add found divisors to sum
            if (i != n / i)
            {
                sum += n / i;
            }
        }
    }
    return (sum == n && n != 1); // returns true if it's a perfect number
}

int main()
{
    int input;
    cout << "Enter an integer: ";
    cin >> input;

    if (isPerfectNumber(input)) // call isPerfectNumber function
    {
        cout << input << " is a perfect number" << endl;
    }
    else
        cout << input << " is not a perfect number" << endl;
}