#include <bits/stdc++.h>
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    for (int col = 0; col < mCols; col++)
    {
        if (col & 1)
        {
            for (int r = nRows - 1; r >= 0; r--)
            {
                ans.push_back(arr[r][col]);
            }
        }
        else
        {
            for (int r = 0; r < nRows; r++)
            {

                ans.push_back(arr[r][col]);
            }
        }
    }
    return ans;
}