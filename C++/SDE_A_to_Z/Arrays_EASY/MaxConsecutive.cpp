class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int count = 0;
        int maxi = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                count++; // increase streak
                maxi = max(maxi, count);
            }
            else
            {
                count = 0; // reset streak
            }
        }

        return maxi;
    }
};
