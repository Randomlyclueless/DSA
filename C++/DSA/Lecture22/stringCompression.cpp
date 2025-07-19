class Solution
{
public:
    int compress(vector<char> &chars)
    {
        int i = 0;            // Pointer to iterate through the input array
        int ansindex = 0;     // Index where we'll write the compressed result
        int n = chars.size(); // Length of the input array

        while (i < n)
        {
            int j = i + 1;

            // Move j forward to count how many times chars[i] repeats
            while (j < n && chars[i] == chars[j])
            {
                j++;
            }

            // Store the current character once in the compressed array
            chars[ansindex++] = chars[i];

            // Count of current character = j - i
            int count = j - i;

            // If count > 1, convert the count to string and add each digit
            if (count > 1)
            {
                string cnt = to_string(count); // e.g. 12 → "12"
                for (char ch : cnt)
                {
                    chars[ansindex++] = ch; // Add each digit of the count
                }
            }

            // Move to the next group of characters
            i = j;
        }

        // Return the length of the compressed string
        return ansindex;
    }
};
