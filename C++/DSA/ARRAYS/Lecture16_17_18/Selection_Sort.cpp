// Online C++ compiler to run C++ program online
#include <iostream>
// #include<math>
using namespace std;

void selectionsort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int smallindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[smallindex])
            {
                smallindex = j;
            }
        }
        swap(arr[i], arr[smallindex]);
    }
}
void printarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
}
int main()
{
    int arr[] = {4, 1, 5, 2, 3};
    int n = 5;
    selectionsort(arr, n);
    printarray(arr, n);
}