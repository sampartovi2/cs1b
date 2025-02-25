#include <iostream>
using namespace std;

int Digit(int number, int n)
{
    int temp = number; // create temporary number to determine length of number
    int length = 0;

    while (temp > 0)
    {
        temp /= 10;
        length++; // keep track of length by dividing number in powers of 10
    }
    if (n > length || n < 1)
        return -1; // return -1 if position n is not in the number or n is negative

    for (int i = 0; i < length - n; i++) // search until reached desired position (from left)
    {                 
        number /= 10; // divide in powers of 10 to eliminate extra numbers
    }
    return number % 10; // return the remaining number which is at desired position
}

int main()
{
    int input;
    int index;
    int result;

    cout << "Enter an integer: ";
    cin >> input;
    cout << "\nEnter a digit position: ";
    cin >> index;

    result = (Digit(input, index));

    if (result != -1)
    {
        cout << "\nFound " << result << " at position " << index;
    }
    else
        cout << "\nInvalid position, please try again";

    return 0;
}