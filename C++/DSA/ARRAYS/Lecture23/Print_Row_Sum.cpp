// Online C++ compiler to run C++ program online
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
int main()
{
    // Sample 2D array with 3 rows and 3 columns
    int arr[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    // Call the function with proper arguments
    printsum(arr, 3, 3);
    printsum2(arr, 3, 3);

    return 0;
}
