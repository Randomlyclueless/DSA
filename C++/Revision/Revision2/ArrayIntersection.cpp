#include <iostream>
#include <vector>
using namespace std;

/*
    Function to find the intersection of two sorted arrays.
    It returns a vector containing the common elements, including duplicates
    (if an element appears twice in both arrays, it appears twice in the result).
*/
vector<int> arrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m) {
    int i = 0;  // Pointer for arr1
    int j = 0;  // Pointer for arr2
    vector<int> ans;  // To store the intersection result

    // Traverse both arrays while both pointers are within bounds
    while (i < n && j < m) {
        if (arr1[i] == arr2[j]) {
            // Case 1: Both elements are equal → part of intersection
            ans.push_back(arr1[i]);
            i++;
            j++;
        } else if (arr1[i] < arr2[j]) {
            // Case 2: arr1[i] is smaller → move i forward to catch up
            i++;
        } else {
            // Case 3: arr2[j] is smaller → move j forward to catch up
            j++;
        }
    }

    return ans;  // Return the result vector
}

int main() {
    // Input arrays (sorted in non-decreasing order)
    vector<int> arr1 = {1, 2, 2, 2, 3, 4};
    vector<int> arr2 = {2, 2, 3, 3};

    // Call the intersection function
    vector<int> result = arrayIntersection(arr1, arr1.size(), arr2, arr2.size());

    // Print the result
    cout << "Intersection: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
