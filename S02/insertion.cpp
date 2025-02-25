#include <iostream>
using namespace std;



int main()
{
    int size = 10;
    int array[size] = {18, 255, 232, 7, 94, 389, 9, 15, 23, 10};
    int temp;
  
    for (int i = 0; i < size; i++)
    {
        for (int i = size; i > 0; i--)
        {
            if (array[i] < array[i - 1])
            {
                temp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = temp;
            }
        }
  
        cout << " " << array[i];
    }
}