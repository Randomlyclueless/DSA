vector<vector<int>> Function2(vector<int> arr, int n, int target) {
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; i++) {
        // Skip duplicates for i
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        int j = i + 1;
        int k = n - 1;

        while (j < k) {
            int sum = arr[i] + arr[j] + arr[k];

            if (sum < target) {
                j++;
            } else if (sum > target) {
                k--;
            } else {
                ans.push_back({arr[i], arr[j], arr[k]});
                j++;
                k--;

                // Skip duplicates for j
                while (j < k && arr[j] == arr[j - 1]) j++;
                // Skip duplicates for k
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }

    return ans;
}
