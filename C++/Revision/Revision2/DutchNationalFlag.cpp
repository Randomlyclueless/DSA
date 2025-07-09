#include <iostream>
#include <vector>
#include <algorithm> // for swap

using namespace std;
// Time complexity is O(n)
vector<int> dutchNationalFlag(vector<int> arr)
{
    int start = 0;
    int curr = 0;
    int end = arr.size() - 1;

    while (curr <= end)
    {
        if (arr[curr] == 0)
        {
            swap(arr[start], arr[curr]);
            start++;
            curr++;
        }
        else if (arr[curr] == 1)
        {
            curr++;
        }
        else
        { // arr[curr] == 2
            swap(arr[curr], arr[end]);
            end--;
        }
    }
    return arr;
}

int main()
{
    vector<int> arr = {2, 0, 2, 1, 1, 0};

    vector<int> sortedArr = dutchNationalFlag(arr);

    cout << "Sorted Array: ";
    for (int num : sortedArr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
