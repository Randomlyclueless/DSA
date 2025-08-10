class Solution
{
public:
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        if (n == 2)
            return true;
        if (n % 2 == 0)
            return false;
        for (int i = 3; i * i <= n; i += 2)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    long long tsum(vector<int> &x)
    {
        long long total = 0;
        for (int i = 0; i < x.size(); i++)
        {
            total += x[i];
        }
        return total;
    }

    long long checkprime(vector<int> &nums)
    {
        vector<int> A, B;
        for (int i = 0; i < nums.size(); i++)
        {
            if (isPrime(i))
            {
                A.push_back(nums[i]); // Prime index -> A
            }
            else
            {
                B.push_back(nums[i]); // Non-prime index -> B
            }
        }
        long long a = tsum(A);
        long long b = tsum(B);
        return abs(a - b); // Use long long to avoid overflow
    }

    long long splitArray(vector<int> &nums)
    {
        return checkprime(nums);
    }
};
©leetcode