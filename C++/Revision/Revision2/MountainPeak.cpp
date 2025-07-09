#include <iostream>
#include <vector>
using namespace std;

// Function to find the peak index in a mountain array
int findPeakIndex(vector<int> &arr)
{
    int s = 0;              // Initialize start of binary search
    int e = arr.size() - 1; // Initialize end of binary search

    // Binary search loop to find the peak
    while (s < e)
    {                              // Continue as long as search space is valid
        int mid = s + (e - s) / 2; // Calculate mid to avoid integer overflow

        if (arr[mid] < arr[mid + 1])
        {
            // You're in the **increasing** part of the mountain
            s = mid + 1; // Move start to the right
        }
        else
        {
            // You're in the **decreasing** part of the mountain
            e = mid; // Keep mid in search space because it could be the peak
        }
    }

    return s; // At the end, start == end, and both point to the peak index
}

int main()
{
    vector<int> mountain = {1, 3, 5, 7, 6, 4, 2}; // Example of a mountain array

    int peak = findPeakIndex(mountain); // Call function to get the peak index

    cout << "Peak Index: " << peak << endl; // Print the result

    return 0;
}
