#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int m)
{
    int i = m + 1, j = arr.size() - 1;
    while (i < j)
    {
        swap(arr[i], arr[j]);
        i++;
        j--;
    }
}

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }
    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
    }
}

// brute force for move zeroes
void moveZeroesBrute(vector<int> &nums)
{
    vector<int> temp;
    for (int num : nums)
    {
        if (num != 0)
            temp.push_back(num);
    }
    int zeros = nums.size() - temp.size();
    while (zeros--)
        temp.push_back(0);
    for (int i = 0; i < nums.size(); i++)
    {
        nums[i] = temp[i];
    }
}

// optimal solution for move zeroes
void moveZeroesOptimal(vector<int> &nums)
{
    int i = 0;
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] != 0)
        {
            swap(nums[j], nums[i]);
            i++;
        }
    }
}

int main()
{
    // Test reverseArray
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    reverseArray(arr, 2); // reverse part after index 2
    cout << "After reverseArray: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    // Test merge
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    merge(nums1, 3, nums2, 3);
    cout << "After merge: ";
    for (int x : nums1)
        cout << x << " ";
    cout << endl;

    // Test moveZeroes brute force
    vector<int> nums3 = {0, 1, 0, 3, 12};
    moveZeroesBrute(nums3);
    cout << "After moveZeroes (Brute): ";
    for (int x : nums3)
        cout << x << " ";
    cout << endl;

    // Test moveZeroes optimal
    vector<int> nums4 = {0, 1, 0, 3, 12};
    moveZeroesOptimal(nums4);
    cout << "After moveZeroes (Optimal): ";
    for (int x : nums4)
        cout << x << " ";
    cout << endl;

    return 0;
}
