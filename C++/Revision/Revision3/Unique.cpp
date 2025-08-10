// find element present only once (2,2,3,3,1)
// int findUnique1(int n, int arr[])
// {
//     int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         ans = ans ^ arr[i];
//     }
//     return ans;
// }

// int main()
// {
//     int arr[5] = {2, 2, 3, 3, 1};
//     int n = 5;
//     int ans = findUnique(n, arr); // Pass full array length

//     cout << ans;
//     return 0;
// }

// check if every element frequency is unique
bool uniqueOccurrences(vector<int> &arr)
{
    unordered_map<int, int> freq;
    for (auto x : arr)
    {
        freq[x]++;
    }
    unordered_set<int> uniquefreq;
    for (auto x : freq)
    {
        if (uniquefreq.count(x.second))
        {
            return false; // Duplicate frequency found
        }
        uniquefreq.insert(x.second);
    }
    return true; // All frequencies are unique
}

int main()
{
    vector<int> arr = {1, 2, 2, 1, 1, 3}; // freq: 1→3, 2→2, 3→1
    bool result = uniqueOccurrences(arr);

    if (result)
    {
        cout << "True: All element frequencies are unique." << endl;
    }
    else
    {
        cout << "False: There are repeated frequencies." << endl;
    }

    return 0;
}
