#include <iostream>
using namespace std;

int findMaxIn2DArray(int arr[5][5], int rows)
{
    int maximum = arr[0][0];  //maximum is initially first number
    for (int i = 0; i < rows; i++) //i is for rows
    {
        for (int j = 0; j < 5; j++) //j is for columns - set for 5 columns
        {
            if (arr[i][j] > maximum)
            {
                maximum = arr[i][j];  //if a number larger than current maximum is found, assign it to maximum
            }
        }
    }
    return maximum;
}

int main()
{
    int array[5][5] = {
        {1, 2, 3, 4, 5},
        {21, 22, 23, 24, 25},
        {11, 12, 13, 14, 15},
        {6, 7, 8, 9, 10},
        {16, 17, 18, 19, 20}};

    int numRows = 5;

    int maxNum = findMaxIn2DArray(array, numRows);
    cout << "Largest element in array is " << maxNum << endl;
}