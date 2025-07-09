#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
    Function to find all unique pairs in a sorted array that sum up to 's'.
    The result is returned as a vector of pairs (2-element vectors).
*/
vector<vector<int>> Function(vector<int> &arr, int s) {
    vector<vector<int>> ans;

    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] + arr[j] == s) {
                // Always store the smaller number first
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
            }
        }
    }

    // Sort the resulting list of pairs
    sort(ans.begin(), ans.end());

    return ans;
}

int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4};
    int s = 5;

    vector<vector<int>> result = Function(arr, s);

    cout << "Pairs with sum = " << s << ":\n";
    for (auto pair : result) {
        cout << pair[0] << ", " << pair[1] << endl;
    }

    return 0;
}
