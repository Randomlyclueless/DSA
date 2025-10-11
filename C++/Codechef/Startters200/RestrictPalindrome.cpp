#include <bits/stdc++.h>
using namespace std;

string constructGoodString(int N)
{
    if (N == 2)
        return "aa";
    if (N == 4)
        return "abaa";

    string pattern = "abcde";
    string S;
    for (int i = 0; i < N; i++)
    {
        S += pattern[i % 5];
    }
    return S;
}

// Optional: Function to compute f(S) for debugging
int countPalindromes(const string &S)
{
    set<string> palindromes;
    int n = S.length();

    // Check all substrings
    for (int i = 0; i < n; i++)
    {
        for (int len = 1; i + len <= n; len++)
        {
            string substr = S.substr(i, len);
            // Check if substring is palindromic
            bool isPalindrome = true;
            for (int j = 0; j < len / 2; j++)
            {
                if (substr[j] != substr[len - 1 - j])
                {
                    isPalindrome = false;
                    break;
                }
            }
            if (isPalindrome)
            {
                palindromes.insert(substr);
            }
        }
    }
    return palindromes.size();
}

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
        string S = constructGoodString(N);
        // Debug: Verify f(S) <= 5
        // cerr << "N=" << N << ", S=" << S << ", f(S)=" << countPalindromes(S) << endl;
        cout << S << "\n";
    }

    cout.flush(); // Ensure output is flushed
    return 0;
}