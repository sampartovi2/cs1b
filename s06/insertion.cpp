#include <iostream>
using namespace std;

//function for insertion sort algorithm
void insertionSort(int *arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int pos = *(arr + i);
        int *j = arr + i - 1;

        while (j >= arr && *j > pos)
        {
            *(j + 1) = *j;
            j--;
        }

        *(j + 1) = pos;
    }
}

int main()
{
    int arr[] = {4, 2, 7, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, size);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ". ";
    };
    return 0;
}