#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
        }

        // DP array: dp[i][0] for even, dp[i][1] for odd
        vector<vector<int>> dp(N, vector<int>(2, 0));

        // Initialize for first element
        dp[0][A[0] % 2] = 1;

        // Fill DP table
        for (int i = 1; i < N; i++)
        {
            int parity = A[i] % 2;
            if (parity == 0)
            { // Current element is even
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + 1);
                dp[i][1] = dp[i - 1][1];
            }
            else
            { // Current element is odd
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + 1);
                dp[i][0] = dp[i - 1][0];
            }
        }

        // Output the maximum length
        cout << max(dp[N - 1][0], dp[N - 1][1]) << "\n";
    }

    return 0;
}