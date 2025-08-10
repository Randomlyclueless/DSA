class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size(); // Correct way for vector
        unordered_map<int, int> freqmap;

        // Count frequencies
        for (int i = 0; i < n; i++)
        {
            freqmap[nums[i]]++;
        }

        // Find majority element
        unordered_map<int, int>::iterator it;
        for (it = freqmap.begin(); it != freqmap.end(); it++)
        {
            if (it->second > n / 2)
            {
                return it->first; // Return majority element
            }
        }

        return -1; // If no majority element (optional)
    }
};
