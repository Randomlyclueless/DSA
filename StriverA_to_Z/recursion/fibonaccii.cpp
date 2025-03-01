#include <iostream>
using namespace std;
int fibonaccii(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int last = fibonaccii(n - 1);
    int slast = fibonaccii(n - 2);
    return last + slast;
}

int main()
{

    // Here, let’s take the value of N to be 4.
    int N = 4;
    cout << fibonaccii(N) << endl;
    return 0;
}