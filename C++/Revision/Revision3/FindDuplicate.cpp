// us#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Find Duplicates using Floyd's Cycle Detection
int find_duplicate_floydCycle(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];

    // First phase: find intersection
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    // Second phase: find entry point (duplicate)
    slow = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}

// Find Duplicate using XOR method
int find_duplicate_xor(vector<int> &arr)
{
    int xor1 = 0;
    int xor2 = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        xor2 ^= arr[i];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        xor1 ^= i;
    }
    return xor1 ^ xor2;
}

int main()
{
    // Duplicate example: 1 is repeated
    vector<int> nums = {1, 3, 4, 2, 2};

    cout << "Floyd's Cycle Detection Result: " << find_duplicate_floydCycle(nums) << endl;
    cout << "XOR Method Result: " << find_duplicate_xor(nums) << endl;

    return 0;
}
