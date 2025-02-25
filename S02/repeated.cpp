#include <iostream>
using namespace std;

int main()
{
    int array[5] = {8, 1, 2, 9, 2};
    int check;
    for (int i = 0; i < 5; i++)
    {
        check = array[i];
        array[i] = -1;
        for (int j = 0; j < 5; j++)
        {
            if (check == array[j])
                cout << check << " is a duplicate";
        }
        return 0;
    }
}
