// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
using namespace std;

bool searchinmatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    if (row == 0)
        return false;
    int col = matrix[1].size();
    int start = 0;
    int end = row * col - 1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        int element = matrix[mid / col][mid % col];
        if (element == target)
        {
            return true;
        }
        if (element > target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return false;
}
int main()
{
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}};

    int target;
    cout << "Enter target: ";
    cin >> target;

    if (searchinmatrix(matrix, target))
    {
        cout << "Found!" << endl;
    }
    else
    {
        cout << "Not Found!" << endl;
    }

    return 0;
}
