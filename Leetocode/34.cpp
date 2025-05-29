
// First and last Occurance of an element in a sorted array
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        return {occurance(nums, target, true), occurance(nums, target, false)};
    }
    int occurance(vector<int> &nums, int target, bool findfirst)
    {
        int s = 0, e = nums.size() - 1, ans = -1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (target > nums[mid])
            {
                s = mid + 1;
            }
            else if (target < nums[mid])
            {
                e = mid - 1;
            }
            else
            {
                ans = mid;
                if (findfirst)
                    e = mid - 1;
                else
                    s = mid + 1;
            }
        }
        return ans;
    }
};