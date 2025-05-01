#include <iostream>
using namespace std;

int findMissingNumber(int nums[], int size)
{
    int totalSum = (size * (size + 1)) / 2; 
    int arraySum = 0;

    for (int i = 0; i < size; i++)
    {
        arraySum += nums[i]; 
    }

    return totalSum - arraySum; 
}

int main()
{
    int nums[] = {4,6,7};
    int size = sizeof(nums) / sizeof(nums[0]);

    int missingNumber = findMissingNumber(nums, size);
    cout << "Missing number: " << missingNumber << endl;

    return 0;
}
