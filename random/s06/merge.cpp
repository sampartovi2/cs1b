#include <iostream>
#include <string>
using namespace std;

//function to merge sorted arrays
void mergeArrays(int *arr1, int size1, int *arr2, int size2, int mergedArr[])
{
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2)
    {
        if (arr1[i] < arr2[j])
        {
            mergedArr[k++] = arr1[i++];
        }
        else
        {
            mergedArr[k++] = arr2[j++];
        }
    }

    while (i < size1)
    {
        mergedArr[k++] = arr1[i++];
    }

    while (j < size2)
    {
        mergedArr[k++] = arr2[j++];
    }
}

int main()
{
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};
    int mergedArr[8];

    mergeArrays(arr1, 3, arr2, 3, mergedArr);
    cout << "Merged array: ";
    for (int i = 0; i < 6; i++)
    {
        cout << mergedArr[i];
    };
    return 0;
}