#include <iostream>
using namespace std;

// Function to find the bitwise complement of a non-negative integer
int bitwiseComplement(int n)
{
    // Edge case: the complement of 0 is 1
    if (n == 0)
    {
        return 1;
    }

    int ans = 0; // Variable to store the final answer (complement)
    int fac = 1; // Fac keeps track of the current binary place value (1, 2, 4, 8, ...)

    // Process each bit of the number
    while (n != 0)
    {
        int bit = n % 2;  // Get the least significant bit (LSB)
        bit = 1 - bit;    // Flip the bit: 0 becomes 1, 1 becomes 0 (bitwise complement)
        ans += fac * bit; // Add the flipped bit to the answer using correct binary place
        fac *= 2;         // Move to the next binary place (multiply by 2)
        n /= 2;           // Remove the processed bit (right shift by dividing by 2)
    }

    return ans; // Return the final complemented number
}

int main()
{
    int n;
    // Take input from the user
    cout << "Enter a non-negative integer: ";
    cin >> n;

    // Call the complement function
    int result = bitwiseComplement(n);

    // Output the result
    cout << "Bitwise complement: " << result << endl;

    return 0;
}
