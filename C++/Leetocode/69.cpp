class Solution
{
public:
    long long int mySqrt(int x)
    {
        long long s = 0;
        long long e = x;
        long long ans = -1;

        while (s <= e)
        {
            long long mid = s + (e - s) / 2;
            long long square = mid * mid;

            if (square == x)
            {
                return mid;
            }
            else if (square < x)
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }

        return ans;
    }
};
