// Online C++ compiler to run C++ program online
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void findLargest(vector<int> arr)
{
    sort(arr.begin(), arr.end());
    cout << arr[arr.size() - 2];
}

int main()
{
    vector<int> arr = {7, 5, 12, 6};
    findLargest(arr);

    return 0;
}