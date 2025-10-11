#include <bits/stdc++.h>
using namespace std;

// Copy your functions here
vector<int> reverse(vector<int> v)
{
    int s = 0;
    int e = v.size() - 1;
    while (s < e)
    {
        swap(v[s++], v[e--]);
    }
    return v;
}

vector<int> findArraySum(vector<int> &a, int n, vector<int> &b, int m)
{
    vector<int> ans;
    int i = n - 1;
    int j = m - 1;
    int carry = 0;
    while (i >= 0 && j >= 0)
    {
        int val1 = a[i];
        int val2 = b[j];
        int sum = val1 + val2 + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
        j--;
    }
    while (i >= 0)
    {
        int sum = a[i] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        i--;
    }
    while (j >= 0)
    {
        int sum = b[j] + carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
        j--;
    }
    while (carry != 0)
    {
        int sum = carry;
        carry = sum / 10;
        sum = sum % 10;
        ans.push_back(sum);
    }

    return reverse(ans);
}

int main()
{
    vector<int> a, b;
    int n, m;

    cout << "Enter the number of digits in the first number: ";
    cin >> n;
    cout << "Enter the digits of the first number: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a.push_back(x);
    }

    cout << "Enter the number of digits in the second number: ";
    cin >> m;
    cout << "Enter the digits of the second number: ";
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        b.push_back(x);
    }

    vector<int> result = findArraySum(a, n, b, m);

    cout << "Sum: ";
    for (int digit : result)
    {
        cout << digit;
    }
    cout << endl;

    return 0;
}
