#include <iostream>
using namespace std;

bool linearSearch(int arr[], int size, int key)
{
    // Base case: size 0 → key not found
    if (size == 0)
        return false;

    // Check first element
    if (arr[0] == key)
        return true;

    // Search in remaining array
    return linearSearch(arr + 1, size - 1, key);
}

int main()
{
    int arr[] = {5, 3, 8, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 8;

    if (linearSearch(arr, n, key))
        cout << "Key found\n";
    else
        cout << "Key not found\n";
}
