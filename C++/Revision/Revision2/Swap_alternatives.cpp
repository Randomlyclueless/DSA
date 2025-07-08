// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

void function(int arr[], int x)
{
    for (int i = 0; i < x; i += 2)
    {
        //   the i+1 < size makes sure there exists an element because we are jumping kind of
        if ((i + 1) < x)
        {
            swap(arr[i], arr[i + 1]);
        }
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