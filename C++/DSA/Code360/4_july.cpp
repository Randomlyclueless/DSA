// https://www.naukri.com/code360/problem-of-the-day/easy

#include <bits/stdc++.h>
int calculateScore(vector<string> &matchResult, int n)
{
    vector<int> x;
    for (int i = 0; i < n; i++)
    {
        string current = matchResult[i];
        if (current == "+")
        {

            int sum = x[x.size() - 1] + x[x.size() - 2];
            x.push_back(sum);
        }
        else if (current == "C")
        {
            x.pop_back();
        }
        else if (current == "D")
        {
            int dounlescore = 2 * x.back();
            x.push_back(dounlescore);
        }
        else
        {
            int num = stoi(current); // string to int
            x.push_back(num);
        }
    }
    int sum = 0;
    for (int i = 0; i < x.size(); i++)
    {
        sum += x[i];
    }
    return sum;
}

int main()
{
    vector<string> matchResult = {"5", "-2", "4", "C", "D", "9", "+", "+"};
    int n = matchResult.size();

    cout << "Final Score: " << calculateScore(matchResult, n) << endl;
    return 0;
}
