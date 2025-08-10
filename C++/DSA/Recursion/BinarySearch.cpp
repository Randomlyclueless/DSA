#include <iostream>
using namespace std;

bool binarySearch(int arr[], int start, int end, int key)
{
    // Base case: no elements left
    if (start > end)
        return false;

    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
        return true;
    else if (key < arr[mid])
        return binarySearch(arr, start, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, end, key);
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    if (binarySearch(arr, 0, n - 1, key))
        cout << "Key found\n";
    else
        cout << "Key not found\n";
}
