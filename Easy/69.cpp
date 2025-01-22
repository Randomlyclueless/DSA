#include <iostream>
using namespace std;

class Solution
{
public:
    long long int bs(int n)
    {
        int start = 0;
        int end = n;
        int ans = -1;
        long long int mid = start + (end - start) / 2;
        while (start <= end)
        {
            long long int sq = mid * mid;
            if (sq == n)
            {
                return mid;
            }
            else if (sq < n)
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }
        return ans;
    }

    double moreP(int n, int p, int temp)
    {
        double factor = 1;
        double ans = temp;
        for (int i = 0; i < p; i++)
        {
            factor = factor / 10;
            for (double j = ans; j * j < n; j = j + factor)
            {
                ans = j;
            }
        }
        return ans;
    }

    double mySqrt(int x, int precision)
    {
        int temp = bs(x);                 // Integer part of the square root
        return moreP(x, precision, temp); // Adding precision
    }
};

int main()
{
    Solution sol;
    int n = 36;        // Input number
    int precision = 5; // Number of decimal places
    double result = sol.mySqrt(n, precision);
    cout << "Square root of " << n << " with precision " << precision << " is: " << result << endl;
    return 0;
}
