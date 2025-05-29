// You are given an array ‘ARR’ of size ‘N’ containing each number between 1 and ‘N’ - 1 at least once.
// There is a single integer value that is present in the array twice. Your task is to find the duplicate integer
// value present in the array.

// For example:

// Consider ARR = [1, 2, 3, 4, 4], the duplicate integer value present in the array is 4. Hence, the
// answer is 4 in this case.

// in above question we can use floyds algorithm to find the unique number in O(n) time and O(1) space complexitybecause
// there is only one value which is duplicate

int findDuplicate(vector<int> &arr)
{
    int fast = arr[0];
    int slow = arr[0];

    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    slow = arr[0];

    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }
    return slow;
}

// or

int findDuplicate(vector<int> &arr)
{
    int xor1 = 0;
    int xor2 = 0;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        xor2 ^= arr[i];
    }
    for (int i = 1; i <= n - 1; i++)
    {
        xor1 ^= i;
    }
    return xor1 ^ xor2;
}
