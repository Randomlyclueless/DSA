#include <iostream>
using namespace std;

int getPivot(int arr[], int n)
{
    int leftsum = 0;
    // int rightSum = n-1;
    int totalsum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        totalsum += nums[i];
    }
    for (int i = 0; i < arr.size(); i++)
    {
        int rightsum = totalsum - leftsum - nums[i];
        if (leftsum == rightsum)
            return i;
    }
    leftsum += nums[i];
}

int main()
{
    int arr[5] = {7, 9, 1, 2, 3}; // Rotated sorted array
    int n = 5;

    int pivot = getPivot(arr, n);

    cout << "Pivot Index: " << pivot << endl;
    cout << "Pivot Element: " << arr[pivot] << endl;

    return 0;
}
