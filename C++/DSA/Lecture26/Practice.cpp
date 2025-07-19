#include <iostream>
using namespace std;

int main()
{
    // Declaring an array of size 10, initializing first 3 elements
    int arr[10] = {2, 5, 6};

    // Prints the address of the first element of the array
    cout << "Address of first memory block is: " << arr << endl;

    // Prints the value at index 0 (i.e., first element)
    cout << "Value at arr[0]: " << arr[0] << endl;

    // Prints the address of arr[0] explicitly
    cout << "Address of arr[0] using &arr[0]: " << &arr[0] << endl;

    // Dereferencing arr gives value at arr[0] because arr is a pointer to arr[0]
    cout << "Value at *arr (same as arr[0]): " << *arr << endl;

    // Adds 1 to the value at arr[0] (2 + 1 = 3)
    cout << "*arr + 1 (value at arr[0] + 1): " << *arr + 1 << endl;

    // *(arr + 1) accesses second element (arr[1] = 5)
    cout << "Value at *(arr + 1) (i.e., arr[1]): " << *(arr + 1) << endl;

    // *(arr) + 1 = value at arr[0] (2) + 1 = 3
    cout << "Value at *(arr) + 1 (arr[0] + 1): " << *(arr) + 1 << endl;

    // Direct access of 3rd element of array
    cout << "arr[2]: " << arr[2] << endl;

    
}
