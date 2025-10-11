// You have been given an integer array/list(ARR) of size 'N'. It only contains 0s, 1s and 2s.
// Write a solution to sort this array/list.

// Note :
// Try to solve the problem in 'Single Scan'. ' Single Scan' refers to iterating over the array/list just once or to put it in other words, you will be
// visiting each element in the array/list just once.

#include <iostream>
#include <vector>
using namespace std;

// Function to sort array of 0s, 1s and 2s in one scan
void sortColors(vector<int> &arr)
{
    int low = 0;               // Pointer for 0s
    int mid = 0;               // Current index
    int high = arr.size() - 1; // Pointer for 2s

    // Traverse the array in a single scan
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            // Swap current element with low pointer
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            // 1 is in the correct position
            mid++;
        }
        else
        {
            // Swap current element with high pointer
            swap(arr[mid], arr[high]);
            high--;
            // We do not increment mid here because we need to recheck the swapped element
        }
    }
}

int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};

    cout << "Original array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    sortColors(arr);

    cout << "Sorted array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
