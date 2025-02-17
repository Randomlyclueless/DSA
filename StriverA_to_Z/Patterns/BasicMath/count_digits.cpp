#include <iostream>
using namespace std;
#include <cmath>
#include <algorithm>

int countdigits(int n)
{
    int cnt = (int)(log10(n) + 1);
    return cnt;
}
int main()
{
    int n = 12345;
    countdigits(n);
    cout << countdigits(n) << endl;
}