#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

// 1. Find intersection of two sorted arrays
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    int i = 0, j = 0;
    vector<int> ans;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}

// 2. Find all pairs that sum to a target
vector<vector<int>> Find2Sum(vector<int> &arr, int s)
{
    vector<vector<int>> ans2;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == s)
            {
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans2.push_back(temp);
            }
        }
    }
    sort(ans2.begin(), ans2.end());
    return ans2;
}

// 3. Find all triplets that sum to a target
vector<vector<int>> findTriplets(vector<int> arr, int n, int target)
{
    vector<vector<int>> ans3;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (i != 0 && arr[i] == arr[i - 1])
            continue;

        int j = i + 1;
        int k = n - 1;

        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < target)
            {
                j++;
            }
            else if (sum > target)
            {
                k--;
            }
            else
            {
                ans3.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
    }
    return ans3;
}

// 4. Dutch National Flag Problem (sort 0s, 1s, 2s)
void DutchFlag(vector<int> &arr)
{
    int start = 0, mid = 0, end = arr.size() - 1;

    while (mid <= end)
    {
        if (arr[mid] == 0)
        {
            swap(arr[start], arr[mid]);
            start++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[end]);
            end--;
        }
    }
}

// 5. Driver Function (main)
int main()
{
    // 1. Test Array Intersection
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {3, 4, 5, 6};
    vector<int> intersection = findArrayIntersection(arr1, arr1.size(), arr2, arr2.size());
    cout << "Intersection: ";
    for (int x : intersection)
        cout << x << " ";
    cout << endl;

    // 2. Test Find2Sum
    vector<int> arr3 = {1, 2, 3, 4, 5};
    int sumTarget = 5;
    vector<vector<int>> pairs = Find2Sum(arr3, sumTarget);
    cout << "Pairs with sum " << sumTarget << ": ";
    for (auto &p : pairs)
        cout << "[" << p[0] << "," << p[1] << "] ";
    cout << endl;

    // 3. Test FindTriplets
    vector<int> arr4 = {1, 2, -1, 0, -2, 1};
    int tripletSum = 0;
    vector<vector<int>> triplets = findTriplets(arr4, arr4.size(), tripletSum);
    cout << "Triplets with sum " << tripletSum << ": ";
    for (auto &t : triplets)
        cout << "[" << t[0] << "," << t[1] << "," << t[2] << "] ";
    cout << endl;

    // 4. Test Dutch National Flag
    vector<int> arr5 = {0, 1, 2, 0, 1, 2, 1, 0};
    DutchFlag(arr5);
    cout << "Sorted 0s, 1s, 2s: ";
    for (int x : arr5)
        cout << x << " ";
    cout << endl;

    return 0;
}
