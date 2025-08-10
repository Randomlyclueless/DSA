class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        unordered_map<int, int> freqmap;

        // Count frequencies
        for (int i = 0; i < n; i++)
        {
            freqmap[nums[i]]++;
        }

        // Store all elements with count > n/3
        vector<int> result;
        unordered_map<int, int>::iterator it;
        for (it = freqmap.begin(); it != freqmap.end(); it++)
        {
            if (it->second > n / 3)
            {
                result.push_back(it->first);
            }
        }

        return result; // Return vector of majority elements
    }
};
