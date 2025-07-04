#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits> // for INT_MAX
using namespace std;

int findShortestSubArray(vector<int> &nums)
{
    unordered_map<int, int> freq_map;    // count of each number
    unordered_map<int, int> first_index; // first appearance
    unordered_map<int, int> last_index;  // last appearance

    // 1️⃣ Go through the array and fill the maps
    for (int i = 0; i < nums.size(); i++)
    {
        int num = nums[i];

        // Increase the frequency
        freq_map[num]++;

        // If this number appears for the first time
        if (first_index.count(num) == 0)
        {
            first_index[num] = i;
        }

        // Always update last index
        last_index[num] = i;
    }

    // 2️⃣ Find the degree of the array (max frequency)
    int degree = 0;
    for (auto it : freq_map)
    {
        if (it.second > degree)
        {
            degree = it.second;
        }
    }

    // 3️⃣ Find the smallest length of subarray with the same degree
    int min_length = INT_MAX;
    for (auto it : freq_map)
    {
        int num = it.first;
        int count = it.second;

        if (count == degree)
        {
            int length = last_index[num] - first_index[num] + 1;
            if (length < min_length)
            {
                min_length = length;
            }
        }
    }

    return min_length;
}
