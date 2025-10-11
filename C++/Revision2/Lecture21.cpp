// class Solution {
// public:
void rotate(vector<int> &nums, int k)
{
    // Brute Force
    // k is num of stemps to rotate
    int n = nums.size();
    // n%k gives rotationsexplain brute
    k = k % n;
    // outer loop - repeat k rotations
    for (int r = 0; r < k; r++)
    {
        // step 1- save the last element
        int last = nums[n - 1];
        for (int i = n - 1; i > 0; i--)
        {
            // shift right
            nums[i] = nums[i - 1];
        }
        // place saved element at front
        nums[0] = last;
    }
}

// Input: nums = [1,2,3,4,5,6,7], k=3

// Before loop: n=7, k=3
// 1st rotation:
// Save last=7
// Shift → [1,1,2,3,4,5,6]
// Put 7 at start → [7,1,2,3,4,5,6]
// 2nd rotation:
// Save last=6
// Shift → [7,7,1,2,3,4,5]
// Put 6 at start → [6,7,1,2,3,4,5]
// 3rd rotation:
// Save last=5
// Shift → [6,6,7,1,2,3,4]
// Put 5 at start → [5,6,7,1,2,3,4] ✅
// Final Answer: [5,6,7,1,2,3,4]
//     }
// };

// OPTIMAL SOLUTION
class Solution
{
public:
    void reverseArray(vector<int> &nums, int left, int right)
    {
        while (left < right)
        {
            swap(nums[left], nums[right]);
            left++;
            right--;
        }
    }

    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n; // handle k > n

        // ===== Solution 1: Reversal method =====
        reverseArray(nums, 0, n - 1); // reverse entire array
        reverseArray(nums, 0, k - 1); // reverse first k elements
        reverseArray(nums, k, n - 1); // reverse remaining elements

        // ===== Solution 2: Extra array method =====
        vector<int> temp(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            temp[(i + k) % nums.size()] = nums[i];
        }
        nums = temp;
    }
};

// Quetion 2
// Given an array nums, return true if the array was originally sorted
// in non-decreasing order, then rotated some number of positions
// (including zero). Otherwise, return false.

// Brute Force

// optimal UGameplayStatics::PlaySoundAtLocation(GetWorld(), class Solution {
public:
bool check(vector<int> &nums)
{
    int n = nums.size();
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            count++;
        }
    }
    if (nums[n - 1] > nums[0])
    {
        count++;
    }
    return count <= 1;
}
}
;, Location, Rotation, VolumeMultiplier, PitchMultiplier, StartTime, Attenuation, Concurrency, Owner);