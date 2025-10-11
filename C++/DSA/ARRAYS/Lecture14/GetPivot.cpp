
#include <iostream>
using namespace std;
int GetPivot(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (arr[mid] > arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}
int main()
{
    // Write C++ code here
    int arr[5] = {3, 8, 10, 7, 1};
    cout << GetPivot(arr, 5);
}