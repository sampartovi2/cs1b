#include <iostream>
#include <fstream>
using namespace std;

// function to reverse string w/ pointers
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

// function to merge sorted arrays
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

// function for insertion sort algorithm
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

// allocate memory for array
int ***allocate3DArray(int dim1, int dim2, int dim3)
{
    int ***arr3D = new int **[dim1];
    for (int i = 0; i < dim1; i++)
    {
        arr3D[i] = new int *[dim2];
        for (int j = 0; j < dim2; j++)
        {
            arr3D[i][j] = new int[dim3];
        }
    }
    return arr3D;
}

// read array from file
void fill3DArray(int ***arr3D, int dim1, int dim2, int dim3, const char *filename)
{
    ifstream file(filename);

    for (int i = 0; i < dim1; i++)
    {
        for (int j = 0; j < dim2; j++)
        {
            for (int k = 0; k < dim3; k++)
            {
                file >> *(*(*(arr3D + i) + j) + k); // Using pointer arithmetic
            }
        }
    }
    file.close();
}

// function to print array
void print3DArray(int ***arr3D, int dim1, int dim2, int dim3)
{
    cout << "\n3D Array (from file):" << endl;
    for (int i = 0; i < dim1; i++)
    {
        cout << "Layer " << i + 1 << ":\n";
        for (int j = 0; j < dim2; j++)
        {
            for (int k = 0; k < dim3; k++)
            {
                cout << *(*(*(arr3D + i) + j) + k) << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main()
{

    // SECTION FOR REVERSE STRING
    char str[] = "hello";
    cout << "Original string: " << str << endl;
    reverseString(str);
    cout << "Reversed string: " << str << endl;
    cout << endl;
    // SECTION FOR MERGE STRING
    int arr1[] = {1, 3, 5};
    int arr2[] = {2, 4, 6};
    int mergedArr[8];

    // display original arrays
    cout << "Original arrays:";
    cout << "\nFirst array: ";
    for (int i = 0; i < 3; i++)
        cout << arr1[i] << ". ";
    cout << "\nSecond array: ";
    for (int i = 0; i < 3; i++)
        cout << arr2[i] << ". ";

    mergeArrays(arr1, 3, arr2, 3, mergedArr); // merge arrays
    cout << "\nMerged array: ";
    for (int i = 0; i < 6; i++)
    {
        cout << mergedArr[i] << ". ";
    };
    cout << endl;

    // section for insertion sort
    int arr[] = {4, 2, 7, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    cout << "\nOriginal array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << ". ";
    insertionSort(arr, size);

    cout << "\nInsertion sorted array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << ". ";
    };
    cout << endl;

    // section for 3d array
    int dim1 = 3, dim2 = 4, dim3 = 5;
    int ***arr3D = allocate3DArray(dim1, dim2, dim3);

    fill3DArray(arr3D, dim1, dim2, dim3, "input.txt");

    print3DArray(arr3D, dim1, dim2, dim3);

    return 0;
}