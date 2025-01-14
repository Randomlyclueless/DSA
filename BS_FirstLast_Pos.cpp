#include <iostream>
using namespace std;

int firstocc(int arr[], int n, int key)
{
    int s = 0, end = n - 1;
    int mid = s + (end - s) / 2;
    int ans = -1;
    while (s <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            end = mid - 1; // Search in the left half
        }
        else if (key > arr[mid])
        {
            s = mid + 1; // Search in the right half
        }
        else
        {
            end = mid - 1; // Search in the left half
        }
        mid = s + (end - s) / 2;
    }
    return ans;
}

int lastocc(int arr[], int n, int key)
{
    int s = 0, end = n - 1;
    int mid = s + (end - s) / 2;
    int ans = -1;
    while (s <= end)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1; // Search in the left half
        }
        else if (key > arr[mid])
        {
            s = mid + 1; // Search in the right half
        }
        else
        {
            end = mid - 1; // Search in the left half
        }
        mid = s + (end - s) / 2;
    }
    return ans;
}
int main()
{
    int even[5] = {1, 2, 3, 3, 3};
    cout << "First Occurrence of 3 is : " << firstocc(even, 5, 3) << endl;
    cout << "last Occurrence of 3 is : " << lastocc(even, 5, 3) << endl;
    return 0;
}
