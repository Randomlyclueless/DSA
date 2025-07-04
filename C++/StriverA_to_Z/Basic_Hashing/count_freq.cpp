#include <iostream>

#include <unordered_map>
using namespace std;
void frq(int arr[], int n)
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[arr[i]]++;
    }
    for (auto x : map)
    {
        cout << x.first << " " << x.second << endl;
    }
}

int main()
{
    int arr[] = {10, 20, 20, 10, 10, 20, 5, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    frq(arr, n);
}