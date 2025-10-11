class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();

        int count = 0;
        int total = row * col;

        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row - 1;
        int endingCol = col - 1;

        while (count < total) {
            // Traverse Top Row (left to right)
            for (int index = startingCol; index <= endingCol && count < total; index++) {
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;

            // Traverse Right Column (top to bottom)
            for (int index = startingRow; index <= endingRow && count < total; index++) {
                ans.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;

            // Traverse Bottom Row (right to left)
            for (int index = endingCol; index >= startingCol && count < total; index--) {
                ans.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow--;

            // Traverse Left Column (bottom to top)
            for (int index = endingRow; index >= startingRow && count < total; index--) {
                ans.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol++;
        }

        return ans;
    }
};
