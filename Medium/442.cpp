// 442. Find All Duplicates in an Array

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> duplicates;

        for (int i = 0; i < nums.size(); i++)
        {
            int index = abs(nums[i]) - 1; // Convert to zero-based index

            if (nums[index] < 0)
            {
                // If already negative, it's a duplicate
                duplicates.push_back(abs(nums[i]));
            }
            else
            {
                // Mark as visited by negating the value
                nums[index] = -nums[index];
            }
        }

        return duplicates;
    }
};
