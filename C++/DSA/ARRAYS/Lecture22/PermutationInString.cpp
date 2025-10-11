class Solution
{
public:
    // This helper function checks if two character frequency arrays are equal
    bool checkEqual(int a[26], int b[26])
    {
        for (int i = 0; i < 26; i++)
        {
            if (a[i] != b[i])
                return false; // If any letter count doesn't match, not equal
        }
        return true; // All counts match — it’s a permutation
    }

    bool checkInclusion(string s1, string s2)
    {
        // Base case: If s1 is longer, it can't be inside s2
        if (s1.length() > s2.length())
            return false;

        // Frequency array for s1
        int count[26] = {0};
        // Frequency array for the current window in s2
        int count2[26] = {0};

        // Fill in the counts for s1 and the first window of s2
        for (int i = 0; i < s1.length(); i++)
        {
            count[s1[i] - 'a']++;  // Count letters in s1
            count2[s2[i] - 'a']++; // Count letters in the first window of s2
        }

        // Check if first window itself is a permutation
        if (checkEqual(count, count2))
            return true;

        // Start sliding the window on s2
        int windowSize = s1.length();
        for (int i = windowSize; i < s2.length(); i++)
        {
            // Add the new character coming into the window
            count2[s2[i] - 'a']++;

            // Remove the character going out of the window
            count2[s2[i - windowSize] - 'a']--;

            // After update, check if the current window matches s1's count
            if (checkEqual(count, count2))
                return true;
        }

        // If no matching window was found, return false
        return false;
    }
};
