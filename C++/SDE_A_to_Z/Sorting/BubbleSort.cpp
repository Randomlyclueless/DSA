class Solution
{
public:
    vector<int> bubbleSort(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++)
        {
            bool swapped = false;

            for (int j = 0; j < n - i - 1; j++)
            {

                // ascending order
                if (nums[j] > nums[j + 1])
                {
                    swap(nums[j], nums[j + 1]);
                    swapped = true;
                }
            }

            // no swaps = already sorted
            if (!swapped)
                break;
        }

        return nums;
    }
};
