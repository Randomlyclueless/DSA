#include <iostream>
#include <vector>
using namespace std;
bool isPalindrome(vector<char> &s)
{
    int start = 0;
    int end = s.size() - 1;
    while (start < end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main()
{
    vector<char> palindrome = {'m', 'a', 'd', 'a', 'm'};
    if (isPalindrome(palindrome))
    {
        cout << "Yes string is palindrome!" << endl;
    }
    else
    {
        cout << "Nope bad luck not a palindrome!" << endl;
    }
}
