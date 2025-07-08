// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int calculateSetbits(int32_t n)
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
    int32_t num = 5;
    int result = calculateSetbits(num);
    cout << "Number of set bits in " << num << " is: " << result << endl;
}