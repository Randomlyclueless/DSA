// 231. Power of Two so what they ask is to return true if a number is power/multiple of 2 or not
// 2^10 = 1024
// (2^31 )- 1 = 2^31 = 2^(10+10+1)
// => 2^10 x 2^10 x 2^11

// so if we find numbers from 2^0 to 2^31 and then compare input number we can clearly give output tru or false by doing a basic comparison
// 1. 0 - 30 tak loop chalana hai
// 2. 2^i ko calculate karna hai
// 3. 2^i ko compare krna hai
#include <iostream>
#include <math.h>
class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        for (int i = 0; i <= 30; i++)
        {
            int ans = pow(2, i);
            if (ans == n)
            {
                return true;
            }
        }
        return false;
    }
};