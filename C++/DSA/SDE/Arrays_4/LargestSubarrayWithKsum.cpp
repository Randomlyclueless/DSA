#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n)
{
    // Hash map to store first occurrence of each prefix sum
    // Key   -> prefix sum value
    // Value -> index where this prefix sum first occurred
    unordered_map<int, int> mpp;

    int maxi = 0; // Stores length of longest subarray with sum 0
    int sum = 0;  // Running prefix sum

    // Traverse the array
    for (int i = 0; i < n; i++)
    {
        sum += A[i]; // Update prefix sum

        // CASE 1: If prefix sum is 0, subarray [0...i] has sum 0
        if (sum == 0)
        {
            maxi = i + 1; // Length = i+1 because index starts from 0
        }
        else
        {
            // CASE 2: If this prefix sum has been seen before
            // mpp.find(sum) returns iterator to the element if found,
            // or mpp.end() if not found
            if (mpp.find(sum) != mpp.end())
            {
                // If found, the subarray between (previous_index+1) and i has sum 0
                // because prefix_sum[i] == prefix_sum[previous_index]
                int prev_index = mpp[sum];
                int length = i - prev_index;
                maxi = max(maxi, length); // Update max length if needed
            }
            else
            {
                // CASE 3: First time seeing this prefix sum
                // Store it in the map with the current index
                mpp[sum] = i;
            }
        }
    }

    return maxi; // Return the length of longest subarray with sum 0
}

int main()
{
    int arr[] = {1, 2, -2, 4, -4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of longest subarray with sum 0: " << maxLen(arr, n);
    return 0;
}
