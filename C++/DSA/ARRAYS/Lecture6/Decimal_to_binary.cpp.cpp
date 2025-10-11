#include <iostream>
using namespace std;
#include <math.h>

int main()
{

    int n;
    cout << "Enter n: " << endl;
    cin >> n;
    int ans = 0;
    int i = 0;

    // Not Optimal
    // while (n != 0)
    // {
    //     int digit = n % 2;
    //     ans = (digit * pow(10, i)) + ans;

    //     n = n >> 1;
    //     i++;
    // }
    // cout << "Answer : " << ans << endl;

    int binarynum[32];
    while (n > 0)
    {
        binarynum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        cout << binarynum[j];
    }
}
