#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

bool hasUniqueFrequencies(int arr[], int n)
{
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
    {
        freq[arr[i]]++;
    }

    unordered_set<int> s;
    for (auto x : freq)
    {
        if (s.find(x.second) != s.end())
        {
            // Frequency already exists
            return false;
        }
        s.insert(x.second);
    }

    return true;
}

int main()
{
    int n[5] = {3, 3, 2, 2, 1}; // 3→2, 2→2, 1→1 → two numbers have same freq (2)
    bool result = hasUniqueFrequencies(n, 5);
    cout << "All frequencies are unique? " << (result ? "Yes" : "No") << endl;
}
