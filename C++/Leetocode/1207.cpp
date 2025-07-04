// Given an array of integers arr, return true if the number of occurrences of each value
// in the array is unique or false otherwise.
// Input : arr = [ 1, 2, 2, 1, 1, 3 ] Output : true Explanation : The value 1 has 3 occurrences, 2 has 2 and 3 has 1.
// No two values have the same number of occurrences.
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Function to check if all element frequencies in the array are unique
bool uniqueOccurrences(vector<int> &arr)
{
    // Step 1: Count frequency of each element using an unordered_map
    unordered_map<int, int> freq;
    for (auto x : arr)
    {
        freq[x]++; // Increment frequency of element x
    }

    // Step 2: Store frequencies in a set to check uniqueness
    unordered_set<int> uniqueFreq;
    for (auto x : freq)
    {
        uniqueFreq.insert(x.second); // Insert frequency into the set
    }

    // Step 3: If size of set == size of map, all frequencies are unique
    return freq.size() == uniqueFreq.size();
}

int main()
{
    // Example input
    vector<int> arr = {1, 2, 2, 1, 1, 3};

    // Call the function and print result
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
