#include <iostream>
using namespace std;

int partitionFunc(int arr[], int low, int high)
{
    int pivot = arr[high]; // choose last element as pivot
    int i = low - 1;       // pointer for smaller elements

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]); // place pivot in correct position
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partitionFunc(arr, low, high);

        quickSort(arr, low, pi - 1);  // left part
        quickSort(arr, pi + 1, high); // right part
    }
}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = 6;

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
