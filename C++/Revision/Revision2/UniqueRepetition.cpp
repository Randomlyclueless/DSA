// in an  array every number is repeated uniquely find the number which is only one or has not been repeated

// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int function(int arr[], int x)
{
    int ans = 0;
    for (int i = 0; i < x; i++)
    {

        ans = ans ^ arr[i];
    }
    return ans;
}

int main()
{
    int n[5] = {3, 3, 2, 2, 1};

    cout << function(n, 5);
}