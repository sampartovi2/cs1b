#include <iostream>
using namespace std;

string reverse(const string &input)
{
    string res = "";
   
    for (int i = 0; i <= input.length(); i++)
    {
    res = input[i] +res;
    }
    return res;
}

int main()
{
    string input;
    cin >> input;
   cout <<  reverse(input);

    return 0;
}