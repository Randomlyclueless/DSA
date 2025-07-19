// remove all adjacent duplicates from a string

class Solution
{
public:
    string removeDuplicates(string s)
    {
        int i = 0; // write pointer
        for (int j = 0; j < s.length(); ++j)
        {
            s[i] = s[j]; // move current char to position i

            // If i > 0 and current char equals the one before it → duplicate!
            if (i > 0 && s[i] == s[i - 1])
            {
                i -= 2; // remove both duplicates
            }

            i++; // move write pointer forward
        }

        return s.substr(0, i); // return only the cleaned-up part
    }
};