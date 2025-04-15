#include <iostream>
#include <string>
using namespace std;

//function to reverse string w/ pointers
void reverseString(char *str)
{
    char temp = 0;
    char *start = str;
    char *end = str; // temporary value before finding real end
    while (*end != '\0')
    {
        end++; // increment the end until newline character reached
    }
    end--; // decrement to end at last value

    while (start < end)
    {
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main()
{
    char str[] = "hello";
    reverseString(str);
    cout << str;
}