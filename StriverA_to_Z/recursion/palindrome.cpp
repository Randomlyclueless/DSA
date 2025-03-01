#include <iostream>
using namespace std;
bool palindrome(string s)
{
    int left = 0;
    int right = s.length() - 1;
    while (left < right)
    {
        if (!isalnum(s[left]))
        {
            left++;
        }
        else if (!isalnum(s[right]))
        {
            right--;
        }
        else if (tolower(s[left]) != tolower(s[right]))
            return false;
        else
        {
            left++;
            right--;
        }
    }
    return true;
}
int main()
{

    string str = "ABCDCBA";
    bool ans = palindrome(str);

    if (ans == true)
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not Palindrome";
    }
    return 0;
}