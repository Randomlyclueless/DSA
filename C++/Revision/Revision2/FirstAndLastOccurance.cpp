#include <iostream>
#include <vector>
using namespace std;

// Find First Occurrence of Key
int firstOccurrence(vector<int> &arr, int n, int key)
{
    int start = 0;
    int end = n - 1;
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1; // Keep looking to the left
        }
        else if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}

// Find Last Occurrence of Key
int lastOccurrence(vector<int> &arr, int n, int key)
{
    int start = 0;
    int end = n - 1;
    int ans = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            start = mid + 1; // Keep looking to the right
        }
        else if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {0, 0, 1, 1, 2, 2}; // Sorted input
    int key = 1;
    int n = arr.size();

    int first = firstOccurrence(arr, n, key);
    int last = lastOccurrence(arr, n, key);

    cout << "First Occurrence of " << key << ": " << first << endl;
    cout << "Last Occurrence of " << key << ": " << last << endl;

    return 0;
}
