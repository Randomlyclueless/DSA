// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

void function(int arr[], int x)
{
    int start = 0;
    int end = x - 1;
    while (start <= end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main()
{
    int n[5] = {3, 4, 5, 6, 7};
    cout << "Input array : " << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << n[i];
    }
    function(n, 5);
    cout << endl;
    cout << "Output array : " << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << n[i];
    }
}