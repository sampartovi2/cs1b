#include <iostream>
#include <string>
using namespace std;

int BinarySearch(int num, int array[10])
{
    int lastIndex = 5;
    int middle = 0;
    
    while (num != middle)
    {
    middle = lastIndex/2;
    if(num != middle) {
        if (num < middle) lastIndex = middle;
        else middle = lastIndex / middle;

    }
    if(num == middle) return middle;

            
    }
    return 0;
}

int main()
{
    int* a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int num = 5;
    if (BinarySearch(num, a))
    {
        cout << "Found";
        }
    else
        cout << " Not found ";
    return 0;
}