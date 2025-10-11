// Online C++ compiler to run C++ program online
#include <iostream>
#include <climits>
using namespace std;

void printsum(int arr[][3], int row, int col)
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
    cout << "Largest Row sum : " << maxi;
    return rowindex;
}

int main()
{
    // Sample 2D array with 3 rows and 3 columns
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    // Call the function with proper arguments
    printsum(arr, 3, 3);
    largestRowSum(arr, 3, 3);
    return 0;
}
