// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and
//  each integer appears at most twice, return an array of all the
//   integers that appears twice.
// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]

#include <iostream>
#include <vector>
#include <cmath> // for abs()
using namespace std;

// Function to find all elements that appear twice in the array
vector<int> findDuplicates(vector<int> &nums)
{
    vector<int> result;

    // Traverse the array
    for (int i = 0; i < nums.size(); i++)
    {
        // Get the absolute value (in case it's already been marked negative)
        int val = abs(nums[i]);

        // Calculate the index this value would map to (1-based to 0-based)
        int index = val - 1;

        // If the value at that index is already negative, this number is a duplicate
        if (nums[index] < 0)
        {
            result.push_back(val); // It has been seen before, so it's a duplicate
        }
        else
        {
            // Mark the index as visited by negating the value at that position
            nums[index] = -nums[index];
        }
    }

    return result; // Return the list of duplicates
}

int main()
{
    // Sample input
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};

    // Call the function
    vector<int> duplicates = findDuplicates(nums);

    // Output the result
    cout << "Duplicate elements are: ";
    for (int num : duplicates)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
