class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        int sum = 0;
        int maxi = nums[0];
        for (int i = 0; i < n; i++)
        {
            // three consitions of Kadane's Algorithm
            // 1. Add current element to sum
            sum += nums[i];
            // 2. If sum is greater than maximum, update maximum
            maxi = max(maxi, sum);
            // 3. If sum is less than 0, reset it to 0
            if (sum < 0)
            {
                sum = 0;
            }
        }
        return maxi;
    }
};