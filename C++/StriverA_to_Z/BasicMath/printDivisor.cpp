#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm> // Required for sort()

using namespace std;

void printDivisors(int n)
{
    vector<int> ls;

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            ls.push_back(i);
            if (i != n / i)
            { // Avoid duplicate entries for perfect squares
                ls.push_back(n / i);
            }
        }
    }

    sort(ls.begin(), ls.end()); // Sort the divisors

    // Print all divisors
    for (auto it : ls)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    cout << "Divisors of " << num << " are: ";
    printDivisors(num);

    return 0;
}
