void reverseString(vector<char> &s)
{
    int start = 0;
    int end = s.size() - 1;
    while (start < end)
    {
        swap(s[start++], s[end--]);
    }
}

// leetcode
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    char tolower(char c)
    {
        if (c >= 'A' && c <= 'Z')
        {
            return c + 32;
        }
        return c;
    }
    bool isPalindrome(string s)
    {
        string cleaned = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (isalnum(s[i]))
            {
                cleaned += tolower(s[i]);
            }
        }
        int start = 0;
        int end = cleaned.length() - 1;
        while (start < end)
        {
            if (cleaned[start] != cleaned[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};
// MAXIMUM OCCURRING CHARACTER IN A STRING
// Brute Force Approach
char getMaxOccuringChar(string s)
{ // parameter name is 's'
    int maxcnt = 0;
    char result = 'a';
    int n = s.length(); // use 's', not 'str'

    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (s[i] == s[j])
            {
                count++;
            }
        }
        if (count > maxcnt || (count == maxcnt && s[i] < result))
        {
            maxcnt = count;
            result = s[i];
        }
    }
    return result;
}
// Optimal Approach
char getMaxOccuringChar(string s)
{
    // Step 1: Create a hashmap to store frequency of each character
    unordered_map<char, int> freq;

    // Step 2: Count frequency of each character in the string
    for (char c : s)
    {
        freq[c]++;
    }

    // Step 3: Initialize variables for maximum frequency and result character
    int maxFreq = 0;
    char result = char(127); // Initialize to a character larger than all printable chars

    // Step 4: Traverse the hashmap to find character with maximum frequency
    for (auto &p : freq)
    {
        char currentChar = p.first;
        int currentFreq = p.second;

        // Update result if:
        // 1. Current frequency is greater than maxFreq
        // 2. Current frequency is equal to maxFreq but character is lexicographically smaller
        if (currentFreq > maxFreq || (currentFreq == maxFreq && currentChar < result))
        {
            maxFreq = currentFreq;
            result = currentChar;
        }
    }

    return result;
}

// REPLACE SPACES BY @40
string replaceSpaces(string &str)
{

    // BRUTE FORCE APPROACH

    // string result = "";
    // for(char c: str){
    //     if(c == ' '){
    //         result+="@40";
    //     }else{
    //         result+=c;
    //     }
    // }
    // return result;

    // OPTIMAL APPROACH

    stringstream ss;
    for (char c : str)
    {
        if (c == ' ')
        {
            ss << "@40";
        }
        else
        {
            ss << c;
        }
    }
    return ss.str();
}
// STRING COMPRESSION very important
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

// REKOVE DUPLICATE ADJACENT CHARACTERS
string removeDuplicates(string s)
{
    int i = 0;
    for (int j = 0; j < s.length(); ++j)
    {
        s[i] = s[j];
        if (i > 0 && s[i] == s[i - 1])
        {
            // if duplicate found then reset the index of i bby eliminating 2 members
            i -= 2;
        }
        i++;
    }
    return s.substr(0, i);
}