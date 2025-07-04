#include <iostream>
using namespace std;

int main()
{
    int n[5];
    cout << "Enter the Array Elements: " << endl;
    for (int i = 0; i < 5; i++)
    {
        cin >> n[i];
    }

    int x;
    cout << "Enter the value of X: " << endl;
    cin >> x;

    bool found = false;
    for (int i = 0; i < 5; i++)
    {
        if (n[i] == x)
        {
            found = true;
            break;
        }
    }

    if (found)
    {
        cout << "Yes, the element X exists in the array!" << endl;
    }
    else
    {
        cout << "No, the element X doesn't exist in the array." << endl;
    }

    return 0;
}
