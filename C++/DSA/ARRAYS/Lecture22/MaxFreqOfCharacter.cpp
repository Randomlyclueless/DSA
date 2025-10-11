

// TIME COMPLEXITY: O(n)

#include <iostream>
#include <string>
using namespace std;

char maxOccurringChar(string s)
{
    int freq[26] = {0}; // frequency array for a-z

    // Count frequency using simple for loop
    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i] - 'a']++;
    }

    // Find max frequency and corresponding character
    int maxFreq = 0;
    char result = 'a';

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > maxFreq)
        {
            maxFreq = freq[i];
            result = 'a' + i;
        }
        else if (freq[i] == maxFreq && ('a' + i) < result)
        {
            result = 'a' + i;
        }
    }

    return result;
}

int main()
{
    cout << maxOccurringChar("testsample") << endl; // Output: e
    cout << maxOccurringChar("output") << endl;     // Output: t
    return 0;
}
