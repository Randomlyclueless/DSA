#include <bits/stdc++.h>
using namespace std;

int subarraysWithXorK(const vector<int> &a, int k)
{
    int n = a.size();
    // xr is the XOR of elements from index 0 to current index, initially 0
    int xr = 0;
    unordered_map<int, int> mpp; // stores frequency of prefix XORs

    // to handle subarrays starting from index 0
    mpp[0] = 1;

    int count = 0;

    for (int i = 0; i < n; i++)
    {
        // Update prefix XOR
        xr = xr ^ a[i];

        // Find the required prefix that would give XOR = k
        int x = xr ^ k;

        // Count previous occurrences of that required prefix
        if (mpp.find(x) != mpp.end())
        {
            count += mpp[x];
        }

        // Store/Update current prefix XOR in map
        mpp[xr]++;
    }
    return count;
}

int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    cout << "The number of subarrays with XOR k is: "
         << subarraysWithXorK(a, k) << "\n";
    return 0;
}
