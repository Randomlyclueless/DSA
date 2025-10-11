#include <iostream>
using namespace std;

void printRowsum(int arr[][3], int row, int col)
{
    for (int r = 0; r < row; r++)
    {
        int sum = 0;
        for (int c = 0; c < col; c++)
        {
            sum += arr[r][c];
        }
        cout << "Sum of row " << r << " = " << sum << endl;
    }
}
int printColsum2(int arr[][3], int row, int col)
{
    for (int c = 0; c < col; c++)
    {
        int sum = 0;
        for (int r = 0; r < row; r++)
        {
            sum += arr[r][c];
        }
        cout << "Sum of col is " << c << " = " << sum << endl;
        // cout<<"Sum of Column"<<c<<" = "<<
    }
}

int largestRowSum(int arr[][3], int row, int col)
{
    int maxi = INT_MIN;
    int rowindex = -1;
    for (int r = 0; r < row; r++)
    {
        int sum = 0;
        for (int c = 0; c < col; c++)
        {
            sum += arr[r][c];
        }
        if (sum > maxi)
        {
            maxi = sum;
            rowindex = r;
        }
    }
    cout << "Largest Row Sum : " << maxi;
    return rowindex;
}