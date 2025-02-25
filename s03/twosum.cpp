#include <iostream>
using namespace std;

int *twoSum(int nums[], int size, int target)
{
    static int result[2];

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    return nullptr;
}

int main()
{
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int size = sizeof(nums) / sizeof(nums[0]);

    int *result = twoSum(nums, size, target);

    if (result)
    {
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    }
    else
    {
        cout << "No valid pair found" << endl;
    }

    return 0;
}
