#include <iostream>
using namespace std;

bool linearSearch(int arr[], int x)
{
    for (int i = 0; i < 5; i++)
    {
        if (arr[i] == x)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int arr[5];
    cout << "Enter 5 elements: ";
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i];
    }

    int x;
    cout << "Enter the element you want to search: ";
    cin >> x;

    if (linearSearch(arr, x))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}
