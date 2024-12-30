// 1207. Unique Number of Occurrences
#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> freq;

        for (auto x : arr)
        {
            freq[x]++;
        }
        unordered_set<int> s;
        for (auto x : freq)
        {
            s.insert(x.second);
        }
        return freq.size() == s.size();
    }
};