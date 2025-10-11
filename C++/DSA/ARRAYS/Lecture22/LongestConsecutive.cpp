#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        // Step 1: Store all numbers in an unordered_set (hash set)
        // This allows O(1) average lookup and automatically removes duplicates
        unordered_set<int> s(nums.begin(), nums.end());

        // Step 2: Copy elements into a vector so we can use a normal indexed for loop
        vector<int> elements(s.begin(), s.end());

        // Variable to store the length of the longest sequence found
        int longest = 0;

        // Step 3: Loop through all elements in the 'elements' vector
        // This is a standard indexed loop
        for (int i = 0; i < (int)elements.size(); i++)
        {
            int num = elements[i]; // current number we are testing

            // Step 4: Check if this number could be the start of a sequence
            // If num - 1 exists in the set, then this number is NOT the start of a sequence
            // So we skip it to avoid redundant counting
            if (s.find(num - 1) == s.end())
            {
                // num is the start of a sequence
                int currentNum = num;
                int streak = 1; // at least this number itself

                // Step 5: Continue to check for the next consecutive numbers
                // While num+1, num+2, ... exist in the set, keep extending the streak
                while (s.find(currentNum + 1) != s.end())
                {
                    currentNum++; // move to next number
                    streak++;     // increase streak length
                }

                // Step 6: Update the maximum streak length if this one is longer
                if (streak > longest)
                {
                    longest = streak;
                }
            }
            // If num was not the start, we skip it — efficiency gain here
        }

        // Step 7: Return the length of the longest consecutive sequence found
        return longest;
    }
};

// Example usage
int main()
{
    Solution sol;
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << sol.longestConsecutive(nums) << endl; // Expected output: 4
    return 0;
}
