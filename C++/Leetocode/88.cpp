#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void mergecode(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }

        while (j >= 0)
        {
            nums1[k--] = nums2[j--]; // ✅ Fixed here
        }
    }

    void printans(vector<int> &nums, int n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << nums[i] << " ";
        }
        cout << endl;
    }

    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        mergecode(nums1, m, nums2, n);
        printans(nums1, m + n); // ✅ Fixed here
    }
};
int main()
{
    Solution sol;

    vector<int> nums1 = {1, 2, 3, 0, 0, 0}; // nums1 has extra space for nums2
    vector<int> nums2 = {2, 5, 6};
    int m = 3; // number of initialized elements in nums1
    int n = 3; // number of elements in nums2

    sol.merge(nums1, m, nums2, n); // This will also print the merged array

    return 0;
}
