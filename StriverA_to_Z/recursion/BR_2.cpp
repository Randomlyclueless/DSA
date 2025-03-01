#include <iostream>
using namespace std;
void print(int i, int n)
{
    if (i > n)
        return;
    cout << "Raj" << endl;
    print(i + 1, n);
}
int main()
{
    int n = 4;
    print(1, n);
    return 0;
}