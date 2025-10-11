#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    vector<vector<int>> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == s)
            { // Check if the pair sums up to 's'
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j])); // Add the smaller element first
                temp.push_back(max(arr[i], arr[j])); // Then the larger element
                ans.push_back(temp);
            }
        }
    }
    sort(ans.begin(), ans.end()); // Sort the result to meet the problem constraints
    return ans;
}
