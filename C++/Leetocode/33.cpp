class Solution
{
public:
    int binarysearch(int s, int e, vector<int> &nums, int target)
    {
        int ans = -1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (nums[mid] == target)
            {
                ans = mid;
                return mid;
            }
            else if (target > nums[mid])
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return -1;
    }
    int search(vector<int> &nums, int target)
    {
        int s = 0;
        int e = nums.size() - 1;

        while (s < e)
        {
            int mid = s + (e - s) / 2;
            if (nums[mid] >= nums[0])
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
        }
        int pivot = s;
        if (nums[pivot] <= target && target <= nums[nums.size() - 1])
        {
            return binarysearch(pivot, nums.size() - 1, nums, target);
        }
        else
        {
            return binarysearch(0, pivot - 1, nums, target);
        }
    }
};