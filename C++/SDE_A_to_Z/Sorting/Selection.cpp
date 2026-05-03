vector<int> selectionSort(vector<int> &nums)
{
    int n = nums.size();

    for (int i = 0; i < n - 1; i++)
    {
        int mini = i;

        // find the minimum element in the unsorted part
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] < nums[mini])
            {
                mini = j;
            }
        }

        // swap the found minimum with nums[i]
        swap(nums[i], nums[mini]);
    }

    return nums; // return sorted vector
}