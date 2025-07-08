// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed
// 32-bit integer range [-231, 231 - 1], then return 0.

// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
using namespace std;
int reverse(int x)
{
    // Initialise answer with 0
    int ans = 0;
    int rem;
    while (x != 0)
    {
        // Retrive the last element

        rem = x % 10;
        if ((ans > INT_MAX / 10) || ans < INT_MIN / 10)
        {
            return 0;
        }
        // multiply bby 10 to get teh appropriate place
        ans = (ans * 10) + rem;
        // divide numver by 10
        x = x / 10;
    }
    return ans;
}

int main()
{
    int n = 456;
    int res = reverse(n);
    cout << "Result is : " << res << endl;
}