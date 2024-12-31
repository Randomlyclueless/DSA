// // You are given an array / list ARR consisting of N integers.Your task is to find all the distinct triplets
// present in the array which adds up to a given number K.

// // An array is said to have a triplet{ARR[i], ARR[j], ARR[k]} with sum = 'K' if there exists three indices i,
// //                       j and k such that i != j, j != k and i != j and ARR[i] + ARR[j] + ARR[k] = 'K'.

#include <bits/stdc++.h>

// Function to find all unique triplets in the array that sum up to K
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{

    vector<vector<int>> ans; // To store the resulting triplets

    // Sort the array to enable the two-pointer technique
    sort(arr.begin(), arr.end());

    // Iterate through the array
    for (int i = 0; i < n; i++)
    {
        // Skip duplicate elements to avoid duplicate triplets
        if (i != 0 && arr[i] == arr[i - 1])
        {
            continue;
        }

        // Initialize two pointers
        int j = i + 1; // Pointer starting right after the current element
        int k = n - 1; // Pointer starting at the end of the array

        // Use the two-pointer technique to find pairs that sum with arr[i] to make K
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k]; // Calculate the sum of the triplet

            if (sum < K)
            {
                // If the sum is less than K, move the left pointer to increase the sum
                j++;
            }
            else if (sum > K)
            {
                // If the sum is greater than K, move the right pointer to decrease the sum
                k--;
            }
            else
            {
                // If the sum equals K, we found a valid triplet
                ans.push_back({arr[i], arr[j], arr[k]});

                // Move both pointers to look for the next potential triplet
                j++;
                k--;

                // Skip duplicate elements for the second pointer
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                // Skip duplicate elements for the third pointer
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
    }

    return ans; // Return the list of triplets
}
