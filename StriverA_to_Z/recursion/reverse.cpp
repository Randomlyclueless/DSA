#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    cout << "Reversed array : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void reverse(int arr[], int n)
{
    int p1 = 0;
    int p2 = n - 1;
    while (p1 < p2)
    {
        swap(arr[p1], arr[p2]);
        p1++;
        p2--;
    }
    print(arr, n);
}

int main()
{
    int n = 5;
    int arr[] = {5, 4, 3, 2, 1};
    reverse(arr, n);
}