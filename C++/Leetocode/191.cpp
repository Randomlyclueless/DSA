#include <iostream>
using namespace std;

// Define a class named Solution
class Solution
{
public:
    // Function to count the number of 1 bits (also known as Hamming Weight)
    int hammingWeight(int n)
    {
        int count = 0; // Initialize counter for 1s

        // Loop runs until all bits are shifted out
        while (n != 0)
        {
            // Bitwise AND of n and 1 checks if the least significant bit is 1
            if (n & 1)
            {
                count++; // If it is 1, increment the count
            }

            // Right shift n by 1 to check the next bit
            n = n >> 1;
        }

        // Return the final count of 1s
        return count;
    }
};

int main()
{
    Solution solution;

    int n;
    // Ask user to enter an integer (can be any 32-bit number)
    cout << "Enter an integer (signed 32-bit): ";
    cin >> n;

    // Call the hammingWeight function with input and store the result
    int result = solution.hammingWeight(n);

    // Print the number of 1s in the binary representation of the number
    cout << "Number of 1 bits (Hamming Weight): " << result << endl;

    return 0;
}
