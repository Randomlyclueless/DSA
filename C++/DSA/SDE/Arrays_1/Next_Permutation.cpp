class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int pivot = -1, n = nums.size();

        // Step 1: Find pivot (first decreasing number from right)
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] < nums[i + 1])
            {
                pivot = i;
                break;
            }
        }

        // Step 2: If no pivot found, reverse whole array
        if (pivot == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 3: Find rightmost element greater than nums[pivot] and swap
        for (int i = n - 1; i > pivot; i--)
        {
            if (nums[i] > nums[pivot])
            {
                swap(nums[i], nums[pivot]);
                break;
            }
        }

        // Step 4: Reverse the suffix after pivot
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};
