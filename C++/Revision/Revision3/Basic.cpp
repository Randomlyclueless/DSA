// Calculate number of SetBits in an integer
#include <iostream>
using namespace std;

// Swap alternate elements of an array
void swap_alternatives(int arr[], int n)
{
    for (int i = 0; i < n; i += 2)
    {
        if ((i + 1) < n)
        {
            swap(arr[i], arr[i + 1]);
        }
    }
}

int main()
{
    int arr[6] = {2, 1, 4, 3, 6, 5};

    swap_alternatives(arr, 6); // Pass full array length

    cout << "Array after swapping alternate elements: ";
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
