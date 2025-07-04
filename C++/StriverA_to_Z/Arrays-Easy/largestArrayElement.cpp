// Problem statement
// Given an array ‘arr’ of size ‘n’ find the largest element in the array.
// Expmple:
// Input: 'n' = 5, 'arr' = [1, 2, 3, 4, 5]
// Output: 5
// Explanation: From the array {1, 2, 3, 4, 5}, the largest element is 5.

#include <bits/stdc++.h>
int largestElement(vector<int> &arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = 5;
    cout << largestElement(arr, n);
    return 0;
}