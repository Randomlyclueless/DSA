#include <iostream>
using namespace std;

// Function to swap alternate elements of the array
void Swap_Alt(int arr[], int n)
{
    // Loop through the array with a step of 2 (i.e., index 0, 2, 4, ...)
    for (int i = 0; i < n; i += 2)
    {
        // Check if the next element exists (to avoid going out of bounds)
        if ((i + 1) < n)
        {
            // Swap the current element with the next one
            swap(arr[i], arr[i + 1]);
        }
    }
}

int main()
{
    int n = 5; // Size of the array (you can change this or take input from the user)

    int arr[n]; // Declare an array of size n

    // Input array elements from the user
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Call the function to swap alternate elements
    Swap_Alt(arr, n);

    // Output the modified array
    cout << "Array after swapping alternate elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}
