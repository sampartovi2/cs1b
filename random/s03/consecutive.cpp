#include <iostream>
using namespace std;


void bubbleSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int longestConsecutive(int nums[], int size)
{
    if (size == 0)
        return 0;

    bubbleSort(nums, size); 

    int longest = 1, current = 1;

    for (int i = 1; i < size; i++)
    {
        if (nums[i] == nums[i - 1])
            continue;
        if (nums[i] == nums[i - 1] + 1)
        {
            current++;
        }
        else
        {
            if (current > longest)
                longest = current; 
            current = 1;          
        }
    }

    return (current > longest) ? current : longest;
}

int main()
{
    int nums[] = {100, 4, 200, 1, 3, 2};
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = longestConsecutive(nums, size);
    cout << "Longest consecutive sequence length: " << result << endl;

    return 0;
}
