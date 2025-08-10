class Solution
{
public:
    double myPow(double x, int n)
    {
        if (n == 0)
            return 1.0;
        if (x == 0)
            return 0.0;

        // Handle x = -1 separately to avoid overflow issues
        if (x == -1 && n % 2 == 0)
            return 1;
        if (x == -1 && n % 2 != 0)
            return -1;

        long binform = n; // Use long to handle INT_MIN case
        if (binform < 0)
        {
            x = 1 / x;
            binform = -binform;
        }

        double ans = 1.0;
        while (binform > 0)
        {
            if (binform % 2 == 1)
            {
                ans *= x;
            }
            x *= x;
            binform /= 2;
        }

        return ans;
    }
};