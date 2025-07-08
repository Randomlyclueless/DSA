#include <iostream>
using namespace std;

int bitcompliment(int n)
{
    if (n == 0)
    {
        return 0;
    }
    int ans = 0, fac = 1;
    while (n != 0)
    {
        int bit = n % 2;
        bit = 1 - bit;
        ans += fac * bit;
        fac *= 2;
        n = n / 2;
    }
    return ans;
}

int main()
{
    int result = bitcompliment(2);
    cout << result;
}