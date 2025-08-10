#include <iostream>
using namespace std;

bool isSorted(int arr[], int size)
{
    // Base case: 0 or 1 element is always sorted
    if (size == 0 || size == 1)
        return true;

    // If first element is bigger than second → not sorted
    if (arr[0] > arr[1])
        return false;

    // Recursive call on remaining array
    return isSorted(arr + 1, size - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (isSorted(arr, n))
        cout << "Array is sorted\n";
    else
        cout << "Array is not sorted\n";
}
