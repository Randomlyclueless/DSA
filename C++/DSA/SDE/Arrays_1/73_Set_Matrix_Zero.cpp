class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int n = matrix.size();    // number of rows
        int m = matrix[0].size(); // number of columns
        int col0 = 1;             // to track if first column needs to be zero

        // Step 1: mark rows and columns using first row and col
        for (int i = 0; i < n; i++)
        {
            if (matrix[i][0] == 0)
                col0 = 0; // track if col0 needs to be 0
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0; // mark row
                    matrix[0][j] = 0; // mark column
                }
            }
        }

        // Step 2: use markers to set cells to 0 (excluding first row/col)
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: update first row if needed
        if (matrix[0][0] == 0)
        {
            for (int j = 0; j < m; j++)
            {
                matrix[0][j] = 0;
            }
        }

        // Step 4: update first column if needed
        if (col0 == 0)
        {
            for (int i = 0; i < n; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
