#include <iostream>
using namespace std;
int main()
{
    int n;
    int sum = 0;
    cout << "Enter the number : " << endl;
    cin >> n;
    int p = 0;
    int q = 1;
    for (int i = 1; i <= n; i++)
    {
        cout << p << " ";
        sum = p + q;
        p = q;
        q = sum;
    }
}