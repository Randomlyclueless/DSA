#include <iostream>
#include <cmath>
using namespace std;

bool isPower(int n)
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

int main()
{
    bool res = isPower(52);
    cout << res;
}