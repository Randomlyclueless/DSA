// this question wants us to find a simgle duplicate which exists

// tc = O(n)

#include <iostream>
#include <vector>
using namespace std;

int findUsingBitwise(vector<int> &arr)
{
    int xor1 = 0;
    int xor2 = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        xor2 ^= arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        xor1 ^= i;
    }

    return xor1 ^ xor2;
}

int floydDetection(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];

    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    slow = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}

int main()
{
    vector<int> arr = {1, 3, 4, 2, 5, 3}; // 3 is the duplicate

    int duplicate1 = findUsingBitwise(arr);
    int duplicate2 = floydDetection(arr);

    cout << "Duplicate (Bit Manipulation): " << duplicate1 << endl;
    cout << "Duplicate (Floyd's Algorithm): " << duplicate2 << endl;

    return 0;
}
