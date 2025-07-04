

// BRUTE FORCE APPROACH
// Time Complexity: O(n^2)

// int maxProfit(vector<int> &arr) {
//     int maxPro = 0;
//     int n = arr.size();

//     for (int i = 0; i < n; i++) {
//         for (int j = i + 1; j < n; j++) {
//             if (arr[j] > arr[i]) {
//             maxPro = max(arr[j] - arr[i], maxPro);
//             }
//         }
//         }

//     return maxPro;
// }

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int maxProfit = 0;
        int mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            mini = min(mini, prices[i]);
            maxProfit = max(maxProfit, prices[i] - mini);
        }
        return maxProfit;
    }
};