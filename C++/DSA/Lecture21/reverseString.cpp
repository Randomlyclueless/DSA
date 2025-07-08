#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char> &s)
{
    int start = 0;
    int end = s.size() - 1;
    while (start < end)
    {
        swap(s[start++], s[end--]);
    }
}

int main()
{
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};
    reverseString(s);

    cout << "Reversed string: ";
    for (char c : s)
    {
        cout << c;
    }
    cout << endl;

    return 0;
}
