

#include <bits/stdc++.h>

void sort012(int *arr, int n)

{

    //   Write your code here

    int temp1, temp2;

    for (int i = 0; i < n - 1; i++)

    {

        if (arr[i] > arr[i + 1])

        {

            temp1 = arr[i];

            arr[i] = arr[i + 1];

            arr[i + 1] = temp1;
        }

        while (i > 0 && arr[i] < arr[i - 1])

        {

            temp2 = arr[i];

            arr[i] = arr[i - 1];

            arr[i - 1] = temp2;

            i--;
        }
    }
}