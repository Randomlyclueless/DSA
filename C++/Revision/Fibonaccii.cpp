#include <iostream>
using namespace std;

int fibonaccii(int n)
{
    int p = 0, q = 1;
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        cout << p;
        sum = p + q;
        p = q;
        q = sum;
    }
    return p;
}

int main()
{
    fibonaccii(5);
}