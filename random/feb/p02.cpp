#include <iostream>
using namespace std;

int power(int base, int exponent)
{
    int result = 1;
    exponent / 2;
    for(int i = 0; i < exponent; i++)
   result += (base * base);
return result;
};

int main()
{
    int num;
    int exp;
    int result;
    cin >> num;
    cin >> exp;

    result = power(num, exp);
    cout << result;

    return 0;
};