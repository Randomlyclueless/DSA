// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {10, 8, 4, 6, 7, 92, 45, 36, 12, 82};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (n < 2)
    {
        cout << "-1";
        return 0;
    }
    int s = INT_MAX;
    int ss = INT_MAX;
    int l = INT_MIN;
    int sl = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        int x = arr[i];
        if (x < s)
        {
            ss = s;
            s = x;
        }
        else if (x > s && x < ss)
        {
            ss = x;
        }
        if (x > l)
        {
            sl = l;
            l = x;
        }
        else if (x < l && x > sl)
        {
            sl = x;
        }
    }
    if (ss == INT_MAX)
        ss = -1;
    if (sl == INT_MIN)
        sl = -1;
    cout << "Second Smallest : " << ss << " " << "Second Largest : " << sl;
}