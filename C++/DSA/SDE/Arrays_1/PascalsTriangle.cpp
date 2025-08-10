class Solution
{
public:
    // Helper to generate a single row using nCr logic
    vector<int> getRow(int row)
    {
        long long ans = 1;
        vector<int> ansR;
        ansR.push_back(1);
        for (int col = 1; col < row; col++)
        {
            ans = ans * (row - col);
            ans = ans / col;
            ansR.push_back(ans);
        }
        return ansR;
    }

    // Generate Pascal's Triangle
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        for (int i = 1; i <= numRows; i++)
        {
            ans.push_back(getRow(i));
        }
        return ans;
    }
};

