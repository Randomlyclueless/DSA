#include <iostream>
#include <vector>
using namespace std;

// Function to find duplicates in the array
// It modifies the array temporarily to mark visited numbers
vector<int> findduplicates(vector<int> &num)
{
    vector<int> result;

    // Loop through all elements in the array
    for (int i = 0; i < num.size(); i++)
    {
        int val = abs(num[i]); // Get the absolute value of current number
        int index = val - 1;   // Convert it to index (since array is 0-based)

        // If the number at this index is already negative,
        // it means we've seen this number before => it's a duplicate
        if (num[index] < 0)
        {
            result.push_back(val); // Add it to the result list
        }
        else
        {
            // First time we're seeing this number, mark it as visited by making it negative
            num[index] = -num[index];
        }
    }

    return result; // Return all duplicates found
}

int main()
{
    vector<int> arr = {1, 3, 4, 2, 5, 3}; // Array with a duplicate value (3)

    // Call the function to find duplicates
    vector<int> duplicates = findduplicates(arr);

    // Print all duplicates found
    cout << "Duplicate number(s): ";
    for (int val : duplicates)
    {
        cout << val << " ";
    }
    cout << "Time Complexity is O(n)" << endl;

    return 0;
}
