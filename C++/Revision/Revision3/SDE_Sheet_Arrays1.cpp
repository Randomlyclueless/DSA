#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
#include <algorithm>
using namespace std;

// Kadanes Algorithm
int maxsubarray(vector<int> &nums)
{
    int n = nums.size();
    int sum = 0;
    int maxi = nums[0];
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        maxi = max(maxi, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
}

// Best time to Buy and Sell Stocks
int maxprofit(vector<int> &arr)
{
    int maxprice = 0;
    int n = arr.size();
    int minprice = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        minprice = min(minprice, arr[i]);
        maxprice = max(maxprice, arr[i] - minprice);
    }
    return maxprice;
}

// Degree of array and smallest subarray with that degree
int findShortestSubArray(vector<int> &nums)
{
    unordered_map<int, int> freq_map, first_index, last_index;
    for (int i = 0; i < nums.size(); ++i)
    {
        int num = nums[i];
        freq_map[num]++;
        if (first_index.count(num) == 0)
        {
            first_index[num] = i;
        }
        last_index[num] = i;
    }
    int degree = 0;
    for (auto it : freq_map)
    {
        degree = max(degree, it.second);
    }
    int min_length = INT_MAX;
    for (auto it : freq_map)
    {
        int num = it.first;
        if (it.second == degree)
        {
            int length = last_index[num] - first_index[num] + 1;
            min_length = min(min_length, length);
        }
    }
    return min_length;
}

// Next Lexicographical Permutation
void NextPermutation(vector<int> &nums)
{
    int pivot = -1;
    int n = nums.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            pivot = i;
            break;
        }
    }
    if (pivot == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }
    for (int i = n - 1; i > pivot; i--)
    {
        if (nums[i] > nums[pivot])
        {
            swap(nums[i], nums[pivot]);
            break;
        }
    }
    reverse(nums.begin() + pivot + 1, nums.end());
}

// Pascal's Triangle
vector<int> getRow(int row)
{
    long long ans = 1;
    vector<int> ansR;
    ansR.push_back(1);
    for (int col = 1; col < row; col++)
    {
        ans = ans * (row - col);
        ans = ans / col;
        ansR.push_back(ans);
    }
    return ansR;
}

vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    for (int i = 1; i <= numRows; i++)
    {
        ans.push_back(getRow(i));
    }
    return ans;
}

int main()
{
    // Kadane's Algorithm
    vector<int> nums1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Maximum Subarray Sum: " << maxsubarray(nums1) << endl;

    // Best time to buy and sell stocks
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << maxprofit(prices) << endl;

    // Degree of array
    vector<int> nums2 = {1, 2, 2, 3, 1, 4, 2};
    cout << "Shortest Subarray Length with Same Degree: " << findShortestSubArray(nums2) << endl;

    // Next Permutation
    vector<int> nums3 = {1, 2, 3};
    NextPermutation(nums3);
    cout << "Next Permutation: ";
    for (int num : nums3)
        cout << num << " ";
    cout << endl;

    // Pascal's Triangle
    int numRows = 5;
    vector<vector<int>> pascal = generate(numRows);
    cout << "Pascal's Triangle:" << endl;
    for (auto row : pascal)
    {
        for (int num : row)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
