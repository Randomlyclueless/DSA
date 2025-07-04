#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void mergecode(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> nums3;
        int i = 0, j = 0;

        while (i < m && j < n)
        {
            if (nums1[i] < nums2[j])
            {
                nums3.push_back(nums1[i]);
                i++;
            }
            else
            {
                nums3.push_back(nums2[j]);
                j++;
            }
        }

        while (i < m)
        {
            nums3.push_back(nums1[i]);
            i++;
        }

        while (j < n)
        {
            nums3.push_back(nums2[j]);
            j++;
        }

        // Copy nums3 back to nums1
        for (int k = 0; k < m + n; k++)
        {
            nums1[k] = nums3[k];
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
        printans(nums1, m + n);
    }
};
int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    s.merge(nums1, m, nums2, n);
    return 0;
}
