// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;
vector<int> functionIntersection(vector<int> arr1, vector<int> arr2)
{
    int m = arr2.size();
    int n = arr1.size();
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return ans;
}
int main()
{
    vector<int> arr1 = {2, 2, 3, 3, 4, 5};

    vector<int> arr2 = {2, 3, 3, 6};

    vector<int> result = functionIntersection(arr1, arr2);
    for (auto x : result)
    {
        cout << x << " ";
    }
}