#include <bits/stdc++.h>
using namespace std;
const int MOD = 998244353;

long long modPow(long long a, long long b)
{
    long long res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
long long modInv(long long a)
{
    return modPow(a, MOD - 2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    long long half = modInv(2); // 499122177

    while (T--)
    {
        int N;
        cin >> N;
        vector<int> A(N);
        bool allOnes = true;
        for (int i = 0; i < N; i++)
        {
            cin >> A[i];
            if (A[i] != 1)
                allOnes = false;
        }

        if (allOnes)
        {
            // If all piles are 1, game is deterministic
            if (N % 2 == 1)
                cout << 1 << "\n"; // Alice wins
            else
                cout << 0 << "\n"; // Alice loses
        }
        else
        {
            // Otherwise, probability = 1/2
            cout << half << "\n";
        }
    }

    return 0;
}
