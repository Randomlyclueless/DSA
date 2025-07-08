// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
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

// int function(int x){

// }

int main()
{
    int n = 456;
    int res = isPower(n);
    cout << "Result is : " << res << endl;
}