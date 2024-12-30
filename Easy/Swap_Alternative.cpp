#include <iostream>
using namespace std;
void swap(int arr[], int size)
{
    for (int i = 0; i < size; i += 2)
    {
        if (i + 1 < size)
        {
            swap(arr[i], arr[i + 1]);
        }
    }
}
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}
int main()
{
    int even[5] = {4, 3, 8, 7, 5};
    swap(even, 5);
    print(even, 5);
}