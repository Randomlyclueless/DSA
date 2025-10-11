#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int longestConsecutive(vector<int> &nums)
{
    // Step 1: Store all elements in an unordered_set for O(1) average-time lookups
    // Also removes duplicates automatically
    unordered_set<int> copy_elements(nums.begin(), nums.end());

    int longest = 0; // Will store the length of the longest consecutive sequence

    // Step 2: Iterate through each unique number in the set
    for (int n : copy_elements)
    {

        // Step 3: Check if n is the start of a new sequence
        // .count(x) returns 1 if x exists in the set, otherwise 0
        // If (n - 1) is NOT present in the set, then n is the starting point of a sequence
        // If (n - 1) exists, then this sequence would have already been counted starting from (n - 1)
        if (!copy_elements.count(n - 1))
        {

            int current_num = n; // Start sequence from n
            int streak = 1;      // Current sequence length

            // Step 4: Keep checking if the next consecutive number exists
            // If it does, move forward and increase the streak count
            while (copy_elements.count(current_num + 1))
            {
                current_num++;
                streak++;
            }

            // Step 5: Update the longest sequence length found so far
            longest = max(longest, streak);
        }
    }

    // Step 6: Return the longest sequence length
    return longest;
}

int main()
{
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    cout << longestConsecutive(nums); // Output: 4
}
