#include <iostream>
using namespace std;

int bitcalculation(int n)
{
    int count = 0;
    while (n != 0)
    {
        if (n & 1)
        {
            count++;
        }
        n = n >> 1;
    }
    return count;
}
int main()
{
    int result = bitcalculation(5);
    cout << result;
}
