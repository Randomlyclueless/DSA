class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> arr(n + 1);
        for (int i = 0; i <= n; i++)
        {
            arr[i] = i;
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans ^= arr[i] ^ nums[i];
        }

        ans ^= arr[n]; // last element

        return ans;
    }
};
