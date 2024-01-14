#include <bits/stdc++.h>
using namespace std;
int main()
{
    // input output for files
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);

    // start code here
    string s = ")w(m)(r(";
    stack<int> opIdx;
    stack<int> clIdx;

    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(')
        {
            opIdx.push(i);
        }
        else if (s[i] == ')')
        {
            clIdx.push(i);
        }
    }

    // remove the extra brackets
    if(opIdx.size() < clIdx.size())
    {
        while (opIdx.size() < clIdx.size())
        {
            s.erase(s.begin() + clIdx.top());
            clIdx.pop();
        }
    }
    else if (opIdx.size() > clIdx.size())
    {
        while (opIdx.size() > clIdx.size())
        {
            s.erase(s.begin() + opIdx.top());
            opIdx.pop();
        }
    }

    // remove the brackets which are not in pair
    cout << s << endl;

    // print the indexes of opening and closing brackets
    // while (!opIdx.empty())
    // {
    //     cout << opIdx.top() << " ";
    //     opIdx.pop();
    // }
    // cout << endl;
    // while (!clIdx.empty())
    // {
    //     cout << clIdx.top() << " ";
    //     clIdx.pop();
    // }
    return 0;
}