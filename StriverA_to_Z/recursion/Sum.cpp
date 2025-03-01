#include <iostream>
using namespace std;
void print(int n)
{
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += i;
    }
    cout << "Sum is : " << sum << endl;
}

int main()
{
    print(5);
}