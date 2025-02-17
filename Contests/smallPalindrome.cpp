#include <bits/stdc++.h>
using namespace std;

void smallest_palindrome(int x, int y)
{

    std::vector<int> ans = {};
    for (int i = 0; i < x; i++)
    {
        ans.push_back(1);
    }

    for (int i = 0; i < y; i++)
    {
        ans.push_back(2);
    }
    int ptrX = x / 2;
    int ptrY = x;
    for (int i = 0; i < y; i++)
    {
        std::swap(ans[ptrX], ans[ptrY]);
        ptrX++;
        ptrY++;
    }

    for (auto it : ans)
        cout << it << " ";
    cout << endl;
}

int main()
{
    smallest_palindrome(4, 4);
}