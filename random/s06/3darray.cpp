#include <iostream>
#include <fstream>
using namespace std;

//allocate memory for array
int ***allocate3DArray(int dim1, int dim2, int dim3)
{
    int ***arr = new int **[dim1];
    for (int i = 0; i < dim1; i++)
    {
        arr[i] = new int *[dim2];
        for (int j = 0; j < dim2; j++)
        {
            arr[i][j] = new int[dim3];
        }
    }
    return arr;
}

//read array from file
void fill3DArray(int ***arr, int dim1, int dim2, int dim3, const char *filename)
{
    ifstream file(filename);

    for (int i = 0; i < dim1; i++)
    {
        for (int j = 0; j < dim2; j++)
        {
            for (int k = 0; k < dim3; k++)
            {
                file >> *(*(*(arr + i) + j) + k); // Using pointer arithmetic
            }
        }
    }
    file.close();
}

//function to print array
void print3DArray(int ***arr, int dim1, int dim2, int dim3)
{
    cout << "3D Array:" << endl;
    for (int i = 0; i < dim1; i++)
    {
        cout << "Layer " << i + 1 << ":\n";
        for (int j = 0; j < dim2; j++)
        {
            for (int k = 0; k < dim3; k++)
            {
                cout << *(*(*(arr + i) + j) + k) << " "; 
            }
            cout << endl;
        }
        cout << endl;
    }
}


int main()
{
    int dim1 = 3, dim2 = 4, dim3 = 5;
    int ***arr = allocate3DArray(dim1, dim2, dim3);

    fill3DArray(arr, dim1, dim2, dim3, "input.txt"); 

    print3DArray(arr, dim1, dim2, dim3);

    return 0;
}
